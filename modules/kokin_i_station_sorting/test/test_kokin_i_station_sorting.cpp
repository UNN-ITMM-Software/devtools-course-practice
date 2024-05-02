// Copyright 2024 Kokin Ivan

#include <gtest/gtest.h>

#include "../include/sort_station.h"
#include "../include/Console_app.h"

TEST(SortingStationTest, ParseValidExpression) {
    SortStationDerived station;
    double result = station.evaluateFunction("1-(2/(4^2))");
    EXPECT_EQ(result, 0.875);
}

TEST(SortStationDerivedTest, EvaluateFunction) {
    SortStationDerived calculator;
    EXPECT_EQ(calculator.evaluateFunction("3+4*2"), 11.0);
}

TEST(SortStationDerivedTest, valid) {
    SortStationDerived calculator;
    EXPECT_EQ(calculator.evaluateFunction("5+3*6-8"), 15.0);
}

TEST(SortStationDerivedTest, valid2) {
    SortStationDerived calculator;
    EXPECT_EQ(calculator.evaluateFunction("4^2+36/12-1"), 5.5);
}

// Vasilev Ivan

TEST(ConsoleAppTest, EvaluateValidExpression) {
    ConsoleApp app;
    testing::internal::CaptureStdout();
    const char* argv[] = {"", "2+2"};
    app.run(2, argv);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Result: 4"), std::string::npos);
}
TEST(ConsoleAppTest, EvaluateComplexExpression) {
    ConsoleApp app;
    testing::internal::CaptureStdout();
    const char* argv[] = {"", "2+3*4"};
    app.run(2, argv);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Result: 14"), std::string::npos);
}

TEST(ConsoleAppTest, EvaluateExpressionWithParentheses) {
    ConsoleApp app;
    testing::internal::CaptureStdout();
    const char* argv[] = {"", "(2+3)*4"};
    app.run(2, argv);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Result: 20"), std::string::npos);
}
TEST(ConsoleAppTest, PrintHelp) {
    ConsoleApp app;
    testing::internal::CaptureStdout();
    app.run(1, nullptr);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Usage:"), std::string::npos);
    EXPECT_NE(output.find("Example:"), std::string::npos);
    EXPECT_NE(output.find("SortStation 2+2"), std::string::npos);
}
TEST(ConsoleAppTest, InvalidNumberOfArguments) {
  ConsoleApp app;
  testing::internal::CaptureStdout();
  app.run(0, nullptr);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_NE(output.find("Usage:"), std::string::npos);
  EXPECT_NE(output.find("Example:"), std::string::npos);
  EXPECT_NE(output.find("SortStation 2+2"), std::string::npos);
}

TEST(ConsoleAppTest, EvaluateAnotherValidExpression) {
  ConsoleApp app;
  testing::internal::CaptureStdout();
  const char* argv[] = {"", "7-4"};
  app.run(2, argv);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_NE(output.find("Result: 3"), std::string::npos);
}

TEST(ConsoleAppTest, TestCaptureStdout) {
  ConsoleApp app;
  testing::internal::CaptureStdout();
  const char* argv[] = {"", "2+2"};
  app.run(2, argv);
  std::string output = testing::internal::GetCapturedStdout();
  // Add any additional assertions here
}

TEST(ErrorHandlingTest, TestCatchException) {
  testing::internal::CaptureStderr();
  try {
    throw std::runtime_error("Test exception");
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  std::string output = testing::internal::GetCapturedStderr();
  EXPECT_NE(output.find("Error: Test exception"), std::string::npos);
}

TEST(ErrorHandlingTest, TestCatchExceptionWithMessage) {
  testing::internal::CaptureStderr();
  try {
    throw std::runtime_error("Custom error message");
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  std::string output = testing::internal::GetCapturedStderr();
  EXPECT_NE(output.find("Error: Custom error message"), std::string::npos);
}

TEST(ErrorHandlingTest, TestCatchExceptionWithNestedException) {
  testing::internal::CaptureStderr();
  try {
    try {
      throw std::runtime_error("Inner exception");
    } catch (const std::exception& e) {
      throw std::runtime_error("Outer exception: " + std::string(e.what()));
    }
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  std::string output = testing::internal::GetCapturedStderr();
  EXPECT_NE(output.find("Error: Outer exception: Inner exception"),
   std::string::npos);
}

TEST(ErrorHandlingTest, TestCatchExceptionWithNoMessage) {
  testing::internal::CaptureStderr();
  try {
    throw std::exception();
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  std::string output = testing::internal::GetCapturedStderr();
  EXPECT_NE(output.find("Error: "), std::string::npos);
}
