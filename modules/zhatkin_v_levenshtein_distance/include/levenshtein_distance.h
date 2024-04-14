// Copyright 2024 Zhatkin Vyacheslav

#ifndef MODULES_ZHATKIN_V_LEVENSHTEIN_DISTANCE_INCLUDE_LEVENSHTEIN_DISTANCE_H_
#define MODULES_ZHATKIN_V_LEVENSHTEIN_DISTANCE_INCLUDE_LEVENSHTEIN_DISTANCE_H_

#include <string>
#include <vector>

class LevenshteinDistance {
 public:
     LevenshteinDistance();
     LevenshteinDistance(const std::string& str1_, const std::string& str2_);

     int distance();

     void setStr1(const std::string& str1_);
     void setStr2(const std::string& str2_);

     std::string getStr1();
     std::string getStr2();
     int getResult();

 private:
     std::string str1;
     std::string str2;
     int result;
};

#endif  // MODULES_ZHATKIN_V_LEVENSHTEIN_DISTANCE_INCLUDE_LEVENSHTEIN_DISTANCE_H_
