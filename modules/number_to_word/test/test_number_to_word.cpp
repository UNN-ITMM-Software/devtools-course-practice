// Copyright 2021 Lukyanchenko Ivan

#include <gtest/gtest.h>
#include <string>
#include "include/number_to_word.h"


TEST(number_to_word, test_constructor) {
    ASSERT_NO_THROW(num_to_word n(19813));
}

TEST(number_to_word, test_get) {
    num_to_word n(1);
    std::string res = n.get_word();
    ASSERT_EQ(res, "");
}

TEST(number_to_word, test_ten) {
    num_to_word n(13);
    n.num2word();
    std::string res = n.get_word();
    ASSERT_EQ(res, "thirteen ");
}

TEST(number_to_word, test_hundred) {
    num_to_word n(811);
    n.num2word();
    std::string res = n.get_word();
    ASSERT_EQ(res, "eight hundred eleven ");
}

TEST(number_to_word, test_thousand) {
    num_to_word n(20232);
    n.num2word();
    std::string res = n.get_word();
    ASSERT_EQ(res, "twenty  thousand two hundred thirty two");
}

TEST(number_to_word, test_thousand1) {
    num_to_word n(121232);
    n.num2word();
    std::string res = n.get_word();
    ASSERT_EQ(res, "one hundred twenty one thousand two hundred thirty two");
}

TEST(number_to_word, test_thousand2) {
    num_to_word n(111232);
    n.num2word();
    std::string res = n.get_word();
    ASSERT_EQ(res, "one hundred eleven thousand two hundred thirty two");
}

TEST(number_to_word, test_thousand3) {
    num_to_word n(100232);
    n.num2word();
    std::string res = n.get_word();
    ASSERT_EQ(res, "one hundred thousand  two hundred thirty two");
}

TEST(number_to_word, test_million) {
    num_to_word n(1000000);
    n.num2word();
    std::string res = n.get_word();
    ASSERT_EQ(res, "one million     ");
}

TEST(number_to_word, test_million1) {
    num_to_word n(11112312);
    n.num2word();
    std::string res = n.get_word();
    std::string res1;
    res1 += "eleven  million one hundred";
    res1 += " twelve thousand three hundred twelve ";
    ASSERT_EQ(res, res1);
}

TEST(number_to_word, first_million2) {
    num_to_word n(221112312);
    n.num2word();
    std::string res = n.get_word();
    std::string res1;
    res1 += "two hundred twenty one million one";
    res1 += " hundred twelve thousand three hundred twelve ";
    ASSERT_EQ(res, res1);
}
