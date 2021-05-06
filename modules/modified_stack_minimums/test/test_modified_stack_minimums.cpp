// Copyright 2021 Novozhilova Ekaterina

#include <gtest/gtest.h>
#include <iostream>
#include "include/modified_stack_minimums.h"

TEST(Novozhilova_Ekaterina_modified_stack_Test, testgetSize) {
    ModifiedStack mystack(6);

    ASSERT_EQ(6, mystack.getSize());
}

TEST(Novozhilova_Ekaterina_modified_stack_Test, testConstructor) {
    ModifiedStack mystack1(6);

    ModifiedStack mystack2(mystack1);

    ASSERT_EQ(6, mystack2.getSize());
}

TEST(Novozhilova_Ekaterina_modified_stack_Test, testIsEmptyPositive) {
    ModifiedStack mystack(10);

    ASSERT_TRUE(mystack.isEmpty());
}

TEST(Novozhilova_Ekaterina_modified_stack_Test, testIsFullPositive) {
    ModifiedStack mystack(3);

    mystack.push(1);
    mystack.push(2);
    mystack.push(3);

    ASSERT_TRUE(mystack.isFull());
}

TEST(Novozhilova_Ekaterina_modified_stack_Test, testIsEmptyNegative) {
    ModifiedStack mystack(3);

    mystack.push(1);

    ASSERT_FALSE(mystack.isEmpty());
}

TEST(Novozhilova_Ekaterina_modified_stack_Test, testIsFullNegative) {
    ModifiedStack mystack(3);

    mystack.push(1);
    mystack.push(2);

    ASSERT_FALSE(mystack.isFull());
}

TEST(Novozhilova_Ekaterina_modified_stack_Test, testgetMin) {
    ModifiedStack mystack(4);

    mystack.push(1);
    mystack.push(2);
    mystack.push(3);

    ASSERT_EQ(1, mystack.getMin());
}

TEST(Novozhilova_Ekaterina_modified_stack_Test, testgetMin_shuffledOrder) {
    ModifiedStack mystack(4);

    mystack.push(3);
    mystack.push(1);
    mystack.push(2);

    ASSERT_EQ(1, mystack.getMin());
}

TEST(Novozhilova_Ekaterina_modified_stack_Test, testGetTop) {
    ModifiedStack mystack(5);

    mystack.push(13);
    mystack.push(5);
    mystack.push(26);

    ASSERT_EQ(26, mystack.getTop());
}

TEST(Novozhilova_Ekaterina_modified_stack_Test, testPop) {
    ModifiedStack mystack(4);

    mystack.push(13);
    mystack.push(5);
    mystack.push(26);
    mystack.pop();

    ASSERT_EQ(5, mystack.getTop());
}

TEST(Novozhilova_Ekaterina_modified_stack_Test, testCompareEqualPositive) {
    ModifiedStack mystack1(5);

    mystack1.push(20);
    mystack1.push(64);
    mystack1.push(12);
    mystack1.push(3);
    ModifiedStack mystack2(mystack1);
    bool equality = false;
    if (mystack1 == mystack2) {
        equality = true;
    }

    ASSERT_TRUE(equality);
}

TEST(Novozhilova_Ekaterina_modified_stack_Test, testCompareDifferentPositive) {
    ModifiedStack mystack1(5);

    mystack1.push(20);
    mystack1.push(64);
    mystack1.push(12);
    mystack1.push(3);
    ModifiedStack mystack2(mystack1);
    mystack1.push(4);
    bool inequality = false;
    if (mystack1 != mystack2) {
        inequality = true;
    }

    ASSERT_TRUE(inequality);
}

TEST(Novozhilova_Ekaterina_modified_stack_Test, testCompareEqualNegative) {
    ModifiedStack mystack1(5);

    mystack1.push(20);
    mystack1.push(64);
    mystack1.push(12);
    mystack1.push(3);
    ModifiedStack mystack2(mystack1);
    mystack1.push(18);
    bool equality = false;
    if (mystack1 == mystack2) {
        equality = true;
    }

    ASSERT_FALSE(equality);
}

TEST(Novozhilova_Ekaterina_modified_stack_Test, testCompareDifferentNegative) {
    ModifiedStack mystack1(5);

    mystack1.push(20);
    mystack1.push(64);
    mystack1.push(12);
    mystack1.push(3);
    ModifiedStack mystack2(mystack1);
    bool inequality = false;
    if (mystack1 != mystack2) {
        inequality = true;
    }

    ASSERT_FALSE(inequality);
}

TEST(Novozhilova_Ekaterina_modified_stack_Test, testGetLast) {
    ModifiedStack mystack(5);

    mystack.push(20);
    mystack.push(64);
    mystack.push(23);
    mystack.push(34);

    ASSERT_EQ(3, mystack.getLast());
}

TEST(Novozhilova_Ekaterina_modified_stack_Test, testPushInFullStack) {
    ModifiedStack mystack(4);

    mystack.push(20);
    mystack.push(64);
    mystack.push(23);
    mystack.push(34);

    ASSERT_ANY_THROW(mystack.push(56));
}

TEST(Novozhilova_Ekaterina_modified_stack_Test, testEqual) {
    ModifiedStack mystack1(4);
    ModifiedStack mystack2(7);

    mystack1.push(4);
    mystack1.push(75);
    mystack2 = mystack1;
    bool equality = false;
    if (mystack2 == mystack1) {
        equality = true;
    }

    ASSERT_TRUE(equality);
}

TEST(Novozhilova_Ekaterina_modified_stack_Test,
testSizesAfterEquatingAreTheSame) {
    ModifiedStack mystack1(16);
    ModifiedStack mystack2(7);

    mystack1 = mystack2;
    bool equality = false;
    if (mystack1.getSize() == mystack2.getSize()) {
        equality = true;
    }

    ASSERT_TRUE(equality);
}

TEST(Novozhilova_Ekaterina_modified_stack_Test,
testLastIsTheSameAfterEquating) {
    ModifiedStack mystack1(58);
    ModifiedStack mystack2(63);

    mystack1.push(12);
    mystack1.push(14);
    mystack1.push(3);
    mystack1.push(5);
    mystack2.push(9);
    mystack2.push(10);
    mystack1 = mystack2;
    bool equality = false;
    if (mystack1.getLast() == mystack2.getLast()) {
        equality = true;
    }

    ASSERT_TRUE(equality);
}

TEST(Novozhilova_Ekaterina_modified_stack_Test,
testIfSizesAreDiffThenNotEqual) {
    ModifiedStack mystack1(16);
    ModifiedStack mystack2(6);

    ASSERT_FALSE(mystack1 == mystack2);
}

TEST(Novozhilova_Ekaterina_modified_stack_Test,
testIfSizesAreDiffThenNotEqual_2) {
    ModifiedStack mystack1(13);
    ModifiedStack mystack2(3);

    ASSERT_TRUE(mystack1 != mystack2);
}

TEST(Novozhilova_Ekaterina_modified_stack_Test,
testSelfAssignmentAndAssignmet) {
    ModifiedStack mystack1(34);
    ModifiedStack mystack2(5);

    mystack1 = mystack1;
    mystack2 = mystack1;

    ASSERT_TRUE(mystack1 == mystack2);
}

TEST(Novozhilova_Ekaterina_modified_stack_Test, testLoopForPushandGetLast) {
    ModifiedStack mystack(5);

    for (int i = 0; i < 5; i++) {
        mystack.push(i);
    }
    ASSERT_EQ(4, mystack.getLast());
}

TEST(Novozhilova_Ekaterina_modified_stack_Test, testIncorrectSize) {
    ASSERT_ANY_THROW(ModifiedStack mystack(-6));
}
