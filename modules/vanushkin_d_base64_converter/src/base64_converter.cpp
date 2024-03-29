// Copyright 2024 Vanushkin Dmitry

#include <unordered_map>
#include "include/base64_converter.h"

Base64Encoder::Base64Encoder(const std::string &message) : _message(message) {}

Base64Encoder::Base64Encoder(std::string &&message):
    _message(std::move(message)) {}

std::string Base64Encoder::Encode() const {
    auto buffer = ConvertStringToByteBufferWithAlignment(_message);
    auto addedEmptyBytes = buffer.size() - _message.size();

    auto sixthsCount = (buffer.size() * 8) / 6;

    auto encodedMessage = std::vector<unsigned char>();
    encodedMessage.reserve(sixthsCount);

    for (size_t sixthIndex = 0; sixthIndex < sixthsCount; ++sixthIndex) {
        auto number = ExtractSixthBitsAsSizeT(buffer, sixthIndex);
        if (number >= 64) {
            throw std::exception("Awful");
        }

        encodedMessage.push_back(internal::Base64Alphabet::GetInstance()
        .GetSymbolByIndex(number));
    }

    for (size_t i = 0; i < addedEmptyBytes; ++i) {
        encodedMessage[encodedMessage.size() - 1 - i] = '=';
    }

    return {encodedMessage.cbegin(), encodedMessage.cend()};
}

std::vector<char> Base64Encoder::ConvertStringToByteBufferWithAlignment(
        const std::string &str) const {
    auto remainder = str.size() % 3;
    auto emptyBytesNeeded = (3 - remainder) % 3;

    std::vector<char> buffer(str.cbegin(), str.cend());

    buffer.reserve(emptyBytesNeeded);
    while (emptyBytesNeeded--) {
        buffer.push_back(0);
    }

    return std::move(buffer);
}

size_t Base64Encoder::ExtractSixthBitsAsSizeT(
        const std::vector<char>& vector, size_t sixthIndex) const {
    auto startByteIndex = (6 * sixthIndex) / 8;
    auto startBitIndex = (6 * sixthIndex) % 8;

    auto endBitIndex = (startBitIndex + 5) % 8;

    auto startByte = vector[startByteIndex];

    // Sixth include in byte entirely
    if (endBitIndex > startBitIndex) {
        // Extract sixth from byte
        auto part = (unsigned char) (startByte >> (2 - startBitIndex));

        // Set first and second bits of part to zero
        return part & ~192;
    }

    auto highestPart = ((unsigned char)(startByte << startBitIndex))
            >> (startBitIndex - 1 - endBitIndex);
    auto lowestPart = vector[startByteIndex + 1] >> (7 - endBitIndex);

    return highestPart + lowestPart;
}

Base64Decoder::Base64Decoder(const std::string &encodedMessage) :
    _encodedMessage(encodedMessage) {}

Base64Decoder::Base64Decoder(std::string &&encodedMessage) :
    _encodedMessage(std::move(encodedMessage)) {}

std::string Base64Decoder::Decode() const {
    if (_encodedMessage.empty()) {
        return "";
    }

    auto otherBytesNeedToDecode = (3 * _encodedMessage.size()) % 4;

    if (otherBytesNeedToDecode != 0) {
        auto message = "Encoded message must as least have "
                + std::to_string(otherBytesNeedToDecode)
                + " bytes to decode";
        throw std::exception(message.c_str());
    }

    auto pair = ConvertEncodedMessageBytesFromBase64Alphabet();

    auto& convertedMessage = pair.first;
    auto specialBytesCount = pair.second;

    auto bytesFromDecodedMessage =
            (3 * _encodedMessage.size()) / 4 - specialBytesCount;

    std::vector<char> decodedMessage;
    decodedMessage.reserve(bytesFromDecodedMessage);

    auto encodedByteIndex = 0;
    auto encodedStartBitFromByteIndex = 0;

    for (size_t decodedByteIndex = 0; decodedByteIndex <
        bytesFromDecodedMessage; decodedByteIndex++) {
        auto encodedByte = convertedMessage[encodedByteIndex];
        auto highestPart = encodedByte << (encodedStartBitFromByteIndex + 2);

        auto endBitAbsoluteIndex = (encodedStartBitFromByteIndex + 4 + 7) % 8;
        auto endByte = convertedMessage[encodedByteIndex + 1];
        auto lowestPart = endByte >> (7 - endBitAbsoluteIndex);

        decodedMessage.push_back(highestPart + lowestPart);

        encodedByteIndex++;
        if (endBitAbsoluteIndex + 1 == 8) {
            encodedByteIndex++;
            encodedStartBitFromByteIndex = 0;
        } else {
            encodedStartBitFromByteIndex = endBitAbsoluteIndex - 1;
        }
    }

    return {decodedMessage.cbegin(), decodedMessage.cend()};
}

std::pair<std::vector<unsigned char>, size_t>
        Base64Decoder::ConvertEncodedMessageBytesFromBase64Alphabet() const {
    auto& alphabet = internal::Base64Alphabet::GetInstance();

    std::vector<unsigned char> converted;
    converted.reserve(_encodedMessage.size());

    auto countOfSpecialByteSymbol = std::count(
            _encodedMessage.begin(), _encodedMessage.end(), '=');

    if (countOfSpecialByteSymbol > 2) {
        throw std::exception(
                "special symbol must be appears max 2 times at the endl");
    }

    auto expectOnlySpecialSymbolsStringEndOfEncoded = _encodedMessage.substr(
            _encodedMessage.size() - countOfSpecialByteSymbol,
            countOfSpecialByteSymbol);

    for (const auto &c : expectOnlySpecialSymbolsStringEndOfEncoded)
        if (c != '=')
            throw std::exception(
                    "special symbol must be appears max 2 times at the endl");

    for (const auto& symbol : _encodedMessage) {
        if (symbol == '=') {
            converted.push_back(0);
        } else {
            converted.push_back(alphabet.GetIndexBySymbol(symbol));
        }
    }

    return std::move(std::make_pair(
            std::move(converted), countOfSpecialByteSymbol));
}

internal::Base64Alphabet::Base64Alphabet():
        alphabet("ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                 "abcdefghijklmnopqrstuvwxyz0123456789"),
        inverseAlphabet() {
    for (size_t i = 0; i < alphabet.size(); ++i) {
        inverseAlphabet[alphabet[i]] = i;
    }
}

unsigned char internal::Base64Alphabet::GetIndexBySymbol(
        unsigned char symbol) const {
    if (!inverseAlphabet.count(symbol)) {
        throw std::exception("Unknown symbol");
    }
    return inverseAlphabet.at(symbol);
}

unsigned char internal::Base64Alphabet::GetSymbolByIndex(
        unsigned char index) const {
    return alphabet[index];
}
