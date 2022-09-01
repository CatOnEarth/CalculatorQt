#include "BigInt.h"

// конструткор по умолчанию
BigInt::BigInt() {
	this->isNeg = false;
	this->value = "0";
}

// конструктор из стандартного целого числа
BigInt::BigInt(long x) {
	this->isNeg = x < 0;
	this->value = std::to_string(isNeg ? -x : x);
}

// конструктор из строки
BigInt::BigInt(const std::string &value) {
	if (!value.length()) {
		this->value = "0";
		isNeg = false;

		return;
	}		

	isNeg = value[0] == '-';
	this->value = value.substr(isNeg);


	int count = 0;
	while (this->value[count] == '0' && this->value.length() - count > 1)
		count++;

	this->value = this->value.substr(count); // удаляем ведущие нули

	for(size_t i = 0; i < this->value.length(); i++)
		if (this->value[i] < '0' || this->value[i] > '9')
			throw u8"BigInt(const string &value) - string contain incorrect characters: " + this->value;
}

// конструктор копирования
BigInt::BigInt(const BigInt& bigInt) {
	this->value = bigInt.getValue();
	this->isNeg = bigInt.getIsNeg();
}

// получение строки со значением числа
const std::string &BigInt::getValue() const {
	return value;
}

// получение флага отрицательности числа
const bool BigInt::getIsNeg() const {
	return isNeg;
}

// изменение флага отрицательности числа
void BigInt::setIsNeg(bool isNeg) {
	this->isNeg = isNeg;
}

// получение знака числа
int BigInt::sign() const {
	return (1 - 2 * isNeg) * (value != "0");
}

// проверка на чётность
const bool BigInt::isEven() const {
	return (value[value.length() - 1] - '0') % 2 == 0;
}

// получение модуля числа
BigInt BigInt::abs() const {
	return BigInt(value);
}

// получение числа в степени n
BigInt BigInt::pow(long n) const {
    if (!n) {
		return 1;
    }

    if (n & 1) {
		return pow(n - 1) * *this;
    }
	else {
		BigInt tmp = pow(n / 2);
		return tmp * tmp;
	}
}

// проверка на равенство двух чисел
const bool BigInt::operator==(const BigInt &bigInt) const {
	return (value == bigInt.getValue()) && (isNeg == bigInt.getIsNeg());
}

// проверка на неравенство
const bool BigInt::operator!=(const BigInt &bigInt) const {
	return !(*this == bigInt);
}

// проверка, что число меньше
const bool BigInt::operator<(const BigInt &bigInt) const {
    std::string value2 = bigInt.getValue();
    size_t len1 = value.length();
    size_t len2 = value2.length();


	if (isNeg == bigInt.getIsNeg()) {

		if (len1 != len2) {
			return (len1 < len2) ^ isNeg;
		}
		size_t ii = 0;

		while (ii < len1 && value[ii] == value2[ii]) {
			++ii;
		}
		return (ii < len1) && ((value[ii] < value2[ii]) ^ isNeg);
	}

    return isNeg;
}

// проверка, что число больше bigInt
const bool BigInt::operator>(const BigInt &bigInt) const {
	return !(*this < bigInt || *this == bigInt);
}

// проверка, что число меньше или равно bigInt
const bool BigInt::operator<=(const BigInt &bigInt) const {
	return *this < bigInt || *this == bigInt;
}

// проверка, что число больше или равно bigInt
const bool BigInt::operator>=(const BigInt &bigInt) const {
	return *this > bigInt || *this == bigInt;
}

// операция присваивания
BigInt &BigInt::operator=(const BigInt &bigInt) {
	value = bigInt.getValue();
	isNeg = bigInt.getIsNeg();

	return *this;
}

// унарный минус, если было отрицательным, возвращаем положительное, иначе отрицательное
BigInt BigInt::operator-() const && {
	return BigInt(isNeg ? value : std::string("-") + value);
}

// унарный плюс (просто копируем значение числа)
BigInt BigInt::operator+() const && {
	return BigInt(*this);
}

// умножение методом Карацубы
BigInt BigInt::karatsuba_mul(const BigInt &a, const BigInt &b) {
    std::string v1 = a.getValue();
    std::string v2 = b.getValue();

    size_t len1 = v1.length();
    size_t len2 = v2.length();
    size_t len = std::max(len1, len2);

	if (len1 + len2 < 9) {
		return stol(a.getValue()) * stol(b.getValue());
	}

    len += len % 2;
    size_t n = len / 2;

    BigInt Xr(len1 > n ? v1.substr(len1 - n, n) : v1);
    BigInt Xl(a >> n);
    BigInt Yr(len2 > n ? v2.substr(len2 - n, n) : v2);
    BigInt Yl(b >> n);

    BigInt P1 = karatsuba_mul(Xl, Yl);
    BigInt P2 = karatsuba_mul(Xr, Yr); 
    BigInt P3 = karatsuba_mul(Xl + Xr, Yl + Yr);

    return (P1 << len) + ((P3 - P2 - P1) << n) + P2;
}


// бинарный плюс (сложение двух чисел)
BigInt BigInt::operator+(const BigInt& bigInt) const {
    bool isAddOp = !(bigInt.getIsNeg() ^ isNeg);

	if (isAddOp) {
        std::string num2 = bigInt.getValue();

        size_t len1 = value.length();
        size_t len2 = num2.length();
        size_t length = 1 + std::max(len1, len2);

		char* res = new char[length + 1];

		res[length - 1] = res[length] = '\0';

		for (size_t ii = 0; ii < length - 1; ++ii) {
			int jj = length - 1 - ii;
            res[jj] += ((ii < len2) ? (num2[len2 - 1 - ii] - '0') : 0) + ((ii < len1) ? (value[len1 - 1 - ii] - '0') : 0);
            res[jj - 1] = res[jj] / 10;
            res[jj] = res[jj] % 10 + '0';
		}

		res[0] += '0';

        return BigInt(isNeg ? std::string("-") + std::string(res) : std::string(res));
	}
	else {
        if (isNeg) {
			return bigInt - (-BigInt(*this));
		}
		else {
			return *this - (-BigInt(bigInt));
		}
	}
}

// бинарный минус (вычитание двух чисел)
BigInt BigInt::operator-(const BigInt &bigInt) const {
	if (*this == bigInt) {
        return 0;
	}

	if (!isNeg && !bigInt.getIsNeg()) {
        std::string value2 = bigInt.getValue();
		
        size_t len1 = value.length();
        size_t len2 = value2.length();
        size_t length = std::max(len1, len2);
		
        bool isNegRes = bigInt > *this;

		char* a = new char[length];
		char* b = new char[length];

        a[0] = b[0] = 0;

		char* res = new char[length + 1];

        res[length - 1] = res[length] = '\0';

        int sign = (2 * isNegRes - 1);
		for (size_t ii = 0; ii < length - 1; ++ii) {
			if (ii < len1) {
				a[ii] += value[len1 - 1 - ii] - '0';
			}
			else {
				a[ii] += 0;
			}

			if (ii < len2) {
				b[ii] += value2[len2 - 1 - ii] - '0';
			}
			else {
				b[ii] += 0;
			}

            b[ii + 1] = -isNegRes;
            a[ii + 1] = isNegRes- 1;

			res[length - 1 - ii] += 10 + sign * (b[ii] - a[ii]);
			res[length - 1 - ii - 1]  = res[length - 1 - ii] / 10;
			res[length - 1 - ii] = res[length - 1 - ii] % 10 + '0';
		}


		a[length - 1] += (length - 1 < len1) * (value[0] - '0');
		b[length - 1] += (length - 1 < len2) * (value2[0] - '0');


		res[0] += sign * (b[length - 1] - a[length - 1]) + '0';

        return BigInt(isNegRes ? std::string("-") + std::string(res) : std::string(res));
	}
    else {

		if (isNeg && bigInt.getIsNeg()) {
			return -BigInt(bigInt) - (-BigInt(*this));
		}
		else {
			return *this + -BigInt(bigInt);
		}
	}
}

// бинарная звёздочка (умножение двух чисел)
BigInt BigInt::operator*(const BigInt &bigInt) const {
	if (value == "0" || bigInt.getValue() == "0")
        return 0;

    std::string value2 = bigInt.getValue();
		
    size_t len1 = value.length();
    size_t len2 = value2.length();
    size_t length = len1 + len2 + 1;
    bool isNegRes = isNeg ^ bigInt.getIsNeg();
    if (length < 2000) {
		char* a = new char[length];
		char* b = new char[length];

		char* res = new char[length + 1];

		res[length] = '\0'; // устанавливаем символ окончания строки
		for (size_t ii = 0; ii < length; ++ii) {
			a[ii] = (ii < len1) ? (value[len1 - 1 - ii] - '0') : 0;
			b[ii] = (ii < len2) ? (value2[len2 - 1 - ii] - '0') : 0;
			res[ii] = 0;
		}

		// выполняем умножение "в столбик""
		for (size_t ii = 0; ii < len1; ++ii) {
		    for (size_t jj = 0; jj < len2; ++jj) {
		        res[length - 1 - (ii + jj)] += a[ii] * b[jj];
		        res[length - 1 - (ii + jj + 1)] += res[length - 1 - (ii + jj)] / 10;
			    res[length - 1 - (ii + jj)] %= 10;
		    }
		}

		for (size_t ii = 0; ii < length; ++ii) {
			res[length - 1 - ii] += '0';
		}

        return BigInt(isNegRes ? std::string("-") + std::string(res) : std::string(res));
	} else { // умножаем по методу Карацубы
        BigInt res = karatsuba_mul(*this, bigInt);
        return isNegRes ? -BigInt(res) : res;
	}
}

// бинарный слеш (деление двух чисел)
BigInt BigInt::operator/(const BigInt &bigInt) const {
	std::string value1 = value;
    std::string value2 = bigInt.getValue();

	if (value2[0] == '0') {
        throw u8"Division by zero!";
	}

	if (value[0] == '0') {
        return 0;
	}

	if (value2 == "1") {
        return BigInt(bigInt.getIsNeg() ? -BigInt(*this) : *this);
	}

	size_t zeroes = 0;
	while (value2[value2.length() - 1 - zeroes] == '0' && value[value.length() - 1 - zeroes] == '0') {
		zeroes++;
	}

	if (zeroes >= value.length()) {
		return 0;
	}

	// избавляемся от круглых чисел
	if (zeroes) {
		value1 = value1.substr(0, value1.length() - zeroes);
		value2 = value2.substr(0, value2.length() - zeroes);
	}

	bool isNegRes;
	if (isNeg && bigInt.getIsNeg()) {
		isNegRes = false;
	}
	else if (isNeg || bigInt.getIsNeg()) {
		isNegRes = true;
	}
	else {
		isNegRes = false;
	}

	BigInt tmp(value2);

    size_t divider_length = value2.length();
    long divider_v = divider_length > 8 ? 0 : atol(value2.c_str());

    size_t length = value1.length();
    size_t index = 0;

    std::string div;
    std::string v;

	while (BigInt(v) < tmp && index < length) {
		v += value1[index++];
	}

	do {
        int count = 0;
		if (BigInt(v) >= tmp) {
            if (divider_length > 8) {
				BigInt mod = v;
				while (mod >= tmp) {
					mod -= tmp;
					count++;
				}
				v = mod.getValue();
			} else {
				long mod = stol(v);
				count = mod / divider_v;
				v = std::to_string(mod % divider_v);
			}
		}
		
		div += count + '0'; // если не делили, то добавили ноль к результату, иначе добавили результат дедения

		if (index <= length) {
			v += value1[index++]; // формируем новое значение для подчисла
		}
	} while (index <= length);

    return BigInt(isNegRes && div != "0" ? std::string("-") + div : div);
}

// бинарный процент (операция взятия остатка от деления)
BigInt BigInt::operator%(const BigInt &bigInt) const {
	std::string value2 = bigInt.getValue();

	if (value2[0] == '0') {
		throw u8"Division by zero!";
	}

	if (value[0] == '0' || value2 == "1") {
		return 0;
	}

	if (value.length() < 9 && value2.length() < 9) {
		long res = stol(value) % stol(value2);
		return isNeg ? -res : res;
	}

	BigInt tmp(value2);

    size_t divider_length = value2.length();
    long divider_v = divider_length >= 9 ? 0 : atol(value2.c_str());

	size_t length = value.length();
	size_t index = 0;
	BigInt mod2 = value;
	std::string v;

	while (BigInt(v) < tmp && index < length)
		v += value[index++];

	do {
		if (BigInt(v) >= tmp) {
			if (divider_v) {
				v = std::to_string(stol(v) % divider_v);
			}
			else {
				BigInt mod = v;

				while (mod >= tmp) {
					mod -= tmp;
				}

				v = mod.getValue();
			}
		}

		if (index <= length) {
			mod2 = v;
			v += value[index++];				
		}
	} while (index <= length);

	if (mod2.getValue() == "0") {
		return 0;
	}

	return isNeg ? -BigInt(mod2) : mod2;
}

// краткая запись сложения
BigInt &BigInt::operator+=(const BigInt &bigInt) {
	return *this = *this + bigInt;
}

// краткая запись вычитания
BigInt &BigInt::operator-=(const BigInt &bigInt) {
	return *this = *this - bigInt;
}

// краткая запись умножения
BigInt &BigInt::operator*=(const BigInt &bigInt) {
	return *this = *this * bigInt;
}

// краткая запись деления
BigInt &BigInt::operator/=(const BigInt &bigInt) {
	return *this = *this / bigInt;
}

// краткая запись взятия остатка
BigInt &BigInt::operator%=(const BigInt &bigInt) {
	return *this = *this % bigInt;
}

// префиксная запись инкремента
BigInt &BigInt::operator++() {
	return *this = *this + 1;
}

// префиксная запись декремента
BigInt &BigInt::operator--() {
	return *this = *this - 1;
}

// постфиксная запись инкремента
BigInt BigInt::operator++(int) {
	BigInt res = *this;
	*this = *this + BigInt(1);	

	return res;
}

// постфиксная запись декремента
BigInt BigInt::operator--(int) {
	BigInt res = *this;
	*this = *this - BigInt(1);

	return res;
}

BigInt BigInt::operator<<(size_t n) const {
	return BigInt(std::string(isNeg ? "-" : "") + value + std::string(n, '0'));
}

BigInt BigInt::operator>>(size_t n) const {
	if (n >= value.length()) {
		return 0;
	}

	return BigInt(std::string(isNeg ? "-" : "") + value.substr(0, value.length() - n));
}
