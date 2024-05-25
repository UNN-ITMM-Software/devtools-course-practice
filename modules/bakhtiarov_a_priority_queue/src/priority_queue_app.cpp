// Copyright 2024 Fedotov Kirill

#include "include/priority_queue_app.h"
#include <sstream>
#include <cstring>
#include <exception>

bool PriorityQueueApplication::Validate(int argc, char *argv[]) {
    int required_argc = 4;
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (std::strcmp(argv[1], "--help") == 0) {
        Help(argv[0]);
        return false;
    } else if (std::strcmp(argv[2], "push") != 0
               && std::strcmp(argv[2], "pop") != 0
               && std::strcmp(argv[2], "front") != 0
               && std::strcmp(argv[2], "back") != 0) {
        Help(argv[0], "Operation must be 'push', 'pop', 'front' or 'back'.");
        return false;
    } else if (argc < required_argc && std::strcmp(argv[2], "push") == 0) {
        Help(argv[0], "Incorrect number of arguments for 'push'.");
        return false;
    } else {
        try {
            int size = std::stoi(argv[1]);
            if (size < 1) {
                throw std::invalid_argument
                ("Queue size must be greater than 0.");
            }
            queue = TQueue_insert<int>(size);
        } catch(const std::exception& e) {
            Help(argv[0], "Invalid arguments.");
            return false;
        }
    }
    return true;
}

void PriorityQueueApplication::Help
(const char *application, const char *errMsg) {
    std::stringstream message;

    if (errMsg) {
        message << "Error: " << errMsg << '\n';
    }

    message << "Usage:\n";
    message << '\t' <<
     application << " <size> <operation> [<value> <priority>]\n";
    message << "Where:\n";
    message << '\t' << "<size> is the maximum size of the queue\n";
    message << '\t' <<
    "<operation> is the queue operation ('push', 'pop', 'front', 'back')\n";
    message << '\t' <<
    "[<value> <priority>] are required for 'push' operation\n";
    msg = message.str();
}

std::string PriorityQueueApplication::ProcessQueueOperations
(int argc, char *argv[]) {
    if (Validate(argc, argv)) {
        try {
            std::stringstream result;
            if (std::strcmp(argv[2], "push") == 0) {
                int value = std::stoi(argv[3]);
                int priority = std::stoi(argv[4]);
                queue.push(std::make_pair(value, priority));
                result << "Pushed (" << value << ", " << priority
                 << ") into the queue.\n";    
            } else if (std::strcmp(argv[2], "pop") == 0) {
                if (queue.isEmpty()) {
                    result << "Queue is empty, cannot pop.\n";
                } else {
                    queue.pop();
                    result << "Popped front element from the queue.\n";
                }
            } else if (std::strcmp(argv[2], "front") == 0) {
                if (queue.isEmpty()) {
                    result << "Queue is empty.\n";
                } else {
                    auto front_elem = queue.front();
                    result << "Front element is: (" << front_elem.first << ", "
                     << front_elem.second << ").\n";
                }
            } else if (std::strcmp(argv[2], "back") == 0) {
                if (queue.isEmpty()) {
                    result << "Queue is empty.\n";
                } else {
                    auto back_elem = queue.back();
                    result << "Back element is: (" << back_elem.first << ", "
                     << back_elem.second << ").\n";
                }
            }
            return result.str();
        } catch(const std::exception& e) {
            return "Error: Invalid input.";
        }
    }
    return msg;
}
