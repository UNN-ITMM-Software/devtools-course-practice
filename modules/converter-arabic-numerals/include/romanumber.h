// Copyright 2021 Gurylev Nikita

#ifndef MODULES_CONVERTER_ARABIC_NUMERALS_INCLUDE_ROMANUMBER_H_
#define MODULES_CONVERTER_ARABIC_NUMERALS_INCLUDE_ROMANUMBER_H_

#include <string>

class RomaNumber {
 private:
    std::string roma_;
    int arabic_;
    bool IsStringCorrect(const std::string&);
    std::string RomaConvert(int, int);
 public:
    RomaNumber() : roma_(""), arabic_(0) { }
    explicit RomaNumber(const std::string&);
    explicit RomaNumber(int ar);
    void romaToArab(const std::string&);
    void arabToRoma(int ar);
    std::string getRoma() { return roma_; }
    int getArabic() { return arabic_; }
};

#endif  // MODULES_CONVERTER_ARABIC_NUMERALS_INCLUDE_ROMANUMBER_H_
