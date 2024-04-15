// Copyright 2024 Lesnikov Nikita

#pragma once

#include <vector>
#include <cstdint>
#include <string>

#define TYPE uint8_t
#define BIG_TYPE int32_t

class LongNumber
{
public:
	LongNumber();
	LongNumber(const LongNumber& n);
	LongNumber(LongNumber&& n) noexcept;
	LongNumber(std::string s);
	LongNumber& operator=(const LongNumber& n);
	LongNumber& operator=(LongNumber&& n) noexcept;
	LongNumber operator+(const LongNumber& n) const;
	void operator+=(const LongNumber& n);
	LongNumber operator-(const LongNumber& n) const;
	void operator-=(const LongNumber& n);
	LongNumber operator*(const LongNumber& n);
	void operator*=(const LongNumber& n);
	LongNumber operator-() const;
	bool operator==(const LongNumber& n) const;
	bool operator!=(const LongNumber& n) const;
	bool operator<(const LongNumber& n) const;
	bool operator>(const LongNumber& n) const;
	bool operator<=(const LongNumber& n) const;
	bool operator>=(const LongNumber& n) const;

	std::string getString() const;
	
private:

	bool _absIsLess(const LongNumber& n) const;
	bool _absIsGreater(const LongNumber& n) const;
	bool _absIsEqual(const LongNumber& n) const;
	static void _checkZero(LongNumber& n);
	static BIG_TYPE _getMaxTypeValue();
	
	std::vector<TYPE> _data;
	bool _negative = false;
};
