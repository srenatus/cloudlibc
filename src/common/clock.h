// Copyright (c) 2016 Nuxi, https://nuxi.nl/
//
// This file is distributed under a 2-clause BSD license.
// See the LICENSE file for details.

#ifndef COMMON_CLOCK_H
#define COMMON_CLOCK_H

#include <cloudabi_types.h>

// In this implementation we define clockid_t as a pointer type, so that
// we can implement them as full objects. Right now we only use those
// objects to store the raw ABI-level clock identifier, but in the
// future we can use this to provide support for pthread_getcpuclockid()
// and clock file descriptors.
struct __clockid {
  cloudabi_clockid_t id;
};

#endif
