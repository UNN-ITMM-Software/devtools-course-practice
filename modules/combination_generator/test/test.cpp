// Copyright 2021 Nikolaev Denis
#include <gtest/gtest.h>
#include "include/generator.h"

TEST(Combination_Generate, Test1_Combination_Of_5_For_2) {
    int n = 5;
    int m = 2;
    generator g;
    int h = n > m ? n : m;
    int* a = new int[h];
    for (int i = 0; i < h; i++)
        a[i] = 1;

    for (int i = 0; i < 5; i++) {
        g.NextSet(a, n, m);
    }


    int res[] = { 2, 2 };
    for (int i = 0; i < m; i++) {
        ASSERT_EQ(a[i], res[i]);
    }
}

TEST(Combination_Generate, Test2_Combination_Of_7_For_3) {
    int n = 7;
    int m = 3;
    generator g;
    int h = n > m ? n : m;
    int* a = new int[h];
    for (int i = 0; i < h; i++)
        a[i] = 1;

    for (int i = 0; i < 8; i++) {
        g.NextSet(a, n, m);
    }


    int res[] = { 1, 2, 3 };
    for (int i = 0; i < m; i++) {
        ASSERT_EQ(a[i], res[i]);
    }
}

TEST(Combination_Generate, Test3_Combination_Of_100_For_5) {
    int n = 100;
    int m = 5;
    generator g;
    int h = n > m ? n : m;
    int* a = new int[h];
    for (int i = 0; i < h; i++)
        a[i] = 1;

    for (int i = 0; i < 58; i++) {
        g.NextSet(a, n, m);
    }


    int res[] = { 1, 1, 1, 1, 59 };
    for (int i = 0; i < m; i++) {
        ASSERT_EQ(a[i], res[i]);
    }
}

TEST(Combination_Generate,
    Test4_Combination_Of_4_For_6_With_Using_The_Great_Features_Of_NextSet) {
    int n = 4;
    int m = 6;
    generator g;
    int h = n > m ? n : m;
    int* a = new int[h];
    for (int i = 0; i < h; i++)
        a[i] = 1;

    for (int i = 0; i < 15; i++) {
        g.NextSet(a, n, m);
    }


    int res[] = { 1, 1, 1, 2, 4, 4 };
    for (int i = 0; i < m; i++) {
        ASSERT_EQ(a[i], res[i]);
    }
}


TEST(Permutation_Generate,
    Test5_Combination_Of_2_For_2_With_Using_False_In_NextSet) {
    int n = 2;
    int m = 2;
    generator g;
    int* a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = 1;

    for (int i = 0; i < 15; i++) {
        g.NextSet(a, n, m);
    }


    int res[] = { 2, 2 };
    for (int i = 0; i < m; i++) {
        ASSERT_EQ(a[i], res[i]);
    }
}
