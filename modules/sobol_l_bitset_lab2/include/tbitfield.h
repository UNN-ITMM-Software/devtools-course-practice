// Copyright 2024 Sobol Liubov

#ifndef MODULES_SOBOL_L_BITSET_LAB2_INCLUDE_TBITFIELD_H_
#define MODULES_SOBOL_L_BITSET_LAB2_INCLUDE_TBITFIELD_H_

#include <iostream>

//using namespace std;

typedef unsigned int TELEM;

class TBitField {

private:
  int  BitLen;  // длина битового поля - макс. к-во битов
  TELEM *pMem;  // память для представления битового поля
  int  MemLen;  // к-во эл-тов Мем для представления бит.поля

  // методы реализации
  int   GetMemIndex(const int n) const;  // индекс в pМем для бита n       (#О2)
  TELEM GetMemMask(const int n) const;  // битовая маска для бита n       (#О3)

public:
  explicit TBitField(int len);        //                                   (#О1)
  TBitField(const TBitField &bf);    //                                   (#П1)
  ~TBitField();                      //                                    (#С)

  // доступ к битам
  int GetLength(void) const;      // получить длину (к-во битов)           (#О)
  void SetBit(const int n);       // установить бит                       (#О4)
  void ClrBit(const int n);       // очистить бит                         (#П2)
  int  GetBit(const int n) const;  // получить значение бита               (#Л1)

  // битовые операции
  int operator==(const TBitField &bf) const;  // сравнение                 (#О5)
  int operator!=(const TBitField &bf) const;  // сравнение
  TBitField& operator=(const TBitField &bf);  // присваивание              (#П3)
  TBitField  operator|(const TBitField &bf);  // операция "или"            (#О6)
  TBitField  operator&(const TBitField &bf);  // операция "и"              (#Л2)
  TBitField  operator~(void);                 // отрицание                  (#С)

  friend std::istream &operator>>(std::istream &istr, TBitField &bf);       //      (#О7)
  friend std::ostream &operator<<(std::ostream &ostr, const TBitField &bf); //      (#П4)
};
// Структура хранения битового поля
//   бит.поле - набор битов с номерами от 0 до BitLen
//   массив pМем рассматривается как последовательность MemLen элементов
//   биты в эл-тах pМем нумеруются справа налево (от младших к старшим)

#endif
