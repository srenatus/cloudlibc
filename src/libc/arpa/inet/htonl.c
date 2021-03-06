// Copyright (c) 2015 Nuxi, https://nuxi.nl/
//
// This file is distributed under a 2-clause BSD license.
// See the LICENSE file for details.

#include <arpa/inet.h>

#ifndef htonl
#error "htonl is supposed to be a macro as well"
#endif

// clang-format off
uint32_t (htonl)(uint32_t i) {
  return htonl(i);
}
