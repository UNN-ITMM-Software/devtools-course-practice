// Copyright 2021 Evgeniy Napylov

#include <include/queue.h>
#include <include/queue_app.h>

#include <string>

QueueApp::QueueApp() : message_("") {}

void QueueApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a queue application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "$ " + appname + " <methods>\n\n" +

        "Where methods are:\n\n" +
        "append <value>, where value is double\n" +
        "is_empty\n" +
        "rm_first\n" +
        "get_first\n" +
        "get_last\n" +
        "get_size\n" +
        "get_all\n";
}

bool QueueApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

std::string QueueApp::operator()(int argc, const char** argv) {
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    try {
        int arg_id = 1;
        while (arg_id < argc) {
            std::string method = argv[arg_id];
            if (method == "append") {
                arg_id++;  // go to value arg
                double val = parseDouble(argv[arg_id]);
                queue.append(val);
            } else if (method == "is_empty") {
                bool f = queue.isEmpty();
                message_ += (std::to_string(f) + "\n");
            } else if (method == "rm_first") {
                queue.removeFirst();
            } else if (method == "get_first") {
                double val = queue.getFirstData();
                message_ += (std::to_string(val) + "\n");
            } else if (method == "get_last") {
                double val = queue.getLastData();
                message_ += (std::to_string(val) + "\n");
            } else if (method == "get_size") {
                int val = queue.getSize();
                message_ += (std::to_string(val) + "\n");
            } else if (method == "get_all") {
                std::string all_str = queue.toStringData();
                message_ += (all_str + "\n");
            } else {
                throw std::string("invalid arg");
            }
            arg_id++;
        }
    } catch (std::string& err) {
        message_ = err;
    }

    return message_;
}
