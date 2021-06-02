// Copyright 2021 Lukyanchenko Ivan

#ifndef MODULES_NUMBER_TO_WORD_INCLUDE_NUMBER_TO_WORD_H_
#define MODULES_NUMBER_TO_WORD_INCLUDE_NUMBER_TO_WORD_H_

#include <string>

class num_to_word {
 private:
    int num;
    std::string word;
 public:
    explicit num_to_word(int n) : num(n) {}
    void num2word();
    std::string get_word() const;
};

#endif  // MODULES_NUMBER_TO_WORD_INCLUDE_NUMBER_TO_WORD_H_
