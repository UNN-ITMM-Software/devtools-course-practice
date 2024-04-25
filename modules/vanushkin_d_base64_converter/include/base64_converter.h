// Copyright 2024 Vanushkin Dmitry

#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <utility>

class Base64Encoder {
 private:
    std::string _message;

 public:
    explicit Base64Encoder(const std::string &message);

    std::string Encode() const;

 private:
    std::vector<char> ConvertStringToBytesByAddingEmptyBytes() const;

    unsigned char InterpretSixthBitsGroupToUChar(
            const std::vector<char> &vector, size_t sixthIndex) const;
};

class Base64Decoder {
 private:
    std::string _encodedMessage;

 public:
    explicit Base64Decoder(const std::string &encodedMessage);

    std::string Decode() const;

 private:
    std::pair<std::vector<unsigned char>, size_t>
            ConvertEncodedMessageBytesFromBase64Alphabet() const;
};

namespace internal {

class Base64Alphabet {
 private:
    std::string alphabet;
    std::unordered_map<unsigned char, unsigned char> inverseAlphabet;

 private:
    Base64Alphabet();

 public:
    static Base64Alphabet& GetInstance() {
        static Base64Alphabet instance;
        return instance;
    }

    Base64Alphabet(const Base64Alphabet&) = delete;
    void operator=(const Base64Alphabet&) = delete;

    unsigned char GetSymbolByIndex(unsigned char index) const;

    unsigned char GetIndexBySymbol(unsigned char symbol) const;
};

}  // namespace internal
