// Copyright 2021 Yurin Stanislav

#include <vector>
#include <string>
#include <stdexcept>

#include "include/application.h"
#include "include/wave_algorithm.h"

WaveLib::Application::Application() : message_("") {}

void WaveLib::Application::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a shortest way finder application. " +
        "It use wave algorithm to find it.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <mapHeight> <mapWidth> " +
        "<map> <start_point> <finish_point>\n\n" +

        "Where mapHeight and mapWidth" +
        "are integer-precision positive numbers,\n" +
        "map is boolean-precision array in the following format:\n" +
        "  ['w' or 'f'],['w' or 'f'],...,['w' or 'f']\n" +
        "  where is <w> is the wall,\n" +
        "  and <f> is the free way,\n" +
        "  for example: f,f,w,f,w,w,w,f,w\n" +
        "start_point and finish_point" +
        "is integer-precision pairs in the following format:\n" +
        "  [start_width_value],[start_height_value]"+
        "[finish_width_value],[finish_height_value]\n"
        "  for example: 1,0 2,1\n";
}

bool WaveLib::Application::validateNumberOfArguments(int argc,
                                                     const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 6) {
        help(argv[0], "ERROR: Should be 5 arguments.\n\n");
        return false;
    }
    return true;
}

int parseInt(const char* arg) {
    std::string::size_type end;
    int value;
    try {
        value = std::stoi(arg, &end, 10);
    }
    catch (std::invalid_argument& ex) {
        throw std::runtime_error("Wrong number format!");
    }

    if (arg[end]) {
        throw std::runtime_error("Wrong number format!");
    }

    return value;
}

std::vector<int> parseMap(const char* arg) {
    std::vector<int> map;

    std::istringstream is(arg);
    std::string s;

    while (std::getline(is, s, ',')) {
        if (s == "w")
            map.push_back(WALL);
        else if (s == "f")
            map.push_back(FREE);
        else
            throw std::runtime_error("Wrong map format!");
    }

    return map;
}

WaveLib::Point parsePoint(const char* arg) {
    std::istringstream is(arg);
    std::string s;

    std::getline(is, s, ',');
    int first = parseInt(s.c_str());

    std::getline(is, s);
    int second = parseInt(s.c_str());

    return WaveLib::Point(first, second);
}

std::string WaveLib::Application::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.mapHeight = parseInt(argv[1]);
        args.mapWidth = parseInt(argv[2]);
        args.map = parseMap(argv[3]);
        args.start = parsePoint(argv[4]);
        args.finish = parsePoint(argv[5]);
    }
    catch (std::runtime_error& ex) {
        return ex.what();
    }

    try {
        WaveLib::WaveAlgorithm algorithm(args.mapHeight,
                                         args.mapWidth,
                                         args.map);

        std::vector<WaveLib::Point> path;
        algorithm.findPath(args.start, args.finish, &path);

        std::ostringstream stream;
        stream << "Path: ";
        for (int i = 0; i < static_cast<int>(path.size() - 1); i++)
            stream << path[i].first << ',' << path[i].second << " -> ";
        stream << path.back().first << ',' << path.back().second << "\n";

        message_ = stream.str();
    }
    catch (std::invalid_argument& str) {
        return str.what();
    }

    return message_;
}
