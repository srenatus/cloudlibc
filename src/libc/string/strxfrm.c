// Copyright (c) 2015 Nuxi, https://nuxi.nl/
//
// This file is distributed under a 2-clause BSD license.
// See the LICENSE file for details.

#include <common/locale.h>

#include <locale.h>
#include <string.h>

size_t strxfrm(char *restrict s1, const char *restrict s2, size_t n) {
  DEFAULT_LOCALE(locale, LC_CTYPE_MASK | LC_COLLATE_MASK);
  return strxfrm_l(s1, s2, n, locale);
}
