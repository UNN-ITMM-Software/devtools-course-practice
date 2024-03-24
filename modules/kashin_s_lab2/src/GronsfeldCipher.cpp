// Copyright 2024 Kashin Stepa

#include "include/GronsfeldCipher.h"

char GronsfeldCipher::encode_char(char word, char code) const {
    if ('a' <= word && word <= 'z') {
        word = first + (word - first + code - first) % alfabet;
    }
    return word;
}

char GronsfeldCipher::decoder_char(char word, char code) const {
    if ('a' <= word && word <= 'z') {
        word =  first + (word - code + 'z' + 1 - first) % 26;
    }
    return word;
}

char GronsfeldCipher::crackLetter(std::string line) {
    std::vector<double> letters(alfabet);
    for (size_t letter = 0; letter < letters.size(); letter++) {
        for (char a : line) {
            letters[letter] += letterFrequency[decoder_char(a, first + letter)];
        }
    }
    int maxIndex = std::distance(
        letters.begin(),
        std::max_element(letters.begin(), letters.end()));
    return first + maxIndex;
}

GronsfeldCipher::GronsfeldCipher(std::string keyWord) {
    setKey(keyWord);
}

std::string GronsfeldCipher::getKey() {
    return key;
}

void GronsfeldCipher::setKey(std::string keyWord) {
    if (keyWord == "") throw TheStringDoesNotContainCharacters();
    for (size_t i = 0; i < keyWord.length(); i++) {
        keyWord[i] = tolower(keyWord[i]);
        if (!('a' <= keyWord[i] && keyWord[i] <= 'z')) {
            throw TheStringContainsNonLatinCharacters();
        }
    }
    key = keyWord;
}

std::string GronsfeldCipher::encoder(std::string text) {
    if (text == "") throw TheStringDoesNotContainCharacters();
    std::string answer = "";
    for (size_t i = 0; i < text.length(); i++) {
        answer += encode_char(tolower(text[i]), key[i % key.length()]);
    }
    return answer;
}

std::string GronsfeldCipher::decoder(std::string text) {
    if (text == "") throw TheStringDoesNotContainCharacters();
    std::string answer = "";
    for (size_t i = 0; i < text.length(); i++) {
        answer += decoder_char(tolower(text[i]), key[i % key.length()]);
    }
    return answer;
}

std::string GronsfeldCipher::getCrackKey(std::string text, size_t keySize) {
    if (text == "") throw TheStringDoesNotContainCharacters();
    if (1 > keySize || text.length() < keySize) throw IncorrectKeyLength();

    std::string lines[keySize], newKey = "";
    for (size_t i = 0; i < text.length(); i++) {
        if ('a' <= tolower(text[i]) && tolower(text[i]) <= 'z') {
            lines[i % keySize] += tolower(text[i]);
        }
    }
    for (std::string line : lines) {
        newKey += crackLetter(line);
    }
    return  newKey;
}
