#include "include/hashmap_app.h"
#include <sstream>

void Application::run(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: command key value" << std::endl
            << "Commands: insert, find, remove, clear(no need for key and value)" << std::endl;
        return;
    }

    std::string command(argv[1]);
    if (argc != 4 && command != "clear") {
        std::cerr << "Usage: command key value" << std::endl
            << "Commands: insert, find, remove, clear(no need for key and value)" << std::endl;
        return;
    }
    std::string key = (argc > 2) ? argv[2] : "";
    std::string value = (argc > 3) ? argv[3] : "";

    std::string res = processCommand(command, key, value);
    std::cout << res << std::endl;
}

std::string Application::processCommand(const std::string& command, const std::string& key, const std::string& value)
{
    std::stringstream ss;
    try {
        if (command == "insert") {
            hashMap.insert(key, value);
            ss << "Inserted [" << key << "] = " << value;
        }
        else if (command == "find") {
            ss << "Found [" << key << "] = " << hashMap.find(key);
        }
        else if (command == "remove") {
            hashMap.find(key);
            hashMap.remove(key);
            ss << "Removed key: " << key;
        }
        else if (command == "clear") {
            hashMap.clear();
            ss << "Array cleared";
        }
        else {
            throw std::out_of_range("Invalid command");
        }
    }
    catch (const std::exception& e) {
        ss << "Error: " << e.what();
    }
    return ss.str();
}
