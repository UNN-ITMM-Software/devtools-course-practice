// Copyright 2024 Kasimtcev Roman

#ifndef  MODULES_KASIMTCEV_R_POLSKAYA_ZAPIS_INCLUDE_LEX_H_
#define  MODULES_KASIMTCEV_R_POLSKAYA_ZAPIS_INCLUDE_LEX_H_
#define  P_Lex Lex*

#include <string>

enum Type {
    operation, vall
};
enum State {
    q0, q1
};

class Lex {
    std::string s;
    Type t;
    int val;
 public:
    Lex();
    Lex(std::string _s, Type _t, int _val);
    Type getType();
    int getVal();
    std::string getS();
};

#endif  //  MODULES_KASIMTCEV_R_POLSKAYA_ZAPIS_INCLUDE_LEX_H_
