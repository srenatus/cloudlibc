// Copyright (c) 2015 Nuxi, https://nuxi.nl/
//
// This file is distributed under a 2-clause BSD license.
// See the LICENSE file for details.

#include <testing.h>
#include <threads.h>

extern thread_local int tlsvar_i;
thread_local int tlsvar_i = 0x4d653c57;
extern thread_local int tlsvar_j;
thread_local int tlsvar_j = 0;

static int validate(void *arg) {
  // Validate that thread local variables have proper initial values.
  ASSERT_EQ(0x4d653c57, tlsvar_i);
  ASSERT_EQ(0, tlsvar_j);
  return 0;
}

TEST(thread_local, direct) {
  validate(NULL);
}

TEST_SEPARATE_PROCESS(thread_local, process) {
  validate(NULL);
}

TEST(thread_local, thread) {
  thrd_t thread;
  ASSERT_EQ(thrd_success, thrd_create(&thread, validate, NULL));
  ASSERT_EQ(thrd_success, thrd_join(thread, NULL));
}
