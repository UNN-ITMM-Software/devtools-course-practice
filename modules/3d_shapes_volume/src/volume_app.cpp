// Copyright 2021 Kiseleva Anastasia

#include <include/3d_shapes_volume.h>
#include <include/volume_app.h>

#include <stdlib.h>
#include <string>
#include <iostream>
#include <cstring>

Application::Application() : message_("") {}

void Application::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a shape volume application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "$ " + appname + " <type of figure>\n\n" +

        "Where types are:\n\n" +
        "Cube <int x> <int y> <int z> <double side> \n" +
        "Sphere <int x> <int y> <int z> <double radius>\n" +
        "Cone <int x> <int y> <int z> <double radius> <double hight>\n" +
        "Parallelepiped <int x> <int y> <int z>"+
        "<double side1> <double side2> <double hight>\n" +
        "Prism <int x> <int y> <int z> <double side> <double hight>"+
        "<int count of corners>\n" +
        "Pyramid <int x> <int y> <int z> <double side> <double hight>"+
        "<int count of corners>\n" +
        "Frustum <int x> <int y> <int z> <double top radius>"+
        "<double radiust> <double hight>\n" +
        "Torus <int x> <int y> <int z> <double center to axis> <radius>\n";
}

bool Application::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    return true;
}

std::string Application::operator()(int argc, const char** argv) {
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        if (strcmp(argv[1], "Cube") == 0) {
            if (argc == 6) {
                Cube shape(std::atoi(argv[2]), std::atoi(argv[3]),
                    std::atoi(argv[4]), std::stod(argv[5]));
               return message_ = std::to_string(shape.Volume());
            } else { return message_ = "wrong amount"; }
        }
        if (strcmp(argv[1], "Sphere") == 0) {
            if (argc == 6) {
                Sphere shape(std::atoi(argv[2]), std::atoi(argv[3]),
                    std::atoi(argv[4]), std::stod(argv[5]));
                return message_ = std::to_string(shape.Volume());
            } else { return message_ = "wrong amount"; }
        }
        if (strcmp(argv[1], "Cone") == 0) {
            if (argc == 7) {
                Cone shape(std::atoi(argv[2]), std::atoi(argv[3]),
                    std::atoi(argv[4]), std::stod(argv[5]), std::stod(argv[6]));
                return message_ = std::to_string(shape.Volume());
            } else { return message_ = "wrong amount"; }
        }
        if (strcmp(argv[1], "Parallelepiped") == 0) {
            if (argc == 8) {
                Parallelepiped shape(std::atoi(argv[2]), std::atoi(argv[3]),
                    std::atoi(argv[4]), std::stod(argv[5]), std::stod(argv[6]),
                    std::stod(argv[7]));
                return message_ = std::to_string(shape.Volume());
            } else { return message_ = "wrong amount"; }
        }
        if (strcmp(argv[1], "Prism") == 0) {
            if (argc == 8) {
                Prism shape(std::atoi(argv[2]), std::atoi(argv[3]),
                    std::atoi(argv[4]),
                    std::stod(argv[5]), std::stod(argv[6]), std::stod(argv[7]));
                return message_ = std::to_string(shape.Volume());
            } else { return message_ = "wrong amount"; }
        }
        if (strcmp(argv[1], "Pyramid") == 0) {
            if (argc == 8) {
                Pyramid shape(std::atoi(argv[2]), std::atoi(argv[3]),
                    std::atoi(argv[4]), std::stod(argv[5]), std::stod(argv[6]),
                    std::stod(argv[7]));
                return message_ = std::to_string(shape.Volume());
            } else { return message_ = "wrong amount"; }
        }
        if (strcmp(argv[1], "Torus") == 0) {
            if (argc == 7) {
                Torus shape(std::atoi(argv[2]), std::atoi(argv[3]),
                    std::atoi(argv[4]), std::stod(argv[5]),
                    std::stod(argv[6]));
                return message_ = std::to_string(shape.Volume());
            } else { return message_ = "wrong amount"; }
        }
        if (strcmp(argv[1], "Frustum") == 0) {
            if (argc == 8) {
            Frustum shape(std::atoi(argv[2]), std::atoi(argv[3]),
                std::atoi(argv[4]), std::stod(argv[5]), std::stod(argv[6]),
                std::stod(argv[7]));
            return message_ = std::to_string(shape.Volume());
        } else { return message_ = "wrong amount"; }
    }
    }
    catch (...) {
        help(argv[0]);
       return message_ = "invalid arg";
    }
    return message_;
}
