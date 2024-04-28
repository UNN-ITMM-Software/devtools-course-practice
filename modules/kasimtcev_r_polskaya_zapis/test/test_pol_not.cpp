// Copyright 2024 Kasimtcev Roman

#include <gtest/gtest.h>
#include <string>
#include "include/pol_not.h"
#include "include/stack.h"

TEST(que, push_pop) {
    TQueue<int> a(10);
    ASSERT_NO_THROW(a.push(3));
    EXPECT_EQ(a.pop(), 3);
}

TEST(que, create) {
    TQueue<int>* a = new TQueue<int>;
    ASSERT_NO_THROW(TQueue<int> a(5));
    EXPECT_EQ(a->isEmpty(), true);
}

TEST(que, create_empty) {
    TQueue<int>* a = new TQueue<int>;
    ASSERT_NO_THROW(TQueue<int> a());
}

TEST(que, copy_queue) {
    TQueue<int>* a = new TQueue<int>;

    ASSERT_NO_THROW(TQueue<int>*s1(a));
}


TEST(que, test_q1) {
    TQueue<int> a(1);
    EXPECT_EQ(a.isEmpty(), true);
}

TEST(que, test_q2) {
    PolNot a1;
    TQueue<Lex*>* lex = new TQueue<Lex*>;
    EXPECT_EQ(lex->isFull(), false);
}

TEST(que, nearly) {
    TQueue<int> a(2);
    EXPECT_EQ(a.next(0), 1);
}
TEST(Lex, create_lex) {
    Lex* a = new Lex();
    Lex a1("/", operation, -1);
    ASSERT_NO_THROW(new Lex("/", operation, -1));
    ASSERT_NO_THROW(new Lex("5", vall, 5));
}
TEST(Lex, create_lex2) {
    ASSERT_NO_THROW(new Lex("/", operation, -1));
}
TEST(Lex, create_lex3) {
    ASSERT_ANY_THROW(new Lex("1", vall, -1));
}
TEST(Lex, create_lex4) {
    ASSERT_NO_THROW(new Lex("", operation, -1));
}
TEST(Lex, create_lex5) {
    EXPECT_ANY_THROW(new Lex("/", operation, 2));
}
TEST(Lex, getVal) {
    Lex z("/", operation, -1);
    ASSERT_NO_THROW(z.getVal());
}

TEST(TStack, create_push_pop) {
    TStack<int> a(2);
    ASSERT_NO_THROW(a.push(1));
    ASSERT_NO_THROW(a.push(2));
    EXPECT_EQ(a.pop(), 2);
}


TEST(TStack, copy_stack) {
    TStack<int>* a = new TStack<int>;

    ASSERT_NO_THROW(TStack<int>*s1(a));
}

TEST(TStack, empty_check) {
    TStack<int>* a = new TStack<int>;
    EXPECT_EQ(true, a->isEmpty());
}


TEST(PolNot, prior_check1) {
    PolNot z;
    Lex lex(")", operation, -1);
    EXPECT_EQ(z.prior(lex), 0);
}

TEST(PolNot, Check_Prioriry2) {
    PolNot z;
    Lex lex("*", operation, -1);
    EXPECT_EQ(z.prior(lex), 1);
}

TEST(PolNot, Check_Prioriry3) {
    PolNot z;
    Lex lex("+", operation, -1);
    EXPECT_EQ(z.prior(lex), 2);
}

TEST(PolNot, Check_Prioriry4) {
    PolNot z;
    Lex lex("/", operation, -1);
    ASSERT_NO_THROW(z.prior(lex));
}

TEST(PolNot, sep_test1) {
    PolNot l1;
    TQueue<Lex*>* lex = new TQueue<Lex*>;
    std::string pr = "1+4/(2-1)*3";
    ASSERT_NO_THROW(l1.sEOL(pr));
}

TEST(PolNot, sep_tes2) {
    PolNot l1;
    TQueue<Lex*>* lex = new TQueue<Lex*>;
    std::string pr = "2-1";
    ASSERT_NO_THROW(l1.sEOL(pr));
}

TEST(PolNot, polnot1) {
    PolNot l1;
    TQueue<Lex*>* lex = new TQueue<Lex*>;
    std::string res;
    std::string str = "1+4/(2-1)*3";
    lex = l1.sEOL(str);
    res = l1.revPolNot(lex);
    EXPECT_EQ(res, "1421-/3*+");
}


TEST(PolNot, polnot2) {
    PolNot l1;
    TQueue<Lex*>* lex = new TQueue<Lex*>;
    std::string res;
    std::string str = "5+2-1";
    lex = l1.sEOL(str);
    res = l1.revPolNot(lex);
    EXPECT_EQ(res, "52+1-");
}


TEST(PolNot, polnot_empty) {
    PolNot l1;
    TQueue<Lex*>* lex = new TQueue<Lex*>;
    std::string res;
    std::string str = " ";
    lex = l1.sEOL(str);
    res = l1.revPolNot(lex);
    EXPECT_EQ(res, "");
}


TEST(PolNot, polnot_num) {
    PolNot l1;
    TQueue<Lex*>* lex = new TQueue<Lex*>;
    std::string res;
    std::string str = "(12)";
    lex = l1.sEOL(str);
    res = l1.revPolNot(lex);
    EXPECT_EQ(res, "12");
}
