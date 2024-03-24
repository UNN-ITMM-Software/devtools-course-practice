//
// Created by Стёпа Кашин on 24.03.2024.
//

#include "include/GronsfeldCipher.h"

char GronsfeldCipher::encode_char(char word, char code) const {
    if ('a' <= word && word <= 'z') {
        word = first + (word - first + code - first) % alfabet;
    }
    return word;
}

char GronsfeldCipher::decoder_char(char word, char code) const {
    if ('a' <= word && word <= 'z') {
        word =  first + (word - code + 'z' + 1 - first) % 26 ;
    }
    return word;
}

char GronsfeldCipher::crackLetter(string line) {
    vector<double> letters(alfabet);
    for (int letter = 0; letter < letters.size(); letter++) {
        for (char a: line) {
            letters[letter] += letterFrequency[decoder_char(a, first + letter)];
        }
    }
    int maxIndex = distance(letters.begin(), max_element(letters.begin(), letters.end()));
    return first + maxIndex;
}

GronsfeldCipher::GronsfeldCipher(string keyWord) {
    setKey(keyWord);
}

string GronsfeldCipher::getKey() {
    return key;
}

void GronsfeldCipher::setKey(string keyWord) {
    if (keyWord == "") throw TheStringDoesNotContainCharacters();
    for (int i = 0; i < keyWord.length(); i++) {
        keyWord[i] = tolower(keyWord[i]);
        if (!('a' <= keyWord[i] && keyWord[i] <= 'z')) {
            throw TheStringContainsNonLatinCharacters();
        }
    }
    key = keyWord;
}

string GronsfeldCipher::encoder(string text) {
    if (text == "") throw TheStringDoesNotContainCharacters();
    string answer = "";
    for (int i = 0; i < text.length(); i++) {
        answer += encode_char(tolower(text[i]), key[i % key.length()]);
    }
    return answer;
}

string GronsfeldCipher::decoder(string text) {
    if (text == "") throw TheStringDoesNotContainCharacters();
    string answer = "";
    for (int i = 0; i < text.length(); i++) {
        answer += decoder_char(tolower(text[i]), key[i % key.length()]);
    }
    return answer;
}

string GronsfeldCipher::getCrackKey(string text, int keySize) {
    if (text == "") throw TheStringDoesNotContainCharacters();
    if (1 > keySize || text.length() < keySize) throw IncorrectKeyLength();

    string lines[keySize], newKey = "";
    for (int i = 0; i < text.length(); i++) {
        if ('a' <= tolower(text[i]) && tolower(text[i]) <= 'z') lines[i % keySize] += tolower(text[i]);
    }
    for (string line: lines) {
        newKey += crackLetter(line);
    }
    return  newKey;
}
