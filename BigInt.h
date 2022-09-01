#ifndef BIG_INT_H
#define BIG_INT_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class BigInt {
	std::string value;
	bool isNeg; 

    static BigInt karatsuba_mul(const BigInt &a, const BigInt &b);

public:
    BigInt(); // конструктор
    BigInt(long x);
	BigInt(const std::string &value);
	BigInt(const BigInt& bigInt);

    const std::string &getValue() const;

    const bool getIsNeg() const;
    void setIsNeg(bool isNeg);

    int sign() const;
    const bool isEven() const;

    BigInt abs() const;
    BigInt pow(long n) const;

	// операции сравнения
	const bool operator==(const BigInt &bigInt) const;
	const bool operator!=(const BigInt &bigInt) const;

	const bool operator<(const BigInt &bigInt) const;
	const bool operator>(const BigInt &bigInt) const;
	const bool operator<=(const BigInt &bigInt) const;
	const bool operator>=(const BigInt &bigInt) const;

	// операция присваивания
	BigInt &operator=(const BigInt &bigInt);

	// унарные плюс и минус
	BigInt operator+() const &&;
	BigInt operator-() const &&;

	// арифметические операции
	BigInt operator+(const BigInt &bigInt) const;
	BigInt operator-(const BigInt &bigInt) const;
	BigInt operator*(const BigInt &bigInt) const;
	BigInt operator/(const BigInt &bigInt) const;
	BigInt operator%(const BigInt &bigInt) const;

	// краткая форма операций
	BigInt &operator+=(const BigInt &bigInt);
	BigInt &operator-=(const BigInt &bigInt);
	BigInt &operator*=(const BigInt &bigInt);
	BigInt &operator/=(const BigInt &bigInt);
	BigInt &operator%=(const BigInt &bigInt);

	BigInt operator<<(size_t n) const;
	BigInt operator>>(size_t n) const;

	// префиксная форма
    BigInt &operator++(); // ++ii
    BigInt &operator--(); // --ii

	// постфиксная форма
    BigInt operator++(int); // ii++
    BigInt operator--(int); // ii--

};

#endif
