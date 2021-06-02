// Copyright 2021 Gushchin Artem

#include "include/bit_array.h"

BitArray::BitArray(int len) {
    if (len <= 0)
        throw "Length should be a positive number";

    BitLen = len;
    MemLen = (BitLen + 31) / 32;
    pMem = new uint[MemLen];

    for (int i = 0; i < MemLen; i++)
        pMem[i] = 0;
}

BitArray::BitArray(const BitArray &bf) {
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    pMem = new uint[MemLen];

    for (int i = 0; i < MemLen; i++)
        pMem[i] = bf.pMem[i];
}

BitArray::~BitArray() {
    BitLen = 0;
    delete[] pMem;
}

int BitArray::GetMemIndex(const int n) const {
    return n / 32;
}

uint BitArray::GetMemMask(const int n) const {
    return 1 << (n % 32);
}

int BitArray::GetLength(void) const {
    return BitLen;
}

void BitArray::SetBit(const int n) {
    if (n < 0)
        throw "Bit number should be positive";
    if (n > BitLen)
        throw "Bit number should be lower than overall number of bits";

    pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void BitArray::ClrBit(const int n) {
    if (n < 0)
        throw "Bit number should be positive";
    if (n > BitLen)
        throw "Bit number should be lower than overall number of bits";

    pMem[GetMemIndex(n)] &= ~GetMemMask(n);
}

int BitArray::GetBit(const int n) const {
    if (n < 0)
        throw "Bit number should be positive";
    if (n > BitLen)
        throw "Bit number should be lower than overall number of bits";

    unsigned int ret = pMem[GetMemIndex(n)] & GetMemMask(n);

    if (ret)
        return 1;
    else
        return 0;
}

BitArray& BitArray::operator=(const BitArray &bf) {
    if (BitLen != bf.BitLen) {
        BitLen = bf.BitLen;
        MemLen = bf.MemLen;
        delete[] pMem;
        pMem = new uint[MemLen];
    }

    for (int i = 0; i < MemLen; i++)
        pMem[i] = bf.pMem[i];

    return *this;
}

bool BitArray::operator==(const BitArray &bf) const {
    if (MemLen == bf.MemLen) {
        for (int i = 0; i < MemLen; i++)
            if (pMem[i] != bf.pMem[i])
                return false;
    } else if (bf.MemLen < MemLen) {
        for (int i = 0; i < bf.MemLen; i++)
            if (pMem[i] != bf.pMem[i])
                return false;
        for (int i = bf.MemLen; i < MemLen; i++)
            if (pMem[i])
                return false;
    } else if (bf.MemLen > MemLen) {
        for (int i = 0; i < MemLen; i++)
            if (pMem[i] != bf.pMem[i])
                return false;
        for (int i = MemLen; i < bf.MemLen; i++)
            if (bf.pMem[i])
                return false;
    }

    return true;
}

bool BitArray::operator!=(const BitArray &bf) const {
    return !operator==(bf);
}

BitArray BitArray::operator|(const BitArray &bf) {
    int NewLen = BitLen > bf.BitLen ? BitLen : bf.BitLen;
    BitArray ret(NewLen);

    if (MemLen > bf.MemLen) {
        for (int i = 0; i < bf.MemLen; i++)
            ret.pMem[i] = pMem[i] | bf.pMem[i];
        for (int i = bf.MemLen; i < MemLen; i++)
            ret.pMem[i] = pMem[i];
    } else if (MemLen < bf.MemLen) {
        for (int i = 0; i < MemLen; i++)
            ret.pMem[i] = pMem[i] | bf.pMem[i];
        for (int i = MemLen; i < bf.MemLen; i++)
            ret.pMem[i] = bf.pMem[i];
    } else {
        for (int i = 0; i < MemLen; i++)
            ret.pMem[i] = pMem[i] | bf.pMem[i];
    }

    return ret;
}

BitArray BitArray::operator&(const BitArray &bf) {
    int NewLen = BitLen > bf.BitLen ? BitLen : bf.BitLen;
    BitArray ret(NewLen);

    if (MemLen > bf.MemLen) {
        for (int i = 0; i < bf.MemLen; i++)
            ret.pMem[i] = pMem[i] & bf.pMem[i];
        for (int i = bf.MemLen; i < MemLen; i++)
            ret.pMem[i] = 0;
    } else if (MemLen < bf.MemLen) {
        for (int i = 0; i < MemLen; i++)
            ret.pMem[i] = pMem[i] & bf.pMem[i];
        for (int i = MemLen; i < bf.MemLen; i++)
            ret.pMem[i] = 0;
    } else {
        for (int i = 0; i < MemLen; i++)
            ret.pMem[i] = pMem[i] & bf.pMem[i];
    }

    return ret;
}

BitArray BitArray::operator~(void) {
    BitArray ret(BitLen);

    for (int i = 0; i < BitLen; i++) {
        if (GetBit(i))
            ret.ClrBit(i);
        else
            ret.SetBit(i);
    }

    return ret;
}
