// Copyright 2021 Bulychev Vladislav

#include <gtest/gtest.h>

#include <string>

#include "include/NumConvCalc.h"

TEST(Bulychev_V_NumConvCalc, Can_Create_With_No_Arguments) {
    ASSERT_NO_THROW(NumberConverter());
}

TEST(Bulychev_V_NumConvCalc, Does_Throw_When_Wrong_Bin) {
    ASSERT_ANY_THROW(NumberConverter conv("11010131", BIN));
}

TEST(Bulychev_V_NumConvCalc, Does_Throw_When_Wrong_Oct) {
    ASSERT_ANY_THROW(NumberConverter conv("128", OCT));
}

TEST(Bulychev_V_NumConvCalc, Does_Throw_When_Wrong_Hex) {
    ASSERT_ANY_THROW(NumberConverter conv("GHIJ", HEX));
}

TEST(Bulychev_V_NumConvCalc, ConvertBinToOctAndHex_1) {
    NumberConverter conv("1000", BIN);

    ASSERT_EQ("1000", conv.GetNumberInBin());
    ASSERT_EQ("10", conv.GetNumberInOct());
    ASSERT_EQ("8", conv.GetNumberInHex());
}

TEST(Bulychev_V_NumConvCalc, ConvertBinToOctAndHex_2) {
    NumberConverter conv("110110", BIN);

    ASSERT_EQ("110110", conv.GetNumberInBin());
    ASSERT_EQ("66", conv.GetNumberInOct());
    ASSERT_EQ("36", conv.GetNumberInHex());
}

TEST(Bulychev_V_NumConvCalc, ConvertOctToBinAndHex_1) {
    NumberConverter conv("10", OCT);

    ASSERT_EQ("1000", conv.GetNumberInBin());
    ASSERT_EQ("10", conv.GetNumberInOct());
    ASSERT_EQ("8", conv.GetNumberInHex());
}

TEST(Bulychev_V_NumConvCalc, ConvertOctToBinAndHex_2) {
    NumberConverter conv("010", OCT);

    ASSERT_EQ("1000", conv.GetNumberInBin());
    ASSERT_EQ("10", conv.GetNumberInOct());
    ASSERT_EQ("8", conv.GetNumberInHex());
}

TEST(Bulychev_V_NumConvCalc, ConvertHexToBinAndOct_1) {
    NumberConverter conv("ABC", HEX);

    ASSERT_EQ("101010111100", conv.GetNumberInBin());
    ASSERT_EQ("5274", conv.GetNumberInOct());
    ASSERT_EQ("ABC", conv.GetNumberInHex());
}

TEST(Bulychev_V_NumConvCalc, ConvertHexToBinAndOct_2) {
    NumberConverter conv("000ABC", HEX);

    ASSERT_EQ("101010111100", conv.GetNumberInBin());
    ASSERT_EQ("5274", conv.GetNumberInOct());
    ASSERT_EQ("ABC", conv.GetNumberInHex());
}

TEST(Bulychev_V_NumConvCalc, CanConvertBinToDec) {
    std::string bin = "1010";
    std::string dec = "10";

    ASSERT_EQ(dec, ConvertBinToDec(bin));
}

TEST(Bulychev_V_NumConvCalc, CanConvertDecToBin) {
    std::string dec = "10";
    std::string bin = "1010";

    ASSERT_EQ(bin, ConvertDecToBin(dec));
}

TEST(Bulychev_V_NumConvCalc, CanConvertBinToHex) {
    NumberConverter bin(
        "1010101111001101111011111001100001110110010101000011001000010000",
        BIN);
    std::string hex = "ABCDEF9876543210";

    ASSERT_EQ(hex, bin.GetNumberInHex());
}

TEST(Bulychev_V_NumConvCalc, CanConvertHexToBin) {
    NumberConverter hex("ABCDEF9876543210", HEX);
    std::string bin =
        "1010101111001101111011111001100001110110010101000011001000010000";

    ASSERT_EQ(bin, hex.GetNumberInBin());
}

TEST(Bulychev_V_NumConvCalc, CanConvertOctToBin) {
    NumberConverter oct("1257157371416625031020", OCT);
    std::string bin =
        "1010101111001101111011111001100001110110010101000011001000010000";

    ASSERT_EQ(bin, oct.GetNumberInBin());
}

TEST(Bulychev_V_NumConvCalc, CanSum) {
    NumberConverter conv1("1111", BIN);
    NumberConverter conv2("12", OCT);

    ASSERT_NO_THROW(conv1 + conv2);
}

TEST(Bulychev_V_NumConvCalc, CanSumCorrectly_1) {
    NumberConverter conv1("1111", BIN);
    NumberConverter conv2("12", OCT);

    NumberConverter convres = conv1 + conv2;

    ASSERT_EQ("11001", convres.GetNumberInBin());
}

TEST(Bulychev_V_NumConvCalc, CanSumCorrectly_2) {
    NumberConverter conv1("1111", BIN);
    NumberConverter conv2("12", OCT);

    NumberConverter convres = conv1 + conv2;

    ASSERT_EQ("31", convres.GetNumberInOct());
}

TEST(Bulychev_V_NumConvCalc, CanSumCorrectly_3) {
    NumberConverter conv1("1111", BIN);
    NumberConverter conv2("12", OCT);

    NumberConverter convres = conv1 + conv2;

    ASSERT_EQ("19", convres.GetNumberInHex());
}

TEST(Bulychev_V_NumConvCalc, CanDiff) {
    NumberConverter conv1("1111", BIN);
    NumberConverter conv2("12", OCT);

    ASSERT_NO_THROW(conv1 - conv2);
}

TEST(Bulychev_V_NumConvCalc, CanDiffCorrectly_1) {
    NumberConverter conv1("1111", BIN);
    NumberConverter conv2("12", OCT);

    NumberConverter convres = conv1 - conv2;

    ASSERT_EQ("101", convres.GetNumberInBin());
}

TEST(Bulychev_V_NumConvCalc, CanDiffCorrectly_2) {
    NumberConverter conv1("1111", BIN);
    NumberConverter conv2("12", OCT);

    NumberConverter convres = conv1 - conv2;

    ASSERT_EQ("5", convres.GetNumberInOct());
}

TEST(Bulychev_V_NumConvCalc, CanDiffCorrectly_3) {
    NumberConverter conv1("1111", BIN);
    NumberConverter conv2("12", OCT);

    NumberConverter convres = conv1 - conv2;

    ASSERT_EQ("5", convres.GetNumberInHex());
}

TEST(Bulychev_V_NumConvCalc, CutFrontZeros) {
    NumberConverter conv("0001", BIN);

    ASSERT_EQ("1", conv.GetNumberInBin());
    ASSERT_EQ("1", conv.GetNumberInOct());
    ASSERT_EQ("1", conv.GetNumberInHex());
}
