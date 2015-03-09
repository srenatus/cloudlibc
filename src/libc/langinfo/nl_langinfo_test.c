// Copyright (c) 2015 Nuxi, https://nuxi.nl/
//
// This file is distrbuted under a 2-clause BSD license.
// See the LICENSE file for details.

#include <langinfo.h>
#include <locale.h>
#include <testing.h>

TEST(nl_langinfo, posix) {
  // Values that nl_langinfo() should return for the C locale.
  ASSERT_STREQ("US-ASCII", nl_langinfo(CODESET));
  ASSERT_STREQ("%a %b %e %H:%M:%S %Y", nl_langinfo(D_T_FMT));
  ASSERT_STREQ("%m/%d/%y", nl_langinfo(D_FMT));
  ASSERT_STREQ("%H:%M:%S", nl_langinfo(T_FMT));
  ASSERT_STREQ("%I:%M:%S %p", nl_langinfo(T_FMT_AMPM));
  ASSERT_STREQ("AM", nl_langinfo(AM_STR));
  ASSERT_STREQ("PM", nl_langinfo(PM_STR));
  ASSERT_STREQ("Sunday", nl_langinfo(DAY_1));
  ASSERT_STREQ("Monday", nl_langinfo(DAY_2));
  ASSERT_STREQ("Tuesday", nl_langinfo(DAY_3));
  ASSERT_STREQ("Wednesday", nl_langinfo(DAY_4));
  ASSERT_STREQ("Thursday", nl_langinfo(DAY_5));
  ASSERT_STREQ("Friday", nl_langinfo(DAY_6));
  ASSERT_STREQ("Saturday", nl_langinfo(DAY_7));
  ASSERT_STREQ("Sun", nl_langinfo(ABDAY_1));
  ASSERT_STREQ("Mon", nl_langinfo(ABDAY_2));
  ASSERT_STREQ("Tue", nl_langinfo(ABDAY_3));
  ASSERT_STREQ("Wed", nl_langinfo(ABDAY_4));
  ASSERT_STREQ("Thu", nl_langinfo(ABDAY_5));
  ASSERT_STREQ("Fri", nl_langinfo(ABDAY_6));
  ASSERT_STREQ("Sat", nl_langinfo(ABDAY_7));
  ASSERT_STREQ("January", nl_langinfo(MON_1));
  ASSERT_STREQ("February", nl_langinfo(MON_2));
  ASSERT_STREQ("March", nl_langinfo(MON_3));
  ASSERT_STREQ("April", nl_langinfo(MON_4));
  ASSERT_STREQ("May", nl_langinfo(MON_5));
  ASSERT_STREQ("June", nl_langinfo(MON_6));
  ASSERT_STREQ("July", nl_langinfo(MON_7));
  ASSERT_STREQ("August", nl_langinfo(MON_8));
  ASSERT_STREQ("September", nl_langinfo(MON_9));
  ASSERT_STREQ("October", nl_langinfo(MON_10));
  ASSERT_STREQ("November", nl_langinfo(MON_11));
  ASSERT_STREQ("December", nl_langinfo(MON_12));
  ASSERT_STREQ("Jan", nl_langinfo(ABMON_1));
  ASSERT_STREQ("Feb", nl_langinfo(ABMON_2));
  ASSERT_STREQ("Mar", nl_langinfo(ABMON_3));
  ASSERT_STREQ("Apr", nl_langinfo(ABMON_4));
  ASSERT_STREQ("May", nl_langinfo(ABMON_5));
  ASSERT_STREQ("Jun", nl_langinfo(ABMON_6));
  ASSERT_STREQ("Jul", nl_langinfo(ABMON_7));
  ASSERT_STREQ("Aug", nl_langinfo(ABMON_8));
  ASSERT_STREQ("Sep", nl_langinfo(ABMON_9));
  ASSERT_STREQ("Oct", nl_langinfo(ABMON_10));
  ASSERT_STREQ("Nov", nl_langinfo(ABMON_11));
  ASSERT_STREQ("Dec", nl_langinfo(ABMON_12));
  ASSERT_STREQ("", nl_langinfo(ERA));
  ASSERT_STREQ("", nl_langinfo(ERA_D_FMT));
  ASSERT_STREQ("", nl_langinfo(ERA_D_T_FMT));
  ASSERT_STREQ("", nl_langinfo(ERA_T_FMT));
  ASSERT_STREQ("", nl_langinfo(ALT_DIGITS));
  ASSERT_STREQ(".", nl_langinfo(RADIXCHAR));
  ASSERT_STREQ("", nl_langinfo(THOUSEP));
  ASSERT_STREQ("^[yY]", nl_langinfo(YESEXPR));
  ASSERT_STREQ("^[nN]", nl_langinfo(NOEXPR));
  ASSERT_STREQ("", nl_langinfo(CRNCYSTR));
}

TEST(nl_langinfo, nl_nl) {
  // Values that nl_langinfo() should return for the Dutch locale.
  locale_t locale = newlocale(LC_ALL_MASK, "nl_NL.UTF-8@Europe/Amsterdam", 0);
  ASSERT_STREQ("UTF-8", nl_langinfo_l(CODESET, locale));
  ASSERT_STREQ("%a %e %b %H:%M:%S %Y", nl_langinfo_l(D_T_FMT, locale));
  ASSERT_STREQ("%d-%m-%Y", nl_langinfo_l(D_FMT, locale));
  ASSERT_STREQ("%H:%M:%S", nl_langinfo_l(T_FMT, locale));
  ASSERT_STREQ("%I:%M:%S %p", nl_langinfo_l(T_FMT_AMPM, locale));
  ASSERT_STREQ("a.m.", nl_langinfo_l(AM_STR, locale));
  ASSERT_STREQ("p.m.", nl_langinfo_l(PM_STR, locale));
  ASSERT_STREQ("zondag", nl_langinfo_l(DAY_1, locale));
  ASSERT_STREQ("maandag", nl_langinfo_l(DAY_2, locale));
  ASSERT_STREQ("dinsdag", nl_langinfo_l(DAY_3, locale));
  ASSERT_STREQ("woensdag", nl_langinfo_l(DAY_4, locale));
  ASSERT_STREQ("donderdag", nl_langinfo_l(DAY_5, locale));
  ASSERT_STREQ("vrijdag", nl_langinfo_l(DAY_6, locale));
  ASSERT_STREQ("zaterdag", nl_langinfo_l(DAY_7, locale));
  ASSERT_STREQ("zo", nl_langinfo_l(ABDAY_1, locale));
  ASSERT_STREQ("ma", nl_langinfo_l(ABDAY_2, locale));
  ASSERT_STREQ("di", nl_langinfo_l(ABDAY_3, locale));
  ASSERT_STREQ("wo", nl_langinfo_l(ABDAY_4, locale));
  ASSERT_STREQ("do", nl_langinfo_l(ABDAY_5, locale));
  ASSERT_STREQ("vr", nl_langinfo_l(ABDAY_6, locale));
  ASSERT_STREQ("za", nl_langinfo_l(ABDAY_7, locale));
  ASSERT_STREQ("januari", nl_langinfo_l(MON_1, locale));
  ASSERT_STREQ("februari", nl_langinfo_l(MON_2, locale));
  ASSERT_STREQ("maart", nl_langinfo_l(MON_3, locale));
  ASSERT_STREQ("april", nl_langinfo_l(MON_4, locale));
  ASSERT_STREQ("mei", nl_langinfo_l(MON_5, locale));
  ASSERT_STREQ("juni", nl_langinfo_l(MON_6, locale));
  ASSERT_STREQ("juli", nl_langinfo_l(MON_7, locale));
  ASSERT_STREQ("augustus", nl_langinfo_l(MON_8, locale));
  ASSERT_STREQ("september", nl_langinfo_l(MON_9, locale));
  ASSERT_STREQ("oktober", nl_langinfo_l(MON_10, locale));
  ASSERT_STREQ("november", nl_langinfo_l(MON_11, locale));
  ASSERT_STREQ("december", nl_langinfo_l(MON_12, locale));
  ASSERT_STREQ("jan", nl_langinfo_l(ABMON_1, locale));
  ASSERT_STREQ("feb", nl_langinfo_l(ABMON_2, locale));
  ASSERT_STREQ("mrt", nl_langinfo_l(ABMON_3, locale));
  ASSERT_STREQ("apr", nl_langinfo_l(ABMON_4, locale));
  ASSERT_STREQ("mei", nl_langinfo_l(ABMON_5, locale));
  ASSERT_STREQ("jun", nl_langinfo_l(ABMON_6, locale));
  ASSERT_STREQ("jul", nl_langinfo_l(ABMON_7, locale));
  ASSERT_STREQ("aug", nl_langinfo_l(ABMON_8, locale));
  ASSERT_STREQ("sep", nl_langinfo_l(ABMON_9, locale));
  ASSERT_STREQ("okt", nl_langinfo_l(ABMON_10, locale));
  ASSERT_STREQ("nov", nl_langinfo_l(ABMON_11, locale));
  ASSERT_STREQ("dec", nl_langinfo_l(ABMON_12, locale));
  ASSERT_STREQ("", nl_langinfo_l(ERA, locale));
  ASSERT_STREQ("", nl_langinfo_l(ERA_D_FMT, locale));
  ASSERT_STREQ("", nl_langinfo_l(ERA_D_T_FMT, locale));
  ASSERT_STREQ("", nl_langinfo_l(ERA_T_FMT, locale));
  ASSERT_STREQ("", nl_langinfo_l(ALT_DIGITS, locale));
  ASSERT_STREQ(",", nl_langinfo_l(RADIXCHAR, locale));
  ASSERT_STREQ(" ", nl_langinfo_l(THOUSEP, locale));
  ASSERT_STREQ("^[jJyY]", nl_langinfo_l(YESEXPR, locale));
  ASSERT_STREQ("^[nN]", nl_langinfo_l(NOEXPR, locale));
  ASSERT_STREQ("-€", nl_langinfo_l(CRNCYSTR, locale));
  freelocale(locale);
}
