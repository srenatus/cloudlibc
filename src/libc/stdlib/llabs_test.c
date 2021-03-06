// Copyright (c) 2015 Nuxi, https://nuxi.nl/
//
// This file is distributed under a 2-clause BSD license.
// See the LICENSE file for details.

#include <limits.h>
#include <stdlib.h>
#include <testing.h>

TEST(llabs, example) {
  ASSERT_EQ(0, llabs(0));
  ASSERT_EQ(42, llabs(42));
  ASSERT_EQ(42, llabs(-42));
  ASSERT_EQ(LLONG_MAX, llabs(LLONG_MAX));
  ASSERT_EQ(LLONG_MAX, llabs(-LLONG_MAX));
}
