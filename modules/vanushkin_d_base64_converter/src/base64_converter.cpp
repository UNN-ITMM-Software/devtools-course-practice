// Copyright 2024 Vanushkin Dmitry

#include <algorithm>
#include <unordered_map>
#include <stdexcept>
#include "include/base64_converter.h"

Base64Encoder::Base64Encoder(const std::string &message) : _message(message) {}

// Конвертирует сообщение (с кодировкой ASCII без расширения)
// в формат base64
// Реализация:
//  разбиваем байты сообщения на блоки размера по 6 бит
//  каждый такой блок, в численной интерпретации
//  представляет собой число в диапазоне от 0..63,
//  преобразуем каждый такой блок в символ кодирующего
//  алфавита (A-Za-z0-9) (блок выступает индексом)
//  получаем в итоге закодированное сообщение из
//  преобразованных символов
std::string Base64Encoder::Encode() const {
    auto buffer = ConvertStringToBytesByAddingEmptyBytes();
    auto addedEmptyBytes = buffer.size() - _message.size();

    auto sixthsCount = (buffer.size() * 8) / 6;

    auto encodedMessage = std::vector<unsigned char>();
    encodedMessage.reserve(sixthsCount);

    for (size_t sixthIndex = 0; sixthIndex < sixthsCount; ++sixthIndex) {
        auto number = InterpretSixthBitsGroupToUChar(buffer, sixthIndex);

        encodedMessage.push_back(internal::Base64Alphabet::GetInstance()
            .GetSymbolByIndex(number));
    }

    // Пустые байты кодируются символом =
    for (size_t i = 0; i < addedEmptyBytes; ++i) {
        encodedMessage[encodedMessage.size() - 1 - i] = '=';
    }

    // Создаём строку из вектора символов
    return {encodedMessage.cbegin(), encodedMessage.cend()};
}

// Преобразует сообщение в набор символов,
// добавляя необходимое количество нулевых байтов в конец,
// такое, чтобы общее число бит было кратно 6,
// откуда следует, что сумма n + k должна делится на 3,
// где n - число символов в сообщении (число байт),
// k - необходимое для делимости нулевые байты
std::vector<char> Base64Encoder
    ::ConvertStringToBytesByAddingEmptyBytes() const {
    auto remainder = _message.size() % 3;
    auto emptyBytesNeeded = (3 - remainder) % 3;

    std::vector<char> buffer(_message.cbegin(), _message.cend());

    buffer.reserve(emptyBytesNeeded);
    while (emptyBytesNeeded--) {
        buffer.push_back(0);
    }

    return buffer;
}

// Преобразует группу из 6ти битов в число, по заданному
// индексу группы и выровненному набору байтов сообщения
// 8 - размер байта в битах (кто не знал)
unsigned char Base64Encoder::InterpretSixthBitsGroupToUChar(
        const std::vector<char>& vector, size_t sixthIndex) const {
    auto startByteIndex = (6 * sixthIndex) / 8;
    auto startBitIndex = (6 * sixthIndex) % 8;

    auto endBitIndex = (startBitIndex + 6 - 1) % 8;

    auto startByte = vector[startByteIndex];

    // Шестёрка битов полностью содержится в байте
    if (endBitIndex > startBitIndex) {
        // Смещаем байт к концу, удаляя последние 2 - startBitIndex битов
        auto part = (unsigned char) (startByte >> (2 - startBitIndex));

        // Set first and second bits of part to zero, 192 is 0x0011 11111
        return part & ~192;
    }

    // Шестёрка содержится в соседних байтах
    // Достаём часть из первого байта, выравниваем до двух нулевых битов слева
    auto highestPart = ((unsigned char)(startByte << startBitIndex))
            >> (startBitIndex - 1 - endBitIndex);

    // Достаём часть из второго байта, выравнивая по правому краю
    auto lowestPart = vector[startByteIndex + 1] >> (7 - endBitIndex);

    return highestPart + lowestPart;
}

Base64Decoder::Base64Decoder(const std::string &encodedMessage) :
    _encodedMessage(encodedMessage) {}

// Конвертирует сообщение в формате base64 в исходное сообщение
// Реализация:
//  каждый байт интерпретируем,
//  как символ кодирующего алфавита (A-Za-z0-9), преобразуя байт
//  в индекс символа из этого алфавита,
//  получаем новый набор байт, в котором у каждого байта
//  первые два символа - нулевые, т.е. 6 существенных битов
//  преобразуем сообщение в новый набор байтов, игнорируя
//  у каждого исходного байта первые два бита
//  конвертируем набор байтов в строку
std::string Base64Decoder::Decode() const {
    // Чтобы сообщение могло быть декодированно, существенно число бит
    // (игрорируя первые два у каждого байта) должно делится на 8
    // (8 - 2)k ⋮ 8 => 3k ⋮ 4
    auto alsoBytesNeedToDecode = (3 * _encodedMessage.size()) % 4;

    if (alsoBytesNeedToDecode != 0) {
        auto message = "Encoded message must as least have "
                + std::to_string(alsoBytesNeedToDecode)
                + " bytes to decode";
        throw std::runtime_error(message);
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
        throw std::runtime_error(
                "special symbol must be appears max 2 times at the endl");
    }

    auto expectOnlySpecialSymbolsStringEndOfEncoded = _encodedMessage.substr(
            _encodedMessage.size() - countOfSpecialByteSymbol,
            countOfSpecialByteSymbol);

    for (const auto &c : expectOnlySpecialSymbolsStringEndOfEncoded)
        if (c != '=')
            throw std::runtime_error(
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
        throw std::runtime_error("Unknown symbol");
    }
    return inverseAlphabet.at(symbol);
}

unsigned char internal::Base64Alphabet::GetSymbolByIndex(
        unsigned char index) const {
    return alphabet[index];
}
