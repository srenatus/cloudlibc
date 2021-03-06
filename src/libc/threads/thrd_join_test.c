// Copyright (c) 2015 Nuxi, https://nuxi.nl/
//
// This file is distributed under a 2-clause BSD license.
// See the LICENSE file for details.

#include <testing.h>
#include <threads.h>

static int do_retval(void *arg) {
  return 42;
}

TEST(thrd_join, retval) {
  thrd_t thread;
  ASSERT_EQ(thrd_success, thrd_create(&thread, do_retval, NULL));
  int retval;
  ASSERT_EQ(thrd_success, thrd_join(thread, &retval));
  ASSERT_EQ(42, retval);
}

static int do_exit(void *arg) {
  thrd_exit(1337);
}

TEST(thrd_join, exit) {
  thrd_t thread;
  ASSERT_EQ(thrd_success, thrd_create(&thread, do_exit, NULL));
  int retval;
  ASSERT_EQ(thrd_success, thrd_join(thread, &retval));
  ASSERT_EQ(1337, retval);
}
