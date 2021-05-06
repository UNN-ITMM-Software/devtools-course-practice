// Copyright 2021 Bulychev Vladislav

#ifndef MODULES_CONV_AND_CALC_INCLUDE_NUMCONVCALC_H_
#define MODULES_CONV_AND_CALC_INCLUDE_NUMCONVCALC_H_
#include <string>

enum SysBase { BIN, OCT, HEX };

class NumberConverter {
 public:
    explicit NumberConverter(std::string input_number = "0",
        SysBase input_base = BIN);

    std::string GetNumberInBin() const;
    std::string GetNumberInOct() const;
    std::string GetNumberInHex() const;

    NumberConverter operator+ (const NumberConverter& z) const;
    NumberConverter operator- (const NumberConverter& z) const;

 private:
    std::string NumberInBin;
    std::string NumberInOct;
    std::string NumberInHex;

    std::string ConvertBinToOct(const std::string n);
    std::string ConvertBinToHex(const std::string n);

    std::string ConvertOctToBin(const std::string n);
    std::string ConvertHexToBin(const std::string n);

    std::string CutFrontZeros(const std::string n);

    friend std::string ConvertBinToDec(const std::string& n);
    friend std::string ConvertDecToBin(const std::string& n);
};

std::string ConvertBinToDec(const std::string& n);
std::string ConvertDecToBin(const std::string& n);

#endif  // MODULES_CONV_AND_CALC_INCLUDE_NUMCONVCALC_H_
