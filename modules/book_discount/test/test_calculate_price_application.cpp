// Copyright 2021 Zhbanova Nadezhda

#include <gtest/gtest.h>

#include <algorithm>
#include <functional>
#include <iterator>
#include <string>
#include <vector>

#include "include/calculate_price_application.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class CalculatePriceApplicationTest : public ::testing::Test {
 protected:
    void Act(vector<string> args_) {
        vector<const char *> options;
        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }
        const char ** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;
        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }
 private:
    CalculatePriceApplication app_;
    string output_;
};

TEST_F(CalculatePriceApplicationTest, Do_Ptint_Help_Without_Arguments) {
    std::vector<std::string> args = {};

    Act(args);

    Assert("This is application for class calculate price\\..*");
}

TEST_F(CalculatePriceApplicationTest, Is_Checking_Number_Of_Arguments) {
    std::vector<std::string> args = {"1", "0"};

    Act(args);

    Assert("ERROR: Should be 5 arguments\\..*");
}

TEST_F(CalculatePriceApplicationTest, Can_Detect_Wrong_Number_Format) {
    std::vector<std::string> args = {"1", "1", "la", "2", "7"};

    Act(args);

    Assert("ERROR: Wrong number format\\..*");
}

TEST_F(CalculatePriceApplicationTest, Can_Detect_Negative_Arguments) {
    std::vector<std::string> args = {"1", "2", "-4", "4", "5"};

    Act(args);

    Assert("ERROR: Don't negative numbers\\..*");
}

TEST_F(CalculatePriceApplicationTest, Can_Detect_Wrong_Overflow) {
    std::vector<std::string> args = {"1", "2",
        "7234345435636634", "1", "1"};

    Act(args);

    Assert("ERROR: Number is out of bounds\\..*");
}

TEST_F(CalculatePriceApplicationTest,
        Can_Calculate_Price_Without_Discount_For_Same_Books) {
    std::vector<std::string> args = { "7", "0", "0", "0", "0" };

    Act(args);

    Assert("Total Sum = 56");
}

TEST_F(CalculatePriceApplicationTest, Calculate_Price_With_Maximum_Discount) {
    std::vector<std::string> args = { "5", "4", "3", "2", "1" };

    Act(args);

    Assert("Total Sum = 100.4");
}

TEST_F(CalculatePriceApplicationTest, Get_Correct_Discount_On_Two_Diff_Books) {
    std::vector<std::string> args = { "0", "1", "1", "0", "0" };

    Act(args);

    Assert("15.2");
}

TEST_F(CalculatePriceApplicationTest,
        Correct_Discount_On_Three_Different_Books) {
    std::vector<std::string> args = { "0", "1", "1", "1", "0" };

    Act(args);

    Assert("21.6");
}

TEST_F(CalculatePriceApplicationTest,
        Correct_Discount_On_Four_Different_Books) {
    std::vector<std::string> args = { "1", "1", "1", "1", "0" };

    Act(args);

    Assert("25.6");
}

TEST_F(CalculatePriceApplicationTest, Correct_Discount_On_All_Books) {
    std::vector<std::string> args = { "1", "1", "1", "1", "1" };

    Act(args);

    Assert("30");
}
