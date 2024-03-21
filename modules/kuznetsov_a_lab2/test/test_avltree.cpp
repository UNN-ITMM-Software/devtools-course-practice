// Copyright 2024 Kuznetsov Artem

#include <gtest/gtest.h>

#include <algorithm>
#include <limits>
#include <random>
#include <string>
#include <unordered_set>
#include <utility>

#include "include/avltree.h"

TEST(Test_case_kuznetsov_avltree, testCreateTyDouble) {
  ASSERT_NO_THROW(avlTree<double>());
}

TEST(Test_case_kuznetsov_avltree, testInsertTyInt) {
  avlTree<int> tree;
  const int count = 10;

  ASSERT_TRUE(tree.empty());
  for (int i = 0; i < count; ++i) {
    ASSERT_NO_THROW(tree.insert(i));
    ASSERT_EQ(tree.size(), static_cast<size_t>(i + 1));
  }
  ASSERT_FALSE(tree.empty());
}

TEST(Test_case_kuznetsov_avltree, testInsertOnlyZeroTyInt) {
  avlTree<int> tree;
  const int count = 10;

  ASSERT_TRUE(tree.empty());
  for (int i = 0; i < count; ++i) {
    ASSERT_NO_THROW(tree.insert(0));
    ASSERT_EQ(tree.size(), 1ull);
  }
  ASSERT_FALSE(tree.empty());
}

TEST(Test_case_kuznetsov_avltree, testRemoveTyFloat) {
  avlTree<float> tree;
  const int count = 10;

  for (int i = 0; i < count; ++i) {
    tree.insert(static_cast<float>(i));
  }

  ASSERT_FALSE(tree.empty());
  for (int i = 0; i < count; ++i) {
    ASSERT_NO_THROW(tree.remove(static_cast<float>(i)));
    ASSERT_EQ(tree.size(), static_cast<size_t>(count - (i + 1)));
  }
  ASSERT_TRUE(tree.empty());
}

TEST(Test_case_kuznetsov_avltree, testRemoveEmptyTyInt) {
  ASSERT_ANY_THROW(avlTree<int>().remove(10));
}

TEST(Test_case_kuznetsov_avltree, testClearTyChar) {
  avlTree<char> tree;
  const int count = 10;

  for (int i = 0; i < count; ++i) {
    tree.insert(static_cast<char>(i));
  }

  ASSERT_FALSE(tree.empty());
  tree.clear();
  ASSERT_TRUE(tree.empty());
}

TEST(Test_case_kuznetsov_avltree, testFindTyString) {
  avlTree<std::string> tree;
  const int count = 5;

  for (int i = 0; i < count; ++i) {
    tree.insert(std::string(count, '0' + i));
  }

  std::string strSuccess(count, '4');
  std::string strFailure(count, 'a');

  ASSERT_TRUE(tree.find(strSuccess));
  ASSERT_FALSE(tree.find(strFailure));
}

TEST(Test_case_kuznetsov_avltree, testCopyFuncsTyInt) {
  avlTree<int> treeOne;
  const int count = 10;

  for (int i = 0; i < count; ++i) {
    treeOne.insert(i);
  }

  auto treeTwo(treeOne);
  ASSERT_EQ(treeOne, treeTwo);

  treeOne.clear();
  ASSERT_NE(treeOne, treeTwo);

  treeTwo = treeOne;
  ASSERT_EQ(treeOne, treeTwo);
}

TEST(Test_case_kuznetsov_avltree, testMoveFuncsTyDouble) {
  avlTree<double> treeOne;
  const int count = 10;

  for (int i = 0; i < count; ++i) {
    treeOne.insert(static_cast<double>(i));
  }

  auto treeTwo = std::move(treeOne);

  ASSERT_TRUE(treeOne.empty());
  ASSERT_FALSE(treeTwo.empty());

  treeOne = std::move(treeTwo);

  ASSERT_FALSE(treeOne.empty());
  ASSERT_TRUE(treeTwo.empty());
}

TEST(Test_case_kuznetsov_avltree, testFuncGetTreeAsVectorTyInt) {
  avlTree<int> tree;
  const int count = 10;

  for (int i = 0; i < count; ++i) {
    tree.insert(i);
  }

  std::vector<int> ans{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto res = tree.getTreeAsVector();

  ASSERT_EQ(ans, res);
}

TEST(Test_case_kuznetsov_avltree, testRandomInsert) {
  avlTree<int> tree;
  const int count = 100000;
  std::unordered_set<int> set;

  std::mt19937 gen{std::random_device{}()};
  std::uniform_int_distribution<> dist(std::numeric_limits<int>::min(),
                                       std::numeric_limits<int>::max());

  for (int i = 0; i < count; ++i) {
    auto value = dist(gen);
    set.insert(value);
    tree.insert(value);
  }

  std::vector<int> ans;
  ans.reserve(set.size());

  ans.assign(set.begin(), set.end());
  std::sort(ans.begin(), ans.end());

  auto res = tree.getTreeAsVector();
  ASSERT_EQ(ans, res);
}
