// Copyright 2021 Kolesin Andrey
#include <gtest/gtest.h>

#include <vector>
#include <string>

#include "include/application.h"

TEST(RadixSort_Application, can_create_application) {
    ASSERT_NO_THROW(Application());
}

TEST(RadixSort_Application, message_if_not_integer) {
    int argc = 5;
    std::vector<const char *> argv = {"app", "2.5", "-3", "3", "0"};
    Application app;
    std::string actual = app(argc, &argv[0]);
    ASSERT_EQ(Application::NOT_INTEGER, actual);
}

TEST(RadixSort_Application, can_sort) {
    int argc = 5;
    std::vector<const char *> argv = {"app", "2", "-3", "10", "0"};
    std::vector<int> expected = {-3, 0, 2, 10};
    Application app;
    app(argc, &argv[0]);
    ASSERT_EQ(expected, app.getArr());
}

TEST(RadixSort_Application, can_print) {
    int argc = 5;
    std::vector<const char *> argv = {"app", "2", "-3", "10", "0"};
    std::string expected = "-3 0 2 10";
    Application app;

    std::string actual = app(argc, &argv[0]);

    ASSERT_EQ(expected, actual);
}

TEST(RadixSort_Application, message_if_out_of_range) {
    int argc = 5;
    std::vector<const char *> argv = {"app", "10000000000000000", "0"};
    Application app;

    std::string actual = app(argc, &argv[0]);

    ASSERT_EQ(Application::OUT_OF_RANGE, actual);
}

TEST(RadixSort_Application, message_if_minus_only) {
    int argc = 5;
    std::vector<const char *> argv = {"app", "-", "123"};
    Application app;

    std::string actual = app(argc, &argv[0]);

    ASSERT_EQ(Application::NOT_INTEGER, actual);
}
