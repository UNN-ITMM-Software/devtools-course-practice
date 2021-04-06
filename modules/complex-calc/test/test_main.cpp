// Copyright 2021 Kolesin Andrey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kolesin_Andrey_ComplexNumberTest, can_create_zero) {
    ASSERT_NO_THROW(Complex comp);
}

TEST(Kolesin_Andrey_ComplexNumberTest, can_get_real) {
    Complex comp(3.1);

    ASSERT_DOUBLE_EQ(3.1, comp.getReal());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
