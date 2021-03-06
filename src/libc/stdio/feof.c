// Copyright (c) 2015 Nuxi, https://nuxi.nl/
//
// This file is distributed under a 2-clause BSD license.
// See the LICENSE file for details.

#include <common/stdio.h>

#include <stdbool.h>
#include <stdio.h>

int feof(FILE *stream) {
  flockfile(stream);
  bool result = (stream->flags & F_EOF) != 0;
  funlockfile(stream);
  return result;
}
