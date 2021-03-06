// Copyright (c) 2015 Nuxi, https://nuxi.nl/
//
// This file is distributed under a 2-clause BSD license.
// See the LICENSE file for details.

#include <errno.h>
#include <stdio.h>
#include <testing.h>
#include <unistd.h>

TEST(fileno, bad) {
  // Memory stream has no underlying file descriptor.
  FILE *fp = fmemopen(NULL, 1, "r");
  ASSERT_NE(NULL, fp);
  ASSERT_EQ(-1, fileno(fp));
  ASSERT_EQ(EBADF, errno);
  ASSERT_EQ(0, fclose(fp));
}

TEST(fileno, good) {
  // Open a pipe.
  int fds[2];
  ASSERT_EQ(0, pipe(fds));
  FILE *fp = fdopen(fds[0], "r");
  ASSERT_NE(NULL, fp);

  // Obtain file descriptor.
  ASSERT_EQ(fds[0], fileno(fp));

  // Close pipe.
  ASSERT_EQ(0, fclose(fp));
  ASSERT_EQ(0, close(fds[1]));
}
