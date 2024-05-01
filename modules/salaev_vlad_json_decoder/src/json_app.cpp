// Copyright 2024 Skotin Alexander

#include "include/json_app.h"
#include <iostream>

void JsonApp::run(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Use: " << argv[0] << " <json_string>" << std::endl;
        return;
    }

    std::string json_string(argv[1]);
    size_t index = 0;

    try {
        JsonValue json = parseJson(json_string, index);
        printJsonValue(json);
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error decoded JSON: " << e.what() << std::endl;
    }
}

void JsonApp::printJsonValue(const JsonValue& value, std::string indent) {
    switch (value.type) {
    case JsonType::Object:
        std::cout << indent << "{" << std::endl;
        for (auto iter = value.objectValues.begin();
            iter != value.objectValues.end(); ++iter) {
            std::cout << indent << "  \"" << iter->first << "\": ";
            printJsonValue(iter->second, indent + "  ");
            if (std::next(iter) != value.objectValues.end()) {
                std::cout << ",";
            }
            std::cout << std::endl;
        }
        std::cout << indent << "}";
        break;
    case JsonType::Array:
        std::cout << indent << "[" << std::endl;
        for (size_t i = 0; i < value.arrayValues.size(); ++i) {
            printJsonValue(value.arrayValues[i], indent + "  ");
            if (i < value.arrayValues.size() - 1) {
                std::cout << ",";
            }
            std::cout << std::endl;
        }
        std::cout << indent << "]";
        break;
    case JsonType::String:
        std::cout << indent << "\"" << value.stringValue << "\"";
        break;
    case JsonType::Number:
        std::cout << indent << value.numberValue;
        break;
    case JsonType::Boolean:
        std::cout << indent << (value.booleanValue ? "true" : "false");
        break;
    case JsonType::Null:
        std::cout << indent << "null";
        break;
    }
    std::cout << std::endl;
}
