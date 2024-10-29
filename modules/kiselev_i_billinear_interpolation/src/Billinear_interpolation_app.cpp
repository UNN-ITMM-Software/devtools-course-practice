// Copyright 2024 Bodrov Daniil
#include "include/Billinear_interpolation_app.h"

#include <cstring>
#include <iostream>
#include <random>
#include <sstream>

#include "include/Billinear_interpolation.h"

BillinearInterpolationApp::BillinearInterpolationApp() : message_("") {}

void BillinearInterpolationApp::help(const char *appname, const char *msg) {
  std::stringstream message;

  if (msg) message << "Error: " << msg << '\n';

  message << "Usage:\n";
  message << "This is a bilinear interpolation application.\n\n";
  message << "Please provide arguments in the following format:\n\n";
  message << "  $ " << appname
          << " <core_type> <x1> <y1> <x2> <y2> <fill_pixels>\n\n";
  message << "core_type: 'two' or 'three'\n";
  message << "x1, y1: coordinates of the top-left pixel\n";
  message << "x2, y2: coordinates of the bottom-right pixel\n";
  message << "fill_pixels: method to fill the pixels array (e.g., 'random', "
             "'gradient', etc.)\n";

  message_ = message.str();
}

bool BillinearInterpolationApp::validateNumberOfArguments(int argc,
                                                          char *argv[]) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (argc == 2 && std::strcmp(argv[1], "--help") == 0) {
    help(argv[0]);
    return false;
  } else if (argc != 7) {
    help(argv[0], "Incorrect number of arguments.\n\n");
    return false;
  }

  for (int i = 1; i < argc; ++i) {
    if (std::strcmp(argv[i], "--help") == 0) {
      help(argv[0]);
      return false;
    }
  }

  return true;
}

std::string BillinearInterpolationApp::operator()(int argc, char *argv[]) {
  if (!validateNumberOfArguments(argc, argv)) {
    return message_;
  }

  std::string core_type = argv[1];
  int x1 = std::atoi(argv[2]);
  int y1 = std::atoi(argv[3]);
  int x2 = std::atoi(argv[4]);
  int y2 = std::atoi(argv[5]);
  std::string fill_method = argv[6];

  if (core_type != "two" && core_type != "three") {
    return "ERROR: Invalid core type. Available types are 'two' or 'three'.\n";
  }

  std::vector<std::vector<Color>> pixels;

  // Fill the pixels array based on the fill method
  if (fill_method == "random") {
    // Fill pixels array with random colors
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 255);

    pixels.resize(y2 - y1 + 1, std::vector<Color>(x2 - x1 + 1, Color(0, 0, 0)));

    for (int i = y1; i <= y2; ++i) {
      for (int j = x1; j <= x2; ++j) {
        int r = dis(gen);
        int g = dis(gen);
        int b = dis(gen);
        pixels[i - y1][j - x1] = Color(r, g, b);
      }
    }
  } else if (fill_method == "gradient") {
    // Fill pixels array with gradient colors
    pixels.resize(y2 - y1 + 1, std::vector<Color>(x2 - x1 + 1, Color(0, 0, 0)));

    int start_r = 0;
    int start_g = 0;
    int start_b = 255;

    int end_r = 255;
    int end_g = 255;
    int end_b = 255;

    // Calculate color step size for gradient
    double step_r = static_cast<double>(end_r - start_r) / (x2 - x1);
    double step_g = static_cast<double>(end_g - start_g) / (x2 - x1);
    double step_b = static_cast<double>(end_b - start_b) / (x2 - x1);

    for (int i = y1; i <= y2; ++i) {
      for (int j = x1; j <= x2; ++j) {
        int r = start_r + step_r * (j - x1);
        int g = start_g + step_g * (j - x1);
        int b = start_b + step_b * (j - x1);
        pixels[i - y1][j - x1] = Color(r, g, b);
      }
    }
  } else {
    return "ERROR: Invalid fill method. Available methods are 'random' or "
           "'gradient'.\n";
  }

  BillinearInterpolation bi(pixels);
  std::ostringstream stream;
  if (core_type == "two") {
    std::vector<std::vector<Color>> interpolated = bi.twoCore();
    for (const auto &row : interpolated) {
      for (const auto &color : row) {
        stream << color.getR() << " " << color.getG() << " " << color.getB()
               << std::endl;
      }
    }
  } else {
    std::vector<std::vector<Color>> interpolated = bi.threeCore();
    for (const auto &row : interpolated) {
      for (const auto &color : row) {
        stream << color.getR() << " " << color.getG() << " " << color.getB()
               << std::endl;
      }
    }
  }

  message_ = stream.str();
  return message_;
}
