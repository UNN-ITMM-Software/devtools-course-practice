// Copyright 2024 Kasimtcev Roman

#include <string>
#include <stack>
#include <stdexcept>
#include "include/pol_not.h"
#include "include/lex.h"
#include "include/stack.h"

bool PolNot::number(char symv) {
    if ((symv >= '0') && (symv <= '9'))
        return true;
    return false;
}


int PolNot::prior(Lex tmp) {
    if (tmp.getS() == " ")
        return -1;
    if (tmp.getS() == "(" || tmp.getS() == ")")
        return 0;
    if (tmp.getS() == "*" || tmp.getS() == "/")
        return 1;
    else
        return 2;
}


TQueue<P_Lex>* PolNot::sEOL(std::string _s) {
    std::string str;
    char symv;
    TQueue<Lex*>* q = new TQueue<Lex*>;
    State st = q0;
    for (size_t i = 0; i < _s.length(); i++) {
        symv = _s[i];
        if (st == q0) {
            str = symv;
            if (number(symv))
                st = q1;

            if (!number(symv))
                q->push(new Lex(str, operation, -1));
        } else {
            if (st == q1) {
                if (number(symv)) {
                    str += symv;
                } else {
                    int val_ = atoi(str.c_str());
                    q->push(new Lex(str, vall, val_));
                    st = q0;
                    str = symv;
                    q->push(new Lex(str, operation, -1));
                }
            }
        }
    }
    if (number(symv)) {
        str = symv;
        int val_ = atoi(str.c_str());
        q->push(new Lex(str, vall, val_));
    }

    return q;
}


std::string PolNot::revPolNot(TQueue<P_Lex>* l) {
    TQueue<Lex*>* q = new TQueue<Lex*>;
    TStack<Lex*>* stack = new TStack<Lex*>;
    Lex* tmp;
    State st = q0;
    int count = 0;
    while (!l->isEmpty()) {
        if (st == q0) {
            tmp = l->pop();
            if (tmp->getS() == "(") {
                stack->push(tmp);
            } else if (tmp->getS() == ")") {
                    st = q1;
                } else if (tmp->getType() == vall) {
                    int val_ = atoi(tmp->getS().c_str());
                    q->push(new Lex(tmp->getS(), vall, val_));
                } else if (prior(*tmp) >= 1) {
                    if (stack->isEmpty()) {
                        stack->push(tmp);
                    } else {
                        Lex* ltmp = stack->pop();
                        while (!stack->isEmpty() && prior(*ltmp)
                            <= prior(*tmp) && prior(*ltmp) != 0) {
                            q->push(new Lex(ltmp->getS(), operation, -1));
                            ltmp = stack->pop();
                            count++;
                        }
                        if (stack->isEmpty()) {
                            if (prior(*ltmp) <= prior(*tmp))
                                q->push(new Lex(ltmp->getS(), operation, -1));
                            else
                                stack->push(ltmp);
                        } else {
                            if (count == 0)
                                stack->push(ltmp);
                        }
                        stack->push(tmp);
                        count = 0;
                    }
                }
        }
        if (st == q1) {
            Lex* sttmp = stack->pop();

            while (!stack->isEmpty() && sttmp->getS() != "(") {
                q->push(new Lex(sttmp->getS(), operation, -1));
                sttmp = stack->pop();
            }
            st = q0;
        }
    }

    while (!stack->isEmpty())
        q->push(new Lex(stack->pop()->getS(), operation, -1));
    std::string s = "";
    while (!q->isEmpty())
        s += q->pop()->getS();
    delete stack;
    delete q;
    return s;
}
