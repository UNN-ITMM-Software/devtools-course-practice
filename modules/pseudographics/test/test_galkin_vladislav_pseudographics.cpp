// Copyright 2021 Galkin Vladislav

#include <gtest/gtest.h>

#include <string>
#include "include/Pseudographics.h"

TEST(Galkin_Vladislav_PseudographicsTest, Check_Zero_and_get_graph) {
    int num = 0;
    Pseudographics graph(num);

    std::string str = "._.#|.|#|_|#";

    ASSERT_EQ(str, graph.get_graph());
}

TEST(Galkin_Vladislav_PseudographicsTest, Invalid_value) {
    // Check number less zero
    int num = -15;
    Pseudographics graph(num);

    std::string str = "error#invalid value#error#";

    ASSERT_EQ(str, graph.get_graph());
}

TEST(Galkin_Vladislav_PseudographicsTest, Check_all_numbers) {
    int num = 1234567890;
    Pseudographics graph(num);

    std::string str1 = "... ._. ._. ... ._. ._. ._. ._. ._. ._.#..| ._| ._| |_";
    std::string str2 = "| |_. |_. ..| |_| |_| |.|#..| |_. ._| ..| ._| |_| ..";
    std::string str3 = "| |_| ..| |_|#";
    std::string str_all = str1 + str2 + str3;
    // line constraint 80 sumbols

    ASSERT_EQ(str_all, graph.get_graph());
}

TEST(Galkin_Vladislav_PseudographicsTest, Check_get_Up_Mid_Down_str) {
    int num = 94;
    Pseudographics graph(num);

    std::string strUp = "._. ...#";
    std::string strMid = "|_| |_|#";
    std::string strDown = "..| ..|#";

    // Checking each line separately
    ASSERT_EQ(strUp, graph.get_Up_graph());
    ASSERT_EQ(strMid, graph.get_Mid_graph());
    ASSERT_EQ(strDown, graph.get_Down_graph());
}
