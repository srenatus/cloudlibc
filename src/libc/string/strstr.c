// Copyright (c) 2015-2016 Nuxi, https://nuxi.nl/
//
// This file is distributed under a 2-clause BSD license.
// See the LICENSE file for details.

#include <string.h>

#define MEMMEM 0
#define WIDE 0
#include <common/twoway.h>

char *(strstr)(const char *s1, const char *s2) {
  size_t s2len = strlen(s2);
  if (s2len == 0)
    return (char *)s1;
  if (s2len == 1)
    return (char *)strchr(s1, *s2);
  return (char *)twoway_strstr(s1, s2, s2len);
}
