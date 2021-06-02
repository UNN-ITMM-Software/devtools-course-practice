// Copyright 2021 Ludina Daria

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/mortgage_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class MortgageCalculatorTest : public ::testing::Test {
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
  ASSERT_TRUE(RE::PartialMatch(output_, RE(expected)));
  }

 private:
  mortgage_app app_;
  string output_;
};

TEST_F(MortgageCalculatorTest, Do_Print_Help_Without_Arguments) {
  vector<string> args = {};

  Act(args);

  Assert("This is a mortgage calculator application\\..*");
}

TEST_F(MortgageCalculatorTest, Is_Checking_Number_Of_Arguments) {
  vector<string> args = {"1", "2"};

  Act(args);

  Assert("ERROR: Should be 4 arguments\\..*");
}

TEST_F(MortgageCalculatorTest, Can_Detect_Wrong_Number_Format) {
  vector<string> args = {"1", "pi", "2", "4.0"};

  Act(args);

  Assert("Wrong number format!.*");
}

TEST_F(MortgageCalculatorTest, Can_Interest_Rate) {
  vector<string> args = { "1", "2", "2", "-4.0" };

  Act(args);

  Assert("Interest rate must be greater than zero!.*");
}

TEST_F(MortgageCalculatorTest, Can_Get_MonthlyPayment) {
  vector<string> args = {"2000000", "0", "10", "15.0"};

  Act(args);

  Assert(std::string()+ "c_cost = 2000000 d_downPayment = 0" +
  " c_creditTerm = 120 i_interestRate = 15 payment = 32266");
}
