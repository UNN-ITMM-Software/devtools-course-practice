// Copyright 2021 Gushchin Artem

#ifndef MODULES_BIT_ARRAY_INCLUDE_BIT_ARRAY_H_
#define MODULES_BIT_ARRAY_INCLUDE_BIT_ARRAY_H_

#include <iostream>

using uint = unsigned int;

class BitArray {
 private:
    int     BitLen;
    uint*   pMem;
    int     MemLen;

    int GetMemIndex(const int n) const;
    uint GetMemMask(const int n) const;

 public:
    explicit BitArray(int len);
    BitArray(const BitArray& bf);
    ~BitArray();

    int GetLength(void) const;
    void SetBit(const int n);
    void ClrBit(const int n);
    int  GetBit(const int n) const;

    bool operator==(const BitArray& bf) const;
    bool operator!=(const BitArray& bf) const;
    BitArray& operator=(const BitArray& bf);
    BitArray  operator|(const BitArray& bf);
    BitArray  operator&(const BitArray& bf);
    BitArray  operator~(void);
};

#endif  // MODULES_BIT_ARRAY_INCLUDE_BIT_ARRAY_H_
