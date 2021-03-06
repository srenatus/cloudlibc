// Copyright (c) 2015 Nuxi, https://nuxi.nl/
//
// This file is distributed under a 2-clause BSD license.
// See the LICENSE file for details.

#include <stdio.h>
#include <testing.h>

TEST(clearerr, error) {
  // Create memory file of 10 bytes.
  char buf[10];
  FILE *file = fmemopen(buf, sizeof(buf), "w");
  ASSERT_NE(NULL, file);
  ASSERT_FALSE(feof(file));
  ASSERT_FALSE(ferror(file));

  // We can only write up to five groups of two letters.
  ASSERT_EQ(5, fwrite("Hello, world", 2, 6, file));
  ASSERT_ARREQ("Hello, wor", buf, __arraycount(buf));

  // Clear error condition.
  ASSERT_FALSE(feof(file));
  ASSERT_TRUE(ferror(file));
  clearerr(file);
  ASSERT_FALSE(feof(file));
  ASSERT_FALSE(ferror(file));

  ASSERT_EQ(0, fclose(file));
}

TEST(clearerr, eof) {
  // Create memory file of 12 bytes.
  const char buf[] = "Hello, world";
  FILE *file = fmemopen((void *)buf, sizeof(buf) - 1, "r");
  ASSERT_NE(NULL, file);
  ASSERT_FALSE(feof(file));
  ASSERT_FALSE(ferror(file));

  // We can only read up to two groups of five letters.
  char readbuf[15];
  ASSERT_EQ(2, fread(readbuf, 5, 3, file));
  ASSERT_ARREQ("Hello, wor", buf, 10);

  // Clear error condition.
  ASSERT_TRUE(feof(file));
  ASSERT_FALSE(ferror(file));
  clearerr(file);
  ASSERT_FALSE(feof(file));
  ASSERT_FALSE(ferror(file));

  ASSERT_EQ(0, fclose(file));
}
