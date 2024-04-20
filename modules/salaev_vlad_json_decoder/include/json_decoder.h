// Copyright 2024 Salaev Vladislav

#ifndef MODULES_SALAEV_VLAD_JSON_DECODER_INCLUDE_JSON_DECODER_H_
#define MODULES_SALAEV_VLAD_JSON_DECODER_INCLUDE_JSON_DECODER_H_

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <cctype>
#include <stdexcept>

enum class JsonType {
    Null, Boolean, Number, String, Array, Object
};

struct JsonValue {
    JsonType type;
    std::string stringValue;
    double numberValue;
    bool booleanValue;
    std::vector<JsonValue> arrayValues;
    std::map<std::string, JsonValue> objectValues;
};

inline std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \n\r\t");
    size_t last = str.find_last_not_of(" \n\r\t");
    return (first == std::string::npos || last == std::string::npos) ? "" :
        str.substr(first, (last - first + 1));
}

inline JsonValue parseJson(const std::string& str, size_t& index);

inline JsonValue parseObject(const std::string& str, size_t& index) {
    JsonValue value;
    value.type = JsonType::Object;
    ++index;  // skip '{'

    while (str[index] != '}') {
        while (std::isspace(str[index])) ++index;
        std::string key = parseJson(str, index).stringValue;
        while (std::isspace(str[index])) ++index;
        ++index;  // skip ':'
        JsonValue val = parseJson(str, index);
        value.objectValues[key] = val;
        while (std::isspace(str[index])) ++index;
        if (str[index] == ',') ++index;  // skip ','
    }
    ++index;  // skip '}'
    return value;
}

inline JsonValue parseArray(const std::string& str, size_t& index) {
    JsonValue value;
    value.type = JsonType::Array;
    ++index;  // skip '['

    while (str[index] != ']') {
        JsonValue val = parseJson(str, index);
        value.arrayValues.push_back(val);
        while (std::isspace(str[index])) ++index;
        if (str[index] == ',') ++index;  // skip ','
    }
    ++index;  // skip ']'
    return value;
}

inline JsonValue parseString(const std::string& str, size_t& index) {
    JsonValue value;
    value.type = JsonType::String;
    std::ostringstream out;
    ++index;  // skip '"'

    while (str[index] != '"' || str[index-1] == '\\') {
        if (str[index] != '\\')
            out << str[index++];
        else
            index++;
    }

    ++index;  // skip closing '"'
    value.stringValue = out.str();
    return value;
}

inline JsonValue parseNumber(const std::string& str, size_t& index) {
    JsonValue value;
    value.type = JsonType::Number;
    std::string num;

    while (std::isdigit(str[index]) || str[index] == '.' || str[index] == '-') {
        num += str[index++];
    }

    value.numberValue = std::stod(num);
    return value;
}

inline JsonValue parseJson(const std::string& str, size_t& index) {
    while (index < str.length() && std::isspace(str[index])) ++index;

    if (str[index] == '{') {
        return parseObject(str, index);
    } else if (str[index] == '[') {
        return parseArray(str, index);
    } else if (str[index] == '"') {
        return parseString(str, index);
    } else if (std::isdigit(str[index]) || str[index] == '-') {
        return parseNumber(str, index);
    } else if (str.substr(index, 4) == "true") {
        index += 4;
        return JsonValue{ JsonType::Boolean, "", 0, true };
    } else if (str.substr(index, 5) == "false") {
        index += 5;
        return JsonValue{ JsonType::Boolean, "", 0, false };
    } else if (str.substr(index, 4) == "null") {
        index += 4;
        return JsonValue{ JsonType::Null };
    }

    throw std::runtime_error("Invalid JSON input");
}

#endif  // MODULES_SALAEV_VLAD_JSON_DECODER_INCLUDE_JSON_DECODER_H_
