// Copyright (c) 2015-2016 Nuxi, https://nuxi.nl/
//
// This file is distributed under a 2-clause BSD license.
// See the LICENSE file for details.

#include <sys/time.h>

#include <testing.h>
#include <time.h>

TEST(gettimeofday, example) {
  struct timespec ts;
  ASSERT_EQ(0, clock_gettime(CLOCK_REALTIME, &ts));
  struct timeval tv;
  ASSERT_EQ(0, gettimeofday(&tv));

  // Resulting time should be about the same as clock_gettime().
  ASSERT_EQ(1, tv.tv_sec / ts.tv_sec);
  ASSERT_LE(0, tv.tv_usec);
  ASSERT_GT(1000000000, tv.tv_usec);
}
