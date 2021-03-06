// Copyright (c) 2015-2016 Nuxi, https://nuxi.nl/
//
// This file is distributed under a 2-clause BSD license.
// See the LICENSE file for details.

#include <sys/uio.h>

#include <assert.h>
#include <cloudabi_syscalls.h>
#include <errno.h>
#include <stddef.h>

static_assert(offsetof(struct iovec, iov_base) ==
                  offsetof(cloudabi_iovec_t, iov_base),
              "Offset mismatch");
static_assert(sizeof(((struct iovec *)0)->iov_base) ==
                  sizeof(((cloudabi_iovec_t *)0)->iov_base),
              "Size mismatch");
static_assert(offsetof(struct iovec, iov_len) ==
                  offsetof(cloudabi_iovec_t, iov_len),
              "Offset mismatch");
static_assert(sizeof(((struct iovec *)0)->iov_len) ==
                  sizeof(((cloudabi_iovec_t *)0)->iov_len),
              "Size mismatch");
static_assert(sizeof(struct iovec) == sizeof(cloudabi_iovec_t),
              "Size mismatch");

ssize_t readv(int fildes, const struct iovec *iov, int iovcnt) {
  if (iovcnt < 0) {
    errno = EINVAL;
    return -1;
  }
  size_t bytes_read;
  cloudabi_errno_t error = cloudabi_sys_fd_read(
      fildes, (const cloudabi_iovec_t *)iov, iovcnt, &bytes_read);
  if (error != 0) {
    errno = error;
    return -1;
  }
  return bytes_read;
}
