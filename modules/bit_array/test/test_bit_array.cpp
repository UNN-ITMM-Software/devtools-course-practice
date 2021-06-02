// Copyright 2021 Gushchin Artem

#include <gtest/gtest.h>

#include <vector>

#include "include/bit_array.h"

TEST(Bit_Array_Test, Can_Create_Bit_Array_With_Positive_Length) {
    ASSERT_NO_THROW(BitArray bf(3));
}

TEST(Bit_Array_Test, Can_Get_Length) {
    BitArray bf(3);

    ASSERT_EQ(3, bf.GetLength());
}

TEST(Bit_Array_Test, New_Bit_Array_Is_Set_To_Zero) {
    BitArray bf(100);

    int sum = 0;
    for (int i = 0; i < bf.GetLength(); i++) {
        sum += bf.GetBit(i);
    }

    ASSERT_EQ(0, sum);
}

TEST(Bit_Array_Test, Can_Construct_From_Another_Bit_Array) {
    BitArray bf(15);
    bf.SetBit(1);
    bf.SetBit(3);
    bf.SetBit(14);

    BitArray constructed(bf);

    ASSERT_EQ(bf, constructed);
    ASSERT_EQ(1, constructed.GetBit(1));
    ASSERT_EQ(1, constructed.GetBit(3));
    ASSERT_EQ(1, constructed.GetBit(14));
}

TEST(Bit_Array_Test, Can_Set_Bit) {
    BitArray bf(10);

    ASSERT_EQ(0, bf.GetBit(3));

    bf.SetBit(3);
    ASSERT_NE(0, bf.GetBit(3));
}

TEST(Bit_Array_Test, Can_Clear_Bit) {
    BitArray bf(10);

    int bitIdx = 3;

    bf.SetBit(bitIdx);
    ASSERT_NE(0, bf.GetBit(bitIdx));

    bf.ClrBit(bitIdx);
    ASSERT_EQ(0, bf.GetBit(bitIdx));
}

TEST(Bit_Array_Test, Throws_When_Create_Bit_Array_With_Negative_Length) {
    ASSERT_ANY_THROW(BitArray bf(-3));
}

TEST(Bit_Array_Test, Throws_When_Set_Bit_With_Negative_Index) {
    BitArray bf(10);

    ASSERT_ANY_THROW(bf.SetBit(-3));
}

TEST(Bit_Array_Test, Throws_When_Set_Bit_With_Too_Large_Index) {
    BitArray bf(10);

    ASSERT_ANY_THROW(bf.SetBit(11));
}

TEST(Bit_Array_Test, Throws_When_Get_Bit_With_Negative_Index) {
    BitArray bf(10);

    ASSERT_ANY_THROW(bf.GetBit(-3));
}

TEST(Bit_Array_Test, Throws_When_Get_Bit_With_Too_Large_Index) {
    BitArray bf(10);

    ASSERT_ANY_THROW(bf.GetBit(11));
}

TEST(Bit_Array_Test, Throws_When_Clear_Bit_With_Negative_Index) {
    BitArray bf(10);

    ASSERT_ANY_THROW(bf.ClrBit(-3));
}

TEST(Bit_Array_Test, Throws_When_Clear_Bit_With_Too_Large_Index) {
    BitArray bf(10);

    ASSERT_ANY_THROW(bf.ClrBit(11));
}

TEST(Bit_Array_Test, Can_Assign_Bit_Arrays_Of_Equal_Size) {
    const int size = 2;
    BitArray bf1(size), bf2(size);

    for (int i = 0; i < size; i++) {
        bf1.SetBit(i);
    }
    bf2 = bf1;

    ASSERT_NE(0, bf2.GetBit(0));
    ASSERT_NE(0, bf2.GetBit(1));
}

TEST(Bit_Array_Test, Assign_Operator_Changes_Bit_Array_Size) {
    const int size1 = 2, size2 = 5;
    BitArray bf1(size1), bf2(size2);

    for (int i = 0; i < size1; i++) {
        bf1.SetBit(i);
    }
    bf2 = bf1;

    ASSERT_EQ(2, bf2.GetLength());
}

TEST(Bit_Array_Test, Can_Assign_Bit_Arrays_Of_Non_Equal_Size) {
    const int size1 = 2, size2 = 5;
    BitArray bf1(size1), bf2(size2);

    for (int i = 0; i < size1; i++) {
        bf1.SetBit(i);
    }
    bf2 = bf1;

    ASSERT_NE(0, bf2.GetBit(0));
    ASSERT_NE(0, bf2.GetBit(1));
}

TEST(Bit_Array_Test, Compare_Equal_Bit_Arrays_Of_Equal_Size) {
    const int size = 2;
    BitArray bf1(size), bf2(size);

    for (int i = 0; i < size; i++) {
        bf1.SetBit(i);
    }
    bf2 = bf1;

    ASSERT_EQ(bf1, bf2);
}

TEST(Bit_Array_Test, Compare_Non_Equal_Bit_Arrays_First_Less_Second) {
    const int size1 = sizeof(uint) * 8 * 2, size2 = sizeof(uint) * 8 * 3;
    BitArray bf1(size1), bf2(size2);

    for (int i = 0; i < size1; i++) {
        bf1.SetBit(i);
    }
    bf2.SetBit(1);

    ASSERT_NE(bf1, bf2);
}

TEST(Bit_Array_Test, Compare_Partially_Equal_Bit_Arrays_First_Less_Second) {
    const int size1 = sizeof(uint) * 8 * 2, size2 = sizeof(uint) * 8 * 3;
    BitArray bf1(size1), bf2(size2);

    for (int i = 0; i < size1; i++) {
        bf1.SetBit(i);
        bf2.SetBit(i);
    }
    bf2.SetBit(size1 + 1);

    ASSERT_NE(bf1, bf2);
}

TEST(Bit_Array_Test, Compare_Non_Equal_Bit_Arrays_Second_Less_First) {
    const int size1 = sizeof(uint) * 8 * 5, size2 = sizeof(uint) * 8 * 2;
    BitArray bf1(size1), bf2(size2);

    for (int i = 0; i < size2; i++) {
        bf2.SetBit(i);
    }
    bf1.SetBit(1);

    ASSERT_NE(bf1, bf2);
}

TEST(Bit_Array_Test, Compare_Partially_Equal_Bit_Arrays_Second_Less_First) {
    const int size1 = sizeof(uint) * 8 * 5, size2 = sizeof(uint) * 8 * 2;
    BitArray bf1(size1), bf2(size2);

    for (int i = 0; i < size2; i++) {
        bf1.SetBit(i);
        bf2.SetBit(i);
    }
    bf1.SetBit(size2 + 1);

    ASSERT_NE(bf1, bf2);
}

TEST(Bit_Array_Test, Or_Operator_Applied_To_Bit_Arrays_Of_Equal_Size) {
    const int size = 4;
    BitArray bf1(size), bf2(size), expBf(size);
    // expBf = 0111
    expBf.SetBit(1);
    expBf.SetBit(2);
    expBf.SetBit(3);

    // bf1 = 0011
    bf1.SetBit(2);
    bf1.SetBit(3);
    // bf2 = 0101
    bf2.SetBit(1);
    bf2.SetBit(3);

    ASSERT_EQ(expBf, bf1 | bf2);
}

TEST(Bit_Array_Test, Or_Operator_First_Array_Less_Second) {
    const int size1 = sizeof(uint) * 8 * 1, size2 = sizeof(uint) * 8 * 4;
    BitArray bf1(size1), bf2(size2), expBf(size2);
    // expBf = 1..1..00111
    expBf.SetBit(1);
    expBf.SetBit(2);
    expBf.SetBit(3);
    expBf.SetBit(8);
    expBf.SetBit(size2);

    // bf1 = 0..1..00110
    bf1.SetBit(2);
    bf1.SetBit(3);
    bf1.SetBit(8);
    // bf2 = 1..1..00001
    bf2.SetBit(1);
    bf2.SetBit(8);
    bf2.SetBit(size2);

    ASSERT_EQ(expBf, bf1 | bf2);
}

TEST(Bit_Array_Test, Or_Operator_Second_Array_Less_First) {
    const int size1 = sizeof(uint) * 8 * 6, size2 = sizeof(uint) * 8 * 2;
    BitArray bf1(size1), bf2(size2), expBf(size1);
    // expBf = 1..1..1..100011
    expBf.SetBit(1);
    expBf.SetBit(2);
    expBf.SetBit(6);
    expBf.SetBit(8);
    expBf.SetBit(16);
    expBf.SetBit(size1);

    // bf1 = 1..1..1..000001
    bf1.SetBit(1);
    bf1.SetBit(8);
    bf1.SetBit(16);
    bf1.SetBit(size1);
    // bf2 = 0..1..100011
    bf2.SetBit(1);
    bf2.SetBit(2);
    bf2.SetBit(6);
    bf2.SetBit(16);

    ASSERT_EQ(expBf, bf1 | bf2);
}

TEST(Bit_Array_Test, And_Operator_Applied_To_Bit_Arrays_Of_Equal_Size) {
    const int size = 4;
    BitArray bf1(size), bf2(size), expBf(size);
    // expBf = 0001
    expBf.SetBit(3);

    // bf1 = 0011
    bf1.SetBit(2);
    bf1.SetBit(3);
    // bf2 = 0101
    bf2.SetBit(1);
    bf2.SetBit(3);

    ASSERT_EQ(expBf, bf1 & bf2);
}

TEST(Bit_Array_Test, And_Operator_First_Array_Less_Second) {
    const int size1 = sizeof(uint) * 8 * 2, size2 = sizeof(uint) * 8 * 3;
    BitArray bf1(size1), bf2(size2), expBf(size2);
    // expBf = 0..1..00010
    expBf.SetBit(3);
    expBf.SetBit(8);

    // bf1 = 0..1..00011
    bf1.SetBit(2);
    bf1.SetBit(3);
    bf1.SetBit(8);
    // bf2 = 1..1..01010
    bf2.SetBit(1);
    bf2.SetBit(3);
    bf2.SetBit(8);
    bf2.SetBit(size2);

    ASSERT_EQ(expBf, bf1 & bf2);
}

TEST(Bit_Array_Test, And_Operator_Second_Array_Less_First) {
    const int size1 = sizeof(uint) * 8 * 5, size2 = sizeof(uint) * 8 * 3;
    BitArray bf1(size1), bf2(size2), expBf(size1);
    // expBf = 0..1..100001
    expBf.SetBit(1);
    expBf.SetBit(6);
    expBf.SetBit(12);

    // bf1 = 1..1..100101
    bf1.SetBit(1);
    bf1.SetBit(3);
    bf1.SetBit(6);
    bf1.SetBit(12);
    bf1.SetBit(size1);
    // bf2 = 0..1..100011
    bf2.SetBit(1);
    bf2.SetBit(2);
    bf2.SetBit(6);
    bf2.SetBit(12);

    ASSERT_EQ(expBf, bf1 & bf2);
}


TEST(Bit_Array_Test, Can_Invert_Bit_Array) {
    const int size = 2;
    BitArray bf(size), negBf(size), expNegBf(size);
    // expNegBf = 10
    expNegBf.SetBit(0);

    // bf = 01
    bf.SetBit(1);
    negBf = ~bf;

    ASSERT_EQ(expNegBf, negBf);
}

TEST(Bit_Array_Test, Can_Invert_Large_Bit_Array) {
    const int size = 38;
    BitArray bf(size), negBf(size), expNegBf(size);
    for (int i = 0; i < size; i++)
        expNegBf.SetBit(i);
    expNegBf.ClrBit(35);

    bf.SetBit(35);
    negBf = ~bf;

    ASSERT_EQ(expNegBf, negBf);
}

TEST(Bit_Array_Test, Invert_Plus_And_Operator_On_Different_Size_Bit_Array) {
    const int firstSze = 4, secondSize = 8;
    BitArray firstBf(firstSze), negFirstBf(firstSze),
             secondBf(secondSize), testBf(secondSize);
    // testBf = 00001000
    testBf.SetBit(3);

    // firstBf = 0001
    firstBf.SetBit(0);
    negFirstBf = ~firstBf;
    // negFirstBf = 1110

    // secondBf = 00011000
    secondBf.SetBit(3);
    secondBf.SetBit(4);

    ASSERT_EQ(testBf, secondBf & negFirstBf);
}

TEST(Bit_Array_Test, Can_Invert_Many_Random_Bits_Bit_Array) {
    const int size = 38;
    BitArray bf(size), negBf(size), expNegBf(size);

    std::vector<int> bits;
    bits.push_back(0);
    bits.push_back(1);
    bits.push_back(14);
    bits.push_back(16);
    bits.push_back(33);
    bits.push_back(37);

    for (int i = 0; i < size; i++)
        expNegBf.SetBit(i);
    for (unsigned int i = 0; i < bits.size(); i++)
        expNegBf.ClrBit(bits[i]);

    for (unsigned int i = 0; i < bits.size(); i++)
        bf.SetBit(bits[i]);

    negBf = ~bf;

    ASSERT_EQ(expNegBf, negBf);
}

TEST(Bit_Array_Test, Bit_Arrays_With_Different_Bits_Are_Not_Equal) {
    const int size = 4;
    BitArray bf1(size), bf2(size);

    bf1.SetBit(1);
    bf1.SetBit(3);

    bf2.SetBit(1);
    bf2.SetBit(2);

    ASSERT_NE(bf1, bf2);
}
