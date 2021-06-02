// Copyright 2021 Bulychev Vladislav

#include <math.h>

#include <string>
#include <sstream>
#include <bitset>

#include "include/NumConvCalc.h"

NumberConverter::NumberConverter(std::string input_number,
    SysBase input_base) {

    switch (input_base) {
    case BIN:
        NumberInBin = CutFrontZeros(input_number);
        NumberInOct = CutFrontZeros(ConvertBinToOct(input_number));
        NumberInHex = CutFrontZeros(ConvertBinToHex(input_number));
        break;
    case OCT:
        NumberInBin = CutFrontZeros(ConvertOctToBin(input_number));
        NumberInOct = CutFrontZeros(input_number);
        NumberInHex = CutFrontZeros(ConvertBinToHex(NumberInBin));
        break;
    case HEX:
        NumberInBin = CutFrontZeros(ConvertHexToBin(input_number));
        NumberInOct = CutFrontZeros(ConvertBinToOct(NumberInBin));
        NumberInHex = CutFrontZeros(ConvertBinToHex(NumberInBin));
        break;
    }
}

std::string NumberConverter::GetNumberInBin() const {
    return NumberInBin;
}

std::string NumberConverter::GetNumberInOct() const {
    return NumberInOct;
}

std::string NumberConverter::GetNumberInHex() const {
    return NumberInHex;
}

std::string NumberConverter::ConvertBinToOct(const std::string n) {
    std::string result;
    int str_length = n.std::string::length();
    int additional_zeros = 0;
    if (str_length % 3 != 0)
        additional_zeros = 3 - str_length % 3;
    result = n;
    for (int i = 0; i < additional_zeros; i++) {
        result.std::string::insert(result.std::string::begin(), '0');
    }
    str_length = result.std::string::length();
    for (int it = 0; it < str_length / 3; it = it + 1) {
        std::string triad = result.std::string::substr(it, 3);
        int int_triad = atoi(triad.std::string::c_str());
        int digit_oct = -1;

        switch (int_triad) {
        case 0:
            digit_oct = 0;
            break;
        case 1:
            digit_oct = 1;
            break;
        case 10:
            digit_oct = 2;
            break;
        case 11:
            digit_oct = 3;
            break;
        case 100:
            digit_oct = 4;
            break;
        case 101:
            digit_oct = 5;
            break;
        case 110:
            digit_oct = 6;
            break;
        case 111:
            digit_oct = 7;
            break;
        default:
            throw("Error");
            break;
        }
        result.replace(it, 3, std::to_string(digit_oct));
    }
    return result;
}

std::string NumberConverter::ConvertBinToHex(const std::string n) {
    std::string result;
    int str_length = n.std::string::length();
    int additional_zeros = 0;
    if (str_length % 4 != 0)
        additional_zeros = 4 - str_length % 4;
    result = n;
    for (int i = 0; i < additional_zeros; i++) {
        result.std::string::insert(result.std::string::begin(), '0');
    }
    str_length = result.std::string::length();
    for (int it = 0; it < str_length / 4; it = it + 1) {
        std::string tetrad = result.std::string::substr(it, 4);
        int int_tetrad = atoi(tetrad.std::string::c_str());
        std::string digit_hex = "-1";

        switch (int_tetrad) {
        case 0:
            digit_hex = '0';
            break;
        case 1:
            digit_hex = '1';
            break;
        case 10:
            digit_hex = '2';
            break;
        case 11:
            digit_hex = '3';
            break;
        case 100:
            digit_hex = '4';
            break;
        case 101:
            digit_hex = '5';
            break;
        case 110:
            digit_hex = '6';
            break;
        case 111:
            digit_hex = '7';
            break;
        case 1000:
            digit_hex = '8';
            break;
        case 1001:
            digit_hex = '9';
            break;
        case 1010:
            digit_hex = 'A';
            break;
        case 1011:
            digit_hex = 'B';
            break;
        case 1100:
            digit_hex = 'C';
            break;
        case 1101:
            digit_hex = 'D';
            break;
        case 1110:
            digit_hex = 'E';
            break;
        case 1111:
            digit_hex = 'F';
            break;
        }

        result.replace(it, 4, digit_hex);
    }
    return result;
}

std::string NumberConverter::ConvertOctToBin(const std::string n) {
    std::string result;
    int str_length = n.std::string::length();
    result = n;

    for (int it = 0; it < str_length * 3; it = it + 3) {
        int oct_digit =
            atoi(result.std::string::substr(it, 1).std::string::c_str());
        std::string triad = "-1";

        switch (oct_digit) {
        case 0:
            triad = "000";
            break;
        case 1:
            triad = "001";
            break;
        case 2:
            triad = "010";
            break;
        case 3:
            triad = "011";
            break;
        case 4:
            triad = "100";
            break;
        case 5:
            triad = "101";
            break;
        case 6:
            triad = "110";
            break;
        case 7:
            triad = "111";
            break;
        default:
            throw("Error");
            break;
        }
        result.replace(it, 1, triad);
    }

    return result;
}

std::string NumberConverter::ConvertHexToBin(const std::string n) {
    std::string result;
    int str_length = n.std::string::length();
    result = n;

    for (int it = 0; it < str_length * 4; it = it + 4) {
        std::string hex_digit = result.std::string::substr(it, 1);
        const char* char_hex_digit = hex_digit.std::string::c_str();
        std::string tetrad = "-1";

        switch (*char_hex_digit) {
        case '0':
            tetrad = "0000";
            break;
        case '1':
            tetrad = "0001";
            break;
        case '2':
            tetrad = "0010";
            break;
        case '3':
            tetrad = "0011";
            break;
        case '4':
            tetrad = "0100";
            break;
        case '5':
            tetrad = "0101";
            break;
        case '6':
            tetrad = "0110";
            break;
        case '7':
            tetrad = "0111";
            break;
        case '8':
            tetrad = "1000";
            break;
        case '9':
            tetrad = "1001";
            break;
        case 'A':
            tetrad = "1010";
            break;
        case 'B':
            tetrad = "1011";
            break;
        case 'C':
            tetrad = "1100";
            break;
        case 'D':
            tetrad = "1101";
            break;
        case 'E':
            tetrad = "1110";
            break;
        case 'F':
            tetrad = "1111";
            break;
        default:
            throw("Error");
            break;
        }
        result.replace(it, 1, tetrad);
    }

    return result;
}

std::string NumberConverter::CutFrontZeros(const std::string n) {
    std::string result = n;
    if (result.std::string::length() > 1) {
        while (result.std::string::substr(0, 1) == "0") {
            result.erase(result.std::string::begin());
        }
    }
    return result;
}

NumberConverter NumberConverter::operator + (
    const NumberConverter& z) const {
    std::string first_bin, second_bin, result_bin;
    std::string first_dec, second_dec, result_dec;

    first_bin = GetNumberInBin();
    second_bin = z.GetNumberInBin();

    first_dec = ConvertBinToDec(first_bin);
    second_dec = ConvertBinToDec(second_bin);

    int first_dec_int, second_dec_int, result_dec_int;
    first_dec_int = std::atoi(first_dec.std::string::c_str());
    second_dec_int = std::atoi(second_dec.std::string::c_str());
    result_dec_int = first_dec_int + second_dec_int;
    result_dec = std::to_string(result_dec_int);

    result_bin = ConvertDecToBin(result_dec);

    NumberConverter result(result_bin, BIN);
    return result;
}

NumberConverter NumberConverter::operator - (
    const NumberConverter& z) const {
    std::string first_bin, second_bin, result_bin;
    std::string first_dec, second_dec, result_dec;

    first_bin = GetNumberInBin();
    second_bin = z.GetNumberInBin();

    first_dec = ConvertBinToDec(first_bin);
    second_dec = ConvertBinToDec(second_bin);

    int first_dec_int, second_dec_int, result_dec_int;
    first_dec_int = std::atoi(first_dec.std::string::c_str());
    second_dec_int = std::atoi(second_dec.std::string::c_str());
    result_dec_int = first_dec_int - second_dec_int;
    result_dec = std::to_string(result_dec_int);

    result_bin = ConvertDecToBin(result_dec);

    NumberConverter result(result_bin, BIN);
    return result;
}

std::string ConvertBinToDec(const std::string& n) {
    std::string bin = n;
    std::string dec;
    int dec_sum = 0;
    int p = 0;
    std::string::iterator it = bin.end();
    do {
        --it;
        int cur_digit = *(it) == '0' ? 0 : 1;
        dec_sum = dec_sum + cur_digit * pow(2, p);
        p++;
    } while (it != bin.begin());
    dec = std::to_string(dec_sum);
    return dec;
}

std::string ConvertDecToBin(const std::string& n) {
    std::string dec = n;
    std::string bin;
    int int_dec = atoi(dec.c_str());
    while (int_dec > 0) {
        int bin_digit = int_dec % 2;
        char bin_digit_char = bin_digit == 0 ? '0' : '1';
        bin.std::string::insert(bin.std::string::begin(), bin_digit_char);
        int_dec = int_dec / 2;
    }

    return bin;
}
