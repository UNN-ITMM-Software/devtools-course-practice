// Copyright 2024 Kasimtcev Roman

#ifndef  MODULES_KASIMTCEV_R_POLSKAYA_ZAPIS_INCLUDE_POL_NOT_H_
#define  MODULES_KASIMTCEV_R_POLSKAYA_ZAPIS_INCLUDE_POL_NOT_H_


#include <string>
#include "include/lex.h"
#include "include/stack.h"

class PolNot {
 public:
    bool number(char c);
    int prior(Lex tmp);
    TQueue<P_Lex>* sEOL(std::string _s);
    std::string revPolNot(TQueue<P_Lex>* q);
};
#endif  // MODULES_KASIMTCEV_R_POLSKAYA_ZAPIS_INCLUDE_POL_NOT_H_
