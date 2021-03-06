// Copyright (c) 2015 Nuxi, https://nuxi.nl/
//
// This file is distributed under a 2-clause BSD license.
// See the LICENSE file for details.

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <testing.h>
#include <unistd.h>

TEST(fclose, eagain) {
  // Create a stream to non-blocking write side of a pipe.
  int fds[2];
  ASSERT_EQ(0, pipe(fds));
  ASSERT_EQ(0, fcntl(fds[1], F_SETFL, fcntl(fds[1], F_GETFL) | O_NONBLOCK));
  FILE *fp = fdopen(fds[1], "w");

  // Write data into the pipe until it fails.
  flockfile(fp);
  while (putc_unlocked('a', fp) == 'a')
    ;
  funlockfile(fp);

  // Closing should try to flush the data again, but it will still fail
  // with EAGAIN.
  errno = 0;
  ASSERT_EQ(EOF, fclose(fp));
  ASSERT_EQ(EAGAIN, errno);
  ASSERT_EQ(0, close(fds[0]));
}

TEST_SEPARATE_PROCESS(fclose, ebadf) {
  // Create a stream to one end of a pipe.
  int fds[2];
  ASSERT_EQ(0, pipe(fds));
  FILE *fp = fdopen(fds[0], "r");
  ASSERT_NE(NULL, fp);

  // Close underlying file descriptors.
  ASSERT_EQ(0, close(fds[0]));
  ASSERT_EQ(0, close(fds[1]));

  // Closing should fail, as underlying file descriptor is already gone.
  ASSERT_EQ(EOF, fclose(fp));
  ASSERT_EQ(EBADF, errno);
}

TEST_SEPARATE_PROCESS(fclose, epipe) {
  // Create a pipe of which the read side is closed.
  int fds[2];
  ASSERT_EQ(0, pipe(fds));
  ASSERT_EQ(0, close(fds[0]));

  // Write data into write buffer.
  FILE *fp = fdopen(fds[1], "w");
  ASSERT_NE(NULL, fp);
  ASSERT_EQ('a', putc('a', fp));

  // Closing should be unable to flush.
  ASSERT_EQ(EOF, fclose(fp));
  ASSERT_EQ(EPIPE, errno);
}

TEST(fclose, success) {
  FILE *fp = tmpfile();
  ASSERT_NE(NULL, fp);
  ASSERT_EQ(0, fclose(fp));
}
