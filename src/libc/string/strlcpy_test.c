// Copyright (c) 2015 Nuxi, https://nuxi.nl/
//
// This file is distributed under a 2-clause BSD license.
// See the LICENSE file for details.

#include <string.h>
#include <testing.h>

TEST(strlcpy, null) {
  ASSERT_EQ(5, strlcpy(NULL, "Hello", 0));
}

TEST(strlcpy, one) {
  char buf;
  ASSERT_EQ(6, strlcpy(&buf, "Banana", 1));
  ASSERT_EQ('\0', buf);
}

TEST(strlcpy, longer) {
  char buf[] = "AAAAAAAAAA";
  ASSERT_EQ(3, strlcpy(buf, "Dog", sizeof(buf)));
  ASSERT_ARREQ("Dog\0AAAAAA", buf, __arraycount(buf));
}

TEST(strlcpy, longest) {
  char buf[12];
  ASSERT_EQ(23, strlcpy(buf, "This is a long sentence", sizeof(buf)));
  ASSERT_STREQ("This is a l", buf);
}
