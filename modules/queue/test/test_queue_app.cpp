// Copyright 2021 Evgeniy Napylov

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/queue_app.h"


TEST(test_queue_app, can_create) {
    ASSERT_NO_THROW(QueueApp());
}

TEST(test_queue_app, empty_args) {
    std::vector<const char*> argv = { "app"};
    const int argc = argv.size();
    QueueApp app;

    ASSERT_NO_THROW(app(argc, argv.data()));
}

TEST(test_queue_app, invalid_args) {
    std::vector<const char*> argv = { "app", "pepega" };
    const int argc = argv.size();
    QueueApp app;

    std::string res = app(argc, argv.data());
    const std::string correct = "invalid arg";

    ASSERT_EQ(correct, res);
}

TEST(test_queue_app, append) {
    std::vector<const char*> argv = { "app", "append", "11.5", "get_first" };
    const int argc = argv.size();
    QueueApp app;

    double res = stod(app(argc, argv.data()));
    const double correct = 11.5;

    ASSERT_EQ(correct, res);
}

TEST(test_queue_app, append_invalid) {
    std::vector<const char*> argv = { "app", "append", "pepega" };
    const int argc = argv.size();
    QueueApp app;

    std::string res = app(argc, argv.data());
    const std::string correct = "Wrong number format!";

    ASSERT_EQ(correct, res);
}

TEST(test_queue_app, is_empty_true) {
    std::vector<const char*> argv = { "app", "is_empty" };
    const int argc = argv.size();
    QueueApp app;

    std::string res = app(argc, argv.data());
    const std::string correct = "1\n";

    ASSERT_EQ(correct, res);
}

TEST(test_queue_app, is_empty_false) {
    std::vector<const char*> argv = { "app", "append", "55", "is_empty" };
    const int argc = argv.size();
    QueueApp app;

    std::string res = app(argc, argv.data());
    const std::string correct = "0\n";

    ASSERT_EQ(correct, res);
}

TEST(test_queue_app, get_first) {
    std::vector<const char*> argv = { "app", "append", "55.1", "get_first" };
    const int argc = argv.size();
    QueueApp app;

    double res = stod(app(argc, argv.data()));
    const double correct = 55.1;

    ASSERT_EQ(correct, res);
}

TEST(test_queue_app, rm_first) {
    std::vector<const char*> argv = { "app", "append", "55.1", "append", "66.2",
                                    "rm_first", "get_first" };
    const int argc = argv.size();
    QueueApp app;

    double res = stod(app(argc, argv.data()));
    const double correct = 66.2;

    ASSERT_EQ(correct, res);
}

TEST(test_queue_app, get_last) {
    std::vector<const char*> argv = { "app", "append", "55.1",
                                "append", "66.2", "get_last" };
    const int argc = argv.size();
    QueueApp app;

    double res = stod(app(argc, argv.data()));
    const double correct = 66.2;

    ASSERT_EQ(correct, res);
}

TEST(test_queue_app, get_size) {
    std::vector<const char*> argv = { "app", "append", "55.1",
                                "append", "66.2", "get_size" };
    const int argc = argv.size();
    QueueApp app;

    int res = stoi(app(argc, argv.data()));
    const int correct = 2;

    ASSERT_EQ(correct, res);
}

TEST(test_queue_app, get_all) {
    std::vector<const char*> argv = { "app", "append", "55.1", "append",
                                                    "66.2", "get_all" };
    const int argc = argv.size();
    QueueApp app;

    std::string res = app(argc, argv.data());
    const std::string correct = "55.100000 66.200000 \n";

    ASSERT_EQ(correct, res);
}

TEST(test_queue_app, append_after_rm) {
    std::vector<const char*> argv = { "app", "append", "11", "append", "22",
                        "rm_first", "append", "33", "append", "44", "get_last"};
    const int argc = argv.size();
    QueueApp app;

    double res = stod(app(argc, argv.data()));
    const double correct = 44.0;

    ASSERT_EQ(correct, res);
}

TEST(test_queue_app, rm_all) {
    std::vector<const char*> argv = { "app", "append", "1", "append", "2",
                                        "rm_first", "rm_first", "get_size"};
    const int argc = argv.size();
    QueueApp app;

    int res = stoi(app(argc, argv.data()));
    const int correct = 0;

    ASSERT_EQ(correct, res);
}
