// Copyright 2024 Mukhin Ivan
#include <gtest/gtest.h>
#include "include/vector_calculator.h"

TEST(mukhin_i_test_cases, can_parse_sentence_1) {
    const char* c[] = {"filename",
                       "{1.05,2.25,3.35}",
                       "{0.95,2.75,3.65}",
                       "+"};
    ASSERT_NO_THROW(mukhin_i::Vector3DApp app(4, c));
}

TEST(mukhin_i_test_cases, can_parse_sentence_2) {
    const char* c[] = {"filename",
                       "{1,2,3}",
                       "{1,2,3}",
                       "@"};
    ASSERT_NO_THROW(mukhin_i::Vector3DApp app(4, c));
}

TEST(mukhin_i_test_cases, cant_parse_wrong_sentence_1) {
    const char* c[] = {"filename",
                       "{1sadas,2,3}",
                       "{1,2,3}",
                       ">"};
    mukhin_i::Vector3DApp app(4, c);
    ASSERT_ANY_THROW(app.calculate());
}

TEST(mukhin_i_test_cases, cant_parse_wrong_sentence_2) {
    const char* c[] = {"filename",
                       "{1,2,3}",
                       "p"};
    mukhin_i::Vector3DApp app(3, c);
    ASSERT_ANY_THROW(app.calculate());
}

TEST(mukhin_i_test_cases, cant_parse_wrong_sentence_3) {
    const char* c[] = {"filename",
                       "{1,2,3}}",
                       "p"};
    ASSERT_ANY_THROW(mukhin_i::Vector3DApp app(3, c););
}
