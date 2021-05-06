// Copyright 2021 Bezrodnov Dmitry

#include <gtest/gtest.h>
#include<string>
#include"include/Vigener.h"

TEST(VigenerTest, correct_test) {
    Vigener_cipher chip("dmitry");
    std::string message = "hello world";
    std::string result_enc = chip.encrypt(message);
    std::string result_dec = chip.decrypt(result_enc);
    ASSERT_EQ(message, result_dec);
}

TEST(VigenerTest, empty_test) {
    Vigener_cipher chip;
    std::string message = "hello world";
    std::string result_enc = chip.encrypt(message);
    std::string result_dec = chip.decrypt(result_enc);
    ASSERT_EQ(message, result_dec);
}

TEST(VigenerTest, set_key_test) {
    Vigener_cipher chip;
    std::string message = "itmm best institute";
    chip.set_key("pmi");
    std::string result_enc = chip.encrypt(message);
    std::string result_dec = chip.decrypt(result_enc);
    ASSERT_EQ(message, result_dec);
}

TEST(VigenerTest, get_key_test) {
    Vigener_cipher chip;
    std::string message = "itmm best institute";
    if (chip.get_key() == "") {
        chip.set_key("pmi");
    }
    std::string result_enc = chip.encrypt(message);
    std::string result_dec = chip.decrypt(result_enc);
    ASSERT_EQ(message, result_dec);
}

TEST(VigenerTest, main_register_test) {
    Vigener_cipher chip;
    std::string message = "NNGU best university";
    if (chip.get_key() == "") {
        chip.set_key("lobachevsky");
    }
    std::string result_enc = chip.encrypt(message);
    std::string result_dec = chip.decrypt(result_enc);
    ASSERT_EQ("nngu best university", result_dec);
}
