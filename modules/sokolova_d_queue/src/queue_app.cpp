// Copyright 2024 Kochetov Nikolay

#include "include/queue_app.h"


void QueueApp::display(std::string& out) {
    Queue<std::string> temp = queue;
    if (!queue.isEmpty()) {
        for (size_t i = 0; i < queue.size(); i++) {
            out += "[ " + std::to_string(i) + " | "
                + temp.front() + " ]\n";
            temp.dequeue();
        }
    } else {
        out += "queue is empty";
    }
}

size_t QueueApp::size(std::string& out) {
    out += std::to_string(queue.size());
    return queue.size();
}

std::string QueueApp::get_back(std::string& out) {
    out += queue.back();
    return out;
}

std::string QueueApp::get_front(std::string& out) {
    out += queue.front();
    return queue.front();
}

bool QueueApp::isEmpty(std::string& out) {
    if (queue.isEmpty()) {
        out += "queue is empty";
        return queue.isFull();
    } else {
        out += "queue is not empty";
        return queue.isEmpty();
    }
}

bool QueueApp::isFull(std::string& out) {
    if (queue.isFull()) {
        out += "queue is full";
        return queue.isFull();
    } else {
        out += "queue is not full";
        return queue.isFull();
    }
}

std::string QueueApp::push_back(std::string elem, std::string& out) {
    queue.enqueue(elem);
    out += "new element = " + elem;
    return elem;
}

std::string QueueApp::pop_front(std::string& out) {
    std::string temp = queue.front();
    queue.dequeue();
    out += "the item \"" + temp + "\" is out of the queue";
    return temp;
}

std::string QueueApp::get_next(size_t& next, int argc, const char** argv) {
    if (static_cast<int>(next) < argc - 1) {
        next++;
        if (!queue.isFull()) {
            return argv[next];
        } else {
            return "ERROR: queue is full!";
        }
    } else {
        return "ERROR: no args to execute push_back!";
    }
}

std::string QueueApp::Start(int argc, const char** argv) {
    std::vector<std::string> commands(argc);
    std::string output = "";
    for (int i = 0; i < argc; i++) {
        commands.push_back(std::string(argv[i]));
    }
    for (size_t i = 0; i < commands.size(); i++) {
        auto arg = std::string(argv[i]);
        if (arg == "-size") {
            size(output);
        } else if (arg == "-display") {
            display(output);
        } else if (arg == "-get_back") {
            get_back(output);
        } else if (arg == "-get_front") {
            get_front(output);
        } else if (arg == "-isEmpty") {
            isEmpty(output);
        } else if (arg == "-isFull") {
            isFull(output);
        } else if (arg == "-pop_front") {
            pop_front(output);
        } else if (arg == "-push_back") {
            std::string answer = get_next(i, argc, argv);
            if (!(answer.substr(0, 6) == "ERROR:")) {
                push_back(answer, output);
            } else {
                output += answer;
            }
        } else {
            output += "ERROR: the command(" + arg + ") was not recognized!";
        }
        output += '\n';
    }
    return output;
}
