// Copyright 2021 Kiseleva Anastasia

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/volume_app.h"


TEST(test_app, can_create) {
    ASSERT_NO_THROW(Application());
}

TEST(test_app, empty_args) {
    std::vector<const char*> argv = { "app" };
    const int argc = argv.size();
    Application app;

    ASSERT_NO_THROW(app(argc, argv.data()));
}

TEST(test_app, invalid_args) {
    std::vector<const char*> argv = { "app", "Cube", "aa", "2", "5", "0" };
    const int argc = argv.size();
    Application app;

    std::string res = app(argc, argv.data());
    const std::string correct = "invalid arg";

    ASSERT_EQ(correct, res);
}

TEST(test_app, wrong_amount_1) {
    std::vector<const char*> argv = { "app", "Cube", "5", "0", "7" };
    const int argc = argv.size();
    Application app;

    std::string res = app(argc, argv.data());
    const std::string correct = "wrong amount";

    ASSERT_EQ(correct, res);
}

TEST(test_app, wrong_amount_2) {
    std::vector<const char*> argv = { "app", "Sphere",
        "0", "1", "3", "5", "5" };
    const int argc = argv.size();
    Application app;

    std::string res = app(argc, argv.data());
    const std::string correct = "wrong amount";

    ASSERT_EQ(correct, res);
}

TEST(test_app, wrong_amount_3) {
    std::vector<const char*> argv = { "app", "Cone", "2", "3", "3" };
    const int argc = argv.size();
    Application app;

    std::string res = app(argc, argv.data());
    const std::string correct = "wrong amount";

    ASSERT_EQ(correct, res);
}

TEST(test_app, wrong_amount_4) {
    std::vector<const char*> argv = { "app", "Parallelepiped", "-2",
        "31", "30", "10", "10", "5", "0", "9" };
    const int argc = argv.size();
    Application app;

    std::string res = app(argc, argv.data());
    const std::string correct = "wrong amount";

    ASSERT_EQ(correct, res);
}

TEST(test_app, wrong_amount_5) {
    std::vector<const char*> argv = { "app", "Prism", "-24" };
    const int argc = argv.size();
    Application app;

    std::string res = app(argc, argv.data());
    const std::string correct = "wrong amount";

    ASSERT_EQ(correct, res);
}

TEST(test_app, wrong_amount_6) {
    std::vector<const char*> argv = { "app", "Pyramid", "4", "-10", "0" };
    const int argc = argv.size();
    Application app;

    std::string res = app(argc, argv.data());
    const std::string correct = "wrong amount";

    ASSERT_EQ(correct, res);
}

TEST(test_app, wrong_amount_7) {
    std::vector<const char*> argv = { "app", "Torus", "14", "0", "40", "5" };
    const int argc = argv.size();
    Application app;

    std::string res = app(argc, argv.data());
    const std::string correct = "wrong amount";

    ASSERT_EQ(correct, res);
}

TEST(test_app, wrong_amount_8) {
    std::vector<const char*> argv = { "app", "Frustum", "0", "-7", "1", "2",
        "4" , "6", "9" };
    const int argc = argv.size();
    Application app;

    std::string res = app(argc, argv.data());
    const std::string correct = "wrong amount";

    ASSERT_EQ(correct, res);
}

TEST(test_app, cube) {
    std::vector<const char*> argv = { "app", "Cube", "0", "0", "0", "2" };
    const int argc = argv.size();
    Application app;

    std::string res = app(argc, argv.data());
    const std::string correct = "8.000000";

    ASSERT_EQ(correct, res);
}

TEST(test_app, sphere) {
    std::vector<const char*> argv = { "app", "Sphere", "0", "1", "3", "5" };
    const int argc = argv.size();
    Application app;

    std::string res = app(argc, argv.data());
    const std::string correct = "523.598776";

    ASSERT_EQ(correct, res);
}

TEST(test_app, cone) {
    std::vector<const char*> argv = { "app", "Cone", "2", "3", "3", "10", "2" };
    const int argc = argv.size();
    Application app;

    std::string res = app(argc, argv.data());
    const std::string correct = "209.439510";

    ASSERT_EQ(correct, res);
}


TEST(test_app, parallelepiped) {
    std::vector<const char*> argv = { "app", "Parallelepiped", "-2", "31",
        "30", "10", "10", "5" };
    const int argc = argv.size();
    Application app;

    std::string res = app(argc, argv.data());
    double voll = 10 * 10 * 5;
    const std::string correct = std::to_string(voll);

    ASSERT_EQ(correct, res);
}

TEST(test_app, prism) {
    std::vector<const char*> argv = { "app", "Prism", "-24", "0", "0", "1",
        "5", "5" };
    const int argc = argv.size();
    Application app;

    std::string res = app(argc, argv.data());
    const std::string correct = "0.806403";

    ASSERT_EQ(correct, res);
}

TEST(test_app, pyramid) {
    std::vector<const char*> argv = { "app", "Pyramid", "4", "-10", "0",
        "1", "10", "3" };
    const int argc = argv.size();
    Application app;

    std::string res = app(argc, argv.data());
    const std::string correct =  "7.811514";

    ASSERT_EQ(correct, res);
}

TEST(test_app, torus) {
    std::vector<const char*> argv = { "app", "Torus", "14", "0", "40",
        "5", "1" };
    const int argc = argv.size();
    Application app;

    std::string res = app(argc, argv.data());
    const std::string correct = "98.696044";

    ASSERT_EQ(correct, res);
}

TEST(test_app, frustum) {
    std::vector<const char*> argv = { "app", "Frustum", "0", "-7", "1",
        "2", "4" , "6" };
    const int argc = argv.size();
    Application app;

    std::string res = app(argc, argv.data());
    const std::string correct = "175.929189";

    ASSERT_EQ(correct, res);
}
