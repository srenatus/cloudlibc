// Copyright (c) 2015 Nuxi, https://nuxi.nl/
//
// This file is distributed under a 2-clause BSD license.
// See the LICENSE file for details.

#include <sched.h>
#include <threads.h>

void thrd_yield(void) {
  sched_yield();
}
