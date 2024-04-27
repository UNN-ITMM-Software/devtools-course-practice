// Copyright 2024 Sobol Lyubov

#ifndef MODULES_SOBOL_L_BITSET_LAB2_INCLUDE_TBITFIELD_H_
#define MODULES_SOBOL_L_BITSET_LAB2_INCLUDE_TBITFIELD_H_

#include <iostream>
#include <stdexcept>
#include <utility>

typedef unsigned char TELEM;
class TBitField {
 private:
  int  BitLen;  // длина битового поля - макс. к-во битов
  TELEM *pMem;  // память для представления битового поля
  int  MemLen;  // к-во эл-тов Мем для представления бит.поля

  // методы реализации
  int   GetMemIndex(const int n) const;  // индекс в pМем для бита n
  TELEM GetMemMask(const int n) const;  // битовая маска для бита n

 public:
  TBitField() = default;
  explicit TBitField(int len);
  TBitField(const TBitField &bf);
  TBitField(TBitField&& bf) noexcept;
  TBitField& operator=(TBitField&& bf) noexcept;
  ~TBitField();

  // доступ к битам
  int GetLength(void) const;      // получить длину (к-во битов)
  void SetBit(const int n);       // установить бит
  void ClrBit(const int n);       // очистить бит
  int  GetBit(const int n) const;  // получить значение бита

  // битовые операции
  int operator==(const TBitField &bf) const;  // сравнение
  int operator!=(const TBitField &bf) const;  // сравнение
  TBitField& operator=(const TBitField &bf);  // присваивание
  TBitField  operator|(const TBitField &bf);  // операция "или"
  TBitField  operator&(const TBitField &bf);  // операция "и"
  TBitField  operator~(void);                 // отрицание

  friend std::istream &operator>>(std::istream &istr, TBitField &bf);
  friend std::ostream &operator<<(std::ostream &ostr, const TBitField &bf);

  friend void swap(TBitField& lhs, TBitField& rhs) noexcept {
      std::swap(lhs.BitLen, rhs.BitLen);
      std::swap(lhs.MemLen, rhs.MemLen);
      std::swap(lhs.pMem, rhs.pMem);
  }
  TBitField CreateBitField(int buff) {
      TBitField retBuff(buff);
      return retBuff;
  }
};

// Структура хранения битового поля
//   бит.поле - набор битов с номерами от 0 до BitLen
//   массив pМем рассматривается как последовательность MemLen элементов
//   биты в эл-тах pМем нумеруются справа налево (от младших к старшим)

#endif  // MODULES_SOBOL_L_BITSET_LAB2_INCLUDE_TBITFIELD_H_
