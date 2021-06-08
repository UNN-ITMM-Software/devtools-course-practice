// Copyright 2021 Ikromov Inom

#include "include/conways_game_of_life.h"
#include "include/conways_game_of_life_application.h"
#include <string>

Conwayslife_App::Conwayslife_App() : message_("") {}

void Conwayslife_App::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is Conways life game application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <sizew_> " +
        "<sizeh_> <numOfStartPoint_> <epsSteps_>" +
        "<points_ vector w-h> \n\n" +

        "Where all arguments are integer numbers. \n";
}
int parseInt(const char* arg) {
    char* end;
    int value = static_cast<int>(strtod(arg, &end));
    if (end[0]) {
        throw std::string("Wrong number format!");
    }
    return value;
}
bool Conwayslife_App::validateNumberOfArguments(int argc, const char **argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else {
        if (argc < 3) {
            help(argv[0], "ERROR: not enough arguments.\n\n");
            return false;
        } else {
            int nOST = parseInt(argv[3]);
            if (argc != 5 + (nOST * 2)) {
                help(argv[0], "ERROR: not enough arguments.\n\n");
            return false;
            }
        }
    }
    return true;
}
std::string Conwayslife_App::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.sizew_ = parseInt(argv[1]);
        args.sizeh_ = parseInt(argv[2]);
        args.numOfStartPoint_ = parseInt(argv[3]);
        args.epsSteps_ = parseInt(argv[4]);

        for (int i = 5; i < 2*args.numOfStartPoint_ + 5; i+=2) {
            args.points_.push_back(parseInt(argv[i]));
            args.points_.push_back(parseInt(argv[i+1]));
        }
    }
    catch (std::string& str) {
        return str;
    }

    Conways_life cLife(args.sizew_, args.sizeh_);

    for (int i = 0; i < args.numOfStartPoint_; i++) {
        cLife.putStart(args.points_[i * 2], args.points_[i * 2 + 1]);
    }

    std::string res;
    res = cLife.Start(res, args.epsSteps_);

    return res;
}