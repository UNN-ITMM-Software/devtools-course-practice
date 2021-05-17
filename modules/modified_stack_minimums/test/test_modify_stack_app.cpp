// Copyright 2021 Vodeneev Mikhail

#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "include/modified_stack_minimums.h"
#include "include/modify_stack_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class StackAppTest : public ::testing::Test {
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

 private:
    StackApp app_;
    string output_;
};

TEST_F(StackAppTest, Do_Print_Help_Without_Arguments) {
    // Arrange
    vector<string> args = {};

    // Act
    Act(args);

    // Assert
    Assert("This is a modify stack application\\..*");
}

TEST_F(StackAppTest, Is_Checking_Number_Of_Arguments) {
    // Arrange
    vector<string> args = { "1", "2" };

    // Act
    Act(args);

    // Assert
    Assert("ERROR: Should be 1 argument.");
}

TEST_F(StackAppTest, Can_Detect_Wrong_Number_Format) {
    // Arrange
    vector<string> args = { "12ds3 34-1" };

    // Act
    Act(args);

    // Assert
    Assert("ERROR: Wrong format!");
}

TEST_F(StackAppTest, Can_Calculate_Int_Example) {
    // Arrange
    vector<string> args = { "12 3 34 1 6" };

    // Act
    Act(args);

    // Assert
    Assert("MIN: 1 1 3 3 12  Stack: 6 1 34 3 12");
}

TEST_F(StackAppTest, Can_Calculate_Double_Example) {
    // Arrange
    vector<string> args = { "2.5 6.6 1.2 36.364" };

    // Act
    Act(args);

    // Assert
    Assert("MIN: 1.2 1.2 2.5 2.5  Stack: 36.364 1.2 6.6 2.5");
}
