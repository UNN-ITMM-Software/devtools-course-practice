// Copyright 2024 Kashin Stepa

#include "include/GronsfeldCipher.h"

char GronsfeldCipher::encode_char(char word, char code) const {
    if (isLetterInAlphabet(word)) {
        word = firstLetter + (word - firstLetter + code - firstLetter) % alfabetSize;
    }
    return word;
}

char GronsfeldCipher::decoder_char(char word, char code) const {
    if (isLetterInAlphabet(word)) {
        word =  firstLetter + (word - code + lastLetter + 1 - firstLetter) % alfabetSize;
    }
    return word;
}

bool GronsfeldCipher::isLetterInAlphabet(char symbol) const{
    return !(letterFrequency.find(symbol) == letterFrequency.end());
}

char GronsfeldCipher::crackLetter(std::string line) {
    std::vector<double> letters(alfabetSize);
    for (size_t letter = 0; letter < letters.size(); letter++) {
        for (char a : line) {
            letters[letter] += letterFrequency.at(
                decoder_char(a, static_cast<char>(firstLetter + letter)));
        }
    }
    int maxIndex = std::distance(
        letters.begin(),
        std::max_element(letters.begin(), letters.end()));
    return firstLetter + maxIndex;
}

GronsfeldCipher::GronsfeldCipher(std::string keyWord) {
    setKey(keyWord);
}

std::string GronsfeldCipher::getKey() {
    return key;
}

void GronsfeldCipher::setKey(std::string keyWord) {
    if (keyWord.empty()) throw TheStringDoesNotContainCharacters();
    for (size_t i = 0; i < keyWord.length(); i++) {
        keyWord[i] = tolower(keyWord[i]);
        if (!(firstLetter <= keyWord[i] && keyWord[i] <= lastLetter)) {
            throw TheStringContainsNonLatinCharacters();
        }
    }
    key = keyWord;
}

std::string GronsfeldCipher::encoder(std::string text) {
    if (text.empty()) throw TheStringDoesNotContainCharacters();
    std::string answer = "";
    for (size_t i = 0; i < text.length(); i++) {
        answer += encode_char(tolower(text[i]), key[i % key.length()]);
    }
    return answer;
}

std::string GronsfeldCipher::decoder(std::string text) {
    if (text.empty()) throw TheStringDoesNotContainCharacters();
    std::string answer{};
    for (size_t i = 0; i < text.length(); i++) {
        answer += decoder_char(tolower(text[i]), key[i % key.length()]);
    }
    return answer;
}

std::string GronsfeldCipher::getCrackKey(std::string text, size_t keySize) {
    if (text.empty()) throw TheStringDoesNotContainCharacters();
    if (1 > keySize || text.length() < keySize) throw IncorrectKeyLength();

    std::vector<std::string> lines(keySize);
    std::string newKey{};
    for (size_t i = 0; i < text.size(); i++) {
        if (isLetterInAlphabet(tolower(text[i]))) {
            lines[i % keySize] += tolower(text[i]);
        }
    }
    for (std::string line : lines) {
        newKey += crackLetter(line);
    }
    return  newKey;
}
