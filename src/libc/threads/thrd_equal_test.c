// Copyright (c) 2015 Nuxi, https://nuxi.nl/
//
// This file is distributed under a 2-clause BSD license.
// See the LICENSE file for details.

#include <testing.h>
#include <threads.h>

TEST(thrd_equal, equal) {
  ASSERT_TRUE(thrd_equal(thrd_current(), thrd_current()));
}

static int do_nothing(void *arg) {
  return 0;
}

TEST(thrd_equal, unequal) {
  thrd_t thrd;
  ASSERT_EQ(thrd_success, thrd_create(&thrd, do_nothing, NULL));
  ASSERT_FALSE(thrd_equal(thrd_current(), thrd));
  ASSERT_EQ(thrd_success, thrd_join(thrd, NULL));
}
