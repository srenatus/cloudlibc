// Copyright (c) 2015 Nuxi, https://nuxi.nl/
//
// This file is distributed under a 2-clause BSD license.
// See the LICENSE file for details.

#include <common/float10.h>

#include <double-conversion/strtod.h>

float __f10enc_get_float(const char *str, size_t len, int exponent) {
  return double_conversion::Strtof(
      double_conversion::Vector<const char>(str, len), exponent);
}
