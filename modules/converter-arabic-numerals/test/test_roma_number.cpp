// Copyright 2021 Gurylev Nikita

#include <gtest/gtest.h>

#include <string>

#include "include/romanumber.h"

TEST(Test_Roma_Number, Create_Roma_Number) {
    ASSERT_NO_THROW(RomaNumber a);
}

TEST(Test_Roma_Number, Correct_Create_Empty_Roma_Number) {
    RomaNumber a;
    ASSERT_EQ(0, a.getArabic());
    ASSERT_EQ("", a.getRoma());
}

TEST(Test_Roma_Number, Create_With_Arab) {
    ASSERT_NO_THROW(RomaNumber a(55));
}

TEST(Test_Roma_Number, Cant_Create_With_Big_Arab) {
    ASSERT_ANY_THROW(RomaNumber a(10000));
}

TEST(Test_Roma_Number, Cant_Create_With_Negative_Number) {
    ASSERT_ANY_THROW(RomaNumber a(-3));
}

TEST(Test_Roma_Number, Correct_Convert_Arab1) {
    RomaNumber s;
    s.arabToRoma(3);
    ASSERT_EQ(3, s.getArabic());
    ASSERT_EQ("III", s.getRoma());
}

TEST(Test_Roma_Number, Correct_Convert_Arab2) {
    RomaNumber s;
    s.arabToRoma(49);
    ASSERT_EQ(49, s.getArabic());
    ASSERT_EQ("XLIX", s.getRoma());
}

TEST(Test_Roma_Number, Correct_Convert_Arab3) {
    RomaNumber s;
    s.arabToRoma(978);
    ASSERT_EQ(978, s.getArabic());
    ASSERT_EQ("CMLXXVIII", s.getRoma());
}

TEST(Test_Roma_Number, Correct_Convert_Arab4) {
    RomaNumber s;
    s.arabToRoma(2395);
    ASSERT_EQ(2395, s.getArabic());
    ASSERT_EQ("MMCCCXCV", s.getRoma());
}

TEST(Test_Roma_Number, Cant_Convert_Too_Big_Arab) {
    RomaNumber s;
    ASSERT_ANY_THROW(s.arabToRoma(4001));
}

TEST(Test_Roma_Number, Can_Create_With_String) {
    ASSERT_NO_THROW(RomaNumber a("XX"));
}

TEST(Test_Roma_Number, Correct_Create_With_String) {
    std::string r = "VIII";
    RomaNumber a(r);
    ASSERT_EQ("VIII", a.getRoma());
    ASSERT_EQ(8, a.getArabic());
}

TEST(Test_Roma_Number, Correct_Convert_Roma) {
    RomaNumber s;
    s.romaToArab("C");
    ASSERT_EQ(100, s.getArabic());
    ASSERT_EQ("C", s.getRoma());
}

TEST(Test_Roma_Number, Correct_Convert_All_Arab) {
    RomaNumber a1, a2;
    for (int i = 0; i < 4000; ++i) {
        a1.arabToRoma(i);
        a2.romaToArab(a1.getRoma());
        ASSERT_EQ(i, a2.getArabic());
    }
}

TEST(Test_Roma_Number, Cant_Create_With_Wrong_String) {
    std::string r = "AX";
    ASSERT_ANY_THROW(RomaNumber a(r));
}
