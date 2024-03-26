// Copyright 2024 Nogin Denis

#include "include/vigenere_cipher.h"

std::string vigenereCipher(std::string data, std::string key) {
    std::transform(key.begin(), key.end(), key.begin(),
                  [](unsigned char symbol){ return std::tolower(symbol); });
    std::string result;

        int lenKey = key.size();
        int lenData = data.size();
        int space = 0;

        for (int i = 0; i < lenData; ++i) {
            unsigned char new_symbol;
            if ((data[i] >= 65) && (data[i] <= 122) && ((data[i] <= 90) || (data[i] >= 97))) {
                new_symbol = data[i] + key[(i - space) % lenKey] - 97;
                if ((data[i] <= 90) && (data[i] >= 65)) {
                    while (new_symbol > 90) new_symbol -= 26;
                }
                else if ((data[i] <= 122) && (data[i] >= 97)) {
                    while (new_symbol > 122) new_symbol -= 26;
                }
            }
            else {
                ++space;
                new_symbol = data[i];
            }
            std::cout << data[i] << " " << key[(i - space) % lenKey]<< " " << new_symbol << std::endl;
            result += new_symbol;
        }
    std::cout << result << std::endl;
    return result;
}

std::string vigenereDecipher(std::string cipher, std::string key) {
    std::transform(key.begin(), key.end(), key.begin(),
                  [](unsigned char symbol){ return std::tolower(symbol); });
    std::string result;

    int lenKey = key.size();
    int lenCipher = cipher.size();
    int space = 0;

    for (int i = 0; i < lenCipher; ++i) {
        unsigned char new_symbol;
        if ((cipher[i] >= 65) && (cipher[i] <= 122) && ((cipher[i] <= 90) || (cipher[i] >= 97))) {
            new_symbol = cipher[i] - key[(i - space) % lenKey] + 97;
            if ((cipher[i] <= 90) && (cipher[i] >= 65)) {
                while (new_symbol < 65) new_symbol += 26;
            }
            else if ((cipher[i] <= 122) && (cipher[i] >= 97)) {
                while (new_symbol < 97) new_symbol += 26;
            }
        }
        else {
            ++space;
            new_symbol = cipher[i];
        }
        std::cout << cipher[i] << " " << key[(i - space) % lenKey]<< " " << new_symbol << std::endl;
        result += new_symbol;
    }
    std::cout << result << std::endl;

    return result;
}