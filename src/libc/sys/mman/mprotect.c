// Copyright (c) 2015-2016 Nuxi, https://nuxi.nl/
//
// This file is distributed under a 2-clause BSD license.
// See the LICENSE file for details.

#include <sys/mman.h>

#include <cloudabi_syscalls.h>
#include <errno.h>

int mprotect(void *addr, size_t len, int prot) {
  cloudabi_errno_t error = cloudabi_sys_mem_protect(addr, len, prot);
  if (error != 0) {
    errno = error;
    return -1;
  }
  return 0;
}
