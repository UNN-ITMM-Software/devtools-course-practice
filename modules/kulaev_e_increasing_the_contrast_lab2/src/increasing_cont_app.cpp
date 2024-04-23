// Copyright 2024 Kirillov Maxim
#include <string>
#include <iostream>
#include <sstream>
#include "include/increasing_cont_app.h"

bool IncreasingContrastApp::validate(int argc, char **argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (std::strcmp(argv[1], "--help") == 0) {
        help(argv[0]);
        return false;
    }  else if (argc < 6) {
        help(argv[0], "Incorrect number of arguments");
        return false;
    } else {
        size_t width = std::stoi(argv[argc - 4]);
        size_t height = std::stoi(argv[argc - 3]);
        size_t image_size = width * height;
        if (image_size == 0) {
            help(argv[0], "Image cannot be empty");
            return false;
        } else if (argc - 5 != image_size) {
            help(argv[0], "Incorrect image size");
            return false;
        }
    }

    return true;
}

void IncreasingContrastApp::help(const char *appName, const char *msg) {
    std::string message = msg ? "Error: " + std::string(msg) + "\n\n" : "";
    message =
            std::string(message) +
            "This is an image contrast increasing application.\\n\\n" +
            "Please provide arguments in the following format:\n\n"+

            "  $ " + appName + " <pixel_1> <pixel_2> ..." +
            " <width> <height> <new_min> <new_max>\n\n" +
            "Where <pixel_1>, <pixel_2>, ... are the pixel values," +
            "<width> and <height> are the image dimensions," +
            "<new_min> and <new_max> are the new minimum and " +
            "maximum pixel values,\n";
    message_ = message;
}

std::string IncreasingContrastApp::operator()(int argc, char **argv) {
    if (validate(argc, argv)) {
        std::vector<int> image;
        for (int i = 1; i < argc - 4; i++) {
            image.push_back(std::stoi(argv[i]));
        }
        size_t width = std::stoi(argv[argc - 4]);
        size_t height = std::stoi(argv[argc - 3]);
        int newMin = std::stoi(argv[argc - 2]);
        int newMax = std::stoi(argv[argc - 1]);
        increase_contrast(image, width, height, newMin, newMax);
        std::ostringstream stream;
        stream << "Image after contrast increase:\n";
        for (const auto& pix : image) {
            stream << pix << " ";
        }
        message_ = stream.str();
    }
    return message_;
}
