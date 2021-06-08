// Copyright 2021 Ikromov Inom

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "include/conways_game_of_life_application.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class Conwayslife_AppTest : public ::testing::Test {
 protected:
    void Act(vector<string> args_) {
        vector<const char*> options;

        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }
    string output_;
 private:
    Conwayslife_App app_;
};
TEST_F(Conwayslife_AppTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is Conways life game application\\..*");
}

TEST_F(Conwayslife_AppTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = { "1" };

    Act(args);

    Assert("ERROR: not enough arguments\\..*");
}

TEST_F(Conwayslife_AppTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = { "1", "2" , "1", "1" , "v", "0" };

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(Conwayslife_AppTest, Can_Print_Field) {
    vector<string> args = { "5", "5" , "3", "1" , "1", "1",
    "2", "1", "3", "3" };
    std::string res = ". . . . . \n. + + . . \n. . . . . \n. . . + . \n";
    res += ". . . . . \n==========\n. . . . . \n. . . . . \n. . + . . \n";
    res += ". . . . . \n. . . . . \n==========\n";

    Act(args);

    EXPECT_EQ(output_, res);
}

TEST_F(Conwayslife_AppTest, Can_Detect_Wrong_Number_Point) {
    vector<string> args = { "1", "2" , "1" , "1" , "0" };

    Act(args);

    Assert("ERROR: not enough arguments\\..*");
}

TEST_F(Conwayslife_AppTest, Can_be_executed_until_the_end) {
    vector<string> args = { "5", "5" , "3", "10" , "1", "1",
    "2", "1", "3", "3" };
    std::string res = ". . . . . \n. + + . . \n. . . . . \n. . . + . \n";
    res += ". . . . . \n==========\n. . . . . \n. . . . . \n. . + . . \n";
    res += ". . . . . \n. . . . . \n==========\n. . . . . \n";
    res += ". . . . . \n. . . . . \n. . . . . \n. . . . . \n==========\n";

    Act(args);

    EXPECT_EQ(output_, res);
}