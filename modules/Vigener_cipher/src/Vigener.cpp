// Copyright 2021 Bezrodnov Dmitry

#include<string>
#include"include/Vigener.h"

void Vigener_cipher::set_key(const std::string& _key) {
    key = _key;
}

std::string Vigener_cipher::get_key() const {
    return key;
}

std::string Vigener_cipher::encrypt(const std::string& str_input) {
    if (key != "") {
        std::string str_input_corr = correct(str_input);
        std::string str_key = get_key_string(str_input_corr, key);
        //  Зашифровать
        std::string str_output(str_input_corr);
        int length = static_cast<int>(str_input_corr.length());
        for (int i = 0; i < length; i++) {
            if (str_input_corr[i] == ' ') {
                str_output[i] = ' ';
            } else {
                char first_symbol = 'a';
                int code_symbol = static_cast<int>(first_symbol);
                int code_curr = static_cast<int>(str_input_corr[i])-code_symbol;
                int code_key = static_cast<int>(str_key[i]) - code_symbol;
                str_output[i] = static_cast<char>(((code_curr + code_key)
                                            % length_abc) + code_symbol);
            }
        }
        return str_output;
    } else {
        return str_input;
    }
}

std::string Vigener_cipher::decrypt(const std::string& str_input) {
    if (key != "") {
        std::string str_key = get_key_string(str_input, key);
        //  Расшифровать
        std::string str_output(str_input);
        int length = static_cast<int>(str_input.length());
        for (int i = 0; i < length; i++) {
            if (str_input[i] == ' ') {
                str_output[i] = ' ';
            } else {
                char first_symbol = 'a';
                int code_symbol = static_cast<int>(first_symbol);
                int code_curr = static_cast<int>(str_input[i])-code_symbol;
                int code_key = static_cast<int>(str_key[i]) - code_symbol;
                str_output[i] = static_cast<char>(((code_curr + length_abc
                        - code_key) % length_abc) + code_symbol);
            }
        }
        return str_output;
    } else {
        return str_input;
    }
}

std::string Vigener_cipher::correct(const std::string& str_input) {
    std::string str_output(str_input);
    int code_A = static_cast<int>('A');
    int code_Z = static_cast<int>('Z');
    int length = static_cast<int>(str_input.length());
    for (int i = 0, corr = 0; i < length; i++, corr = 0) {
        int code_elem = static_cast<int>(str_input[i]);
        if ((code_elem >= code_A) && (code_elem <= code_Z))
            corr = 32;
        str_output[i] = static_cast<char>(code_elem + corr);
    }
    return str_output;
}

std::string Vigener_cipher::get_key_string(const std::string& _message,
                                           const std::string& _key) {
    int length = static_cast<int>(_message.length());
    std::string str_key(_message);
    for (int i = 0, j = 0; i < length; i++) {
        if (_message[i] == ' ') {
            str_key[i] = ' ';
            continue;
        }
        int length_key = static_cast<int>(key.length());
        str_key[i] = key[j % length_key];
        j++;
    }
    return str_key;
}
