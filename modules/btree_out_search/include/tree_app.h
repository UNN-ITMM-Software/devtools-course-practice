// Copyright 2021 Bulychev Vladislav

#ifndef MODULES_BTREE_OUT_SEARCH_INCLUDE_TREE_APP_H_
#define MODULES_BTREE_OUT_SEARCH_INCLUDE_TREE_APP_H_

#include <string>

class TreeApp {
 public:
     TreeApp() = default;
     std::string operator()(int argc, const char** argv);
 private:
     std::string help(const std::string& filename) const;
};

#endif  // MODULES_BTREE_OUT_SEARCH_INCLUDE_TREE_APP_H_
