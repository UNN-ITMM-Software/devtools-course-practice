// Copyright 2024 Videneva Ekaterina

#include <gtest/gtest.h>

#include "include/euler_function_app.hpp"

TEST(Euler_function_app, test_default_construct) {
    // Act and Assert
    EXPECT_NO_THROW(application_t app{});
}

TEST(Euler_function_app, test_run_function) {
    // Arange
    application_t app{};

    // Act and Assert
    EXPECT_EQ(app.run(1, NULL), 0);
}

TEST(Euler_function_app, test_not_a_number_in_input) {
    // Arange
    application_t app{};
    const char* args[2] = {"some_sting", "afsadfg-23dada"};


    // Act and Assert
    EXPECT_ANY_THROW(application_t::parse(2, args));
}

TEST(Euler_function_app, test_calc_and_print_result) {
    // Arange
    application_t app{};
    const char* args[2] = {"some_sting", "-2"};


    // Act and Assert
    EXPECT_EQ(application_t::calc_and_print_result({2}), 0);
}
