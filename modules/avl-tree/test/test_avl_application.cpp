// Copyright 2021 Anastasia Kurnikova

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/avl_application.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class CAvlApplicationTest : public ::testing::Test {
 protected:
    void Act(vector<string> args_) {
        vector<const char*> options;
        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i)
            options.push_back(args_[i].c_str());
        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;
        _output = _app(argc, argv);
    }
    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(_output, RE(expected)));
    }

 private:
    CAvlApplication _app;
    string _output;
};

TEST_F(CAvlApplicationTest , Do_Print_Help_Without_Arguments) {
    vector<string> args = {};
    Act(args);

    Assert("This is an avl application.*");
}

TEST_F(CAvlApplicationTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"2"};
    Act(args);

    Assert("ERROR: Should be at least 2 arguments.*");
}

TEST_F(CAvlApplicationTest, Can_Detect_Invalid_Operation) {
    vector<string> args = {"3", "2", "2", "4", "+"};
    Act(args);

    Assert("Invalid operation!.*");
}

TEST_F(CAvlApplicationTest, Can_Detect_Invalid_Key) {
    vector<string> args = {"11", "invalid key", "-smin"};
    Act(args);

    Assert("Invalid key!.*");
}

TEST_F(CAvlApplicationTest,
    Can_Detect_Invalid_Search_Item) {
    vector<string> args = {"10", "3", "-s"};
    Act(args);

    Assert("Invalid search element!.*");
}

TEST_F(CAvlApplicationTest, Can_Find_Min_Item) {
    vector<string> args =
    {"4", "7", "10", "-14", "21", "124", "-smin"};
    Act(args);

    Assert("-14");
}

TEST_F(CAvlApplicationTest, Can_Find_Max_Item) {
    vector<string> args =
    {"4", "7", "10", "-14", "21", "124", "-smax"};
    Act(args);

    Assert("124");
}

TEST_F(CAvlApplicationTest, Can_Find_Item) {
    vector<string> args = {"4", "7", "10", "-14", "21", "124", "-s", "-14"};
    Act(args);

    Assert("-14");
}
