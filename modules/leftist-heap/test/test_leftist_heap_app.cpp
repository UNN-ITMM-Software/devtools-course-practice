// Copyright 2021 Tyurmina Alexandra

#include <vector>
#include <string>

#include "include/leftist_heap_app.h"
#include "gtest/gtest.h"


using ::testing::internal::RE;
using std::vector;
using std::string;

class HeapSortTest : public ::testing::Test {
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
  HeapSort app_;
  string output_;
};

TEST_F(HeapSortTest, Print_Info_Without_Args) {
  vector<string> vec = {};

  Act(vec);

  Assert("This is a heapsort application\\..*");
}

TEST_F(HeapSortTest, Check_Type_Of_Arguments1) {
  vector<string> vec = { "1.2", "0", "112", "dd" };

  Act(vec);

  Assert("ERROR : All arguments must be integers\\..*");
}

TEST_F(HeapSortTest, Check_Type_Of_Arguments2) {
  vector<string> vec = { "0", "1", "/", "5" };

  Act(vec);

  Assert("ERROR : All arguments must be integers\\..*");
}

TEST_F(HeapSortTest, Can_Do_HeapSort) {
  vector<string> vec = { "1", "16", "3", "3", "12", "0", "50" };

  Act(vec);

  Assert("Sorted array = 0 1 3 3 12 16 50 ");
}

TEST_F(HeapSortTest, Can_HeapSort_Equal_Numbers) {
  vector<string> vec = { "0", "0", "0", "0" };

  Act(vec);

  Assert("Sorted array = 0 0 0 0 ");
}
