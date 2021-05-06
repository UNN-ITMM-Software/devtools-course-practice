// Copyright 2021 Chistov Vladimir

#include "include/long_arithmetic.h"
#include <string>
#include <algorithm>

bigInt::bigInt() {
    this->negFlag = false;
}

bigInt::bigInt(std::string str) {
    if (str.length() == 0) {
        this->negFlag = false;
    } else {
        if (str[0] == '-') {
            str = str.substr(1);
            this->negFlag = true;
        } else {
            this->negFlag = false;
        }

        for (int i = str.length(); i > 0; i -= 9) {
            if (i < 9)
                this->storage.push_back(atoi(str.substr(0, i).c_str()));
            else
                this->storage.push_back(atoi(str.substr(i - 9, 9).c_str()));
        }

        this->delZeros();
    }
}

void bigInt::delZeros() {
    while (this->storage.size() > 1 && this->storage.back() == 0) {
        this->storage.pop_back();
    }

    if (this->storage.size() == 1 && this->storage[0] == 0) this->
        negFlag = false;
}

bool bigInt::operator==(const bigInt& right) const {
    bigInt left = *this;

    if (left.storage.empty()) {
        if (right.storage.empty() || (right.storage.size() == 1 &&
            right.storage[0] == 0)) return true;
        return false;
    }

    if (right.storage.empty()) {
        if (left.storage.size() == 1 && left.storage[0] == 0) return true;
        return false;
    }
    return left.storage == right.storage;
}

bigInt bigInt::operator -() const {
    bigInt copy(*this);
    copy.negFlag = !copy.negFlag;
    return copy;
}

bool bigInt::operator<(const bigInt& right) const {
    bigInt left = *this;
    if (left.negFlag) {
        if (right.negFlag) return ((-right) < (-left));
        return true;
    } else {
        if (right.negFlag) {
            return false;
        } else {
            if (left.storage.size() != right.storage.size()) {
                return left.storage.size() < right.storage.size();
            } else {
                for (int64_t i = left.storage.size() - 1; i >= 0; --i) {
                    if (left.storage[i] != right.storage[i]) return left.
                        storage[i] < right.storage[i];
                }
                return false;
            }
        }
    }
}

bool bigInt::operator!=(const bigInt& right) const {
    return !(*this == right);
}

bool bigInt::operator<=(const bigInt& right) const {
    return (*this < right || *this == right);
}

bool bigInt::operator>(const bigInt& right) const {
    return !(*this <= right);
}

bool bigInt::operator>=(const bigInt& right) const {
    return !(*this < right);
}

bigInt bigInt::operator+(const bigInt& right) const {
    bigInt left = *this;
    if (left.negFlag) {
        if (right.negFlag) return -(-left + (-right));
        return right - (-left);
    } else { if (right.negFlag) return left - (-right); }
    int carry = 0;
    for (size_t i = 0; i < std::max(left.storage.size(), right.
        storage.size()) || carry != 0; ++i) {
        if (i == left.storage.size()) left.storage.push_back(0);
        left.storage[i] += carry + (i < right.storage.size() ?
            right.storage[i] : 0);
        carry = left.storage[i] >= bigInt::BASE;
        if (carry != 0) left.storage[i] -= bigInt::BASE;
    }

    return left;
}

bigInt bigInt::operator -(const bigInt& right) const {
    bigInt left = *this;
    if (right.negFlag) return left + (-right);
    else if (left.negFlag) return -(-left + right);
    else if (left < right) return -(right - left);
    int carry = 0;
    for (size_t i = 0; i < right.storage.size() || carry != 0; ++i) {
        left.storage[i] -= carry + (i < right.storage.size() ? right.
            storage[i] : 0);
        carry = left.storage[i] < 0;
        if (carry != 0) left.storage[i] += bigInt::BASE;
    }

    left.delZeros();
    return left;
}

bigInt& bigInt::operator +=(const bigInt& value) {
    return *this = (*this + value);
}

bigInt& bigInt::operator -=(const bigInt& value) {
    return *this = (*this - value);
}

bigInt bigInt::operator++() {
    return (*this += bigInt(1));
}

bigInt bigInt::operator --() {
    return *this -= bigInt(1);
}

bigInt bigInt::operator ++(int i) {
    *this += bigInt(1);
    return *this - bigInt(1);
}

bigInt bigInt::operator --(int i) {
    *this -= bigInt(1);
    return *this + bigInt(1);
}

bigInt::bigInt(int i) {
    if (i < 0) this->negFlag = true;
    else
        this->negFlag = false;
    this->storage.push_back(std::abs(i) % bigInt::BASE);
    i /= bigInt::BASE;
    if (i != 0) this->storage.push_back(std::abs(i));
}

bigInt bigInt::operator*(const bigInt& right) const {
    bigInt result;
    bigInt left = *this;
    result.storage.resize(left.storage.size() + right.storage.size());
    for (size_t i = 0; i < left.storage.size(); ++i) {
        int carry = 0;
        for (size_t j = 0; j < right.storage.size() || carry != 0; ++j) {
            int64_t cur = result.storage[i + j] +
                left.storage[i] * 1LL * (j < right.storage.size() ? right.
                    storage[j] : 0) + carry;
            result.storage[i + j] = static_cast<int>(cur % bigInt::BASE);
            carry = static_cast<int>(cur / bigInt::BASE);
        }
    }

    result.negFlag = left.negFlag != right.negFlag;
    result.delZeros();
    return result;
}

bigInt bigInt::operator/(const bigInt& right) const {
    if (right == bigInt(0)) throw bigInt::devByZero();
    bigInt left = *this;
    bigInt b = right;
    b.negFlag = false;
    bigInt result, current;
    result.storage.resize(left.storage.size());
    for (int i = static_cast<int64_t>(left.storage.size())
        - 1; i >= 0; --i) {
        current.shiftRight();
        current.storage[0] = left.storage[i];
        current.delZeros();
        int x = 0, l = 0, r = bigInt::BASE;
        while (l <= r) {
            int m = (l + r) / 2;
            bigInt t = b * bigInt(m);
            if (t <= current) {
                x = m;
                l = m + 1;
            } else { r = m - 1; }
        }

        result.storage[i] = x;
        current = current - b * bigInt(x);
    }

    result.negFlag = left.negFlag != right.negFlag;
    result.delZeros();
    return result;
}

void bigInt::shiftRight() {
    if (this->storage.size() == 0) {
        this->storage.push_back(0);
        return;
    }
    this->storage.push_back(this->storage.back());
    for (size_t i = this->storage.size() - 2; i > 0; --i) this->storage[i] =
        this->storage[i - 1];
    this->storage[0] = 0;
}

bigInt& bigInt::operator *=(const bigInt& value) {
    return *this = (*this * value);
}

bigInt& bigInt::operator /=(const bigInt& value) {
    return *this = (*this / value);
}

bigInt bigInt::operator%(const bigInt& right) const {
    bigInt left = *this;
    bigInt result = left - (left / right) * right;
    if (result.negFlag) result += right;
    return result;
}

bool bigInt::odd() const {
    if (this->storage.size() == 0) return false;
    return this->storage[0] & 1;
}

bool bigInt::even() const {
    return !this->odd();
}

const bigInt bigInt::pow(bigInt n) const {
    bigInt a(*this), result(1), nul(0), del(2);
    while (n != nul) {
        if (n.odd()) result *= a;
        a *= a;
        n /= del;
    }

    return result;
}
