#ifndef BIGNUM_H
#define BIGNUM_H

#include <string>
#include <iostream>
#define MAX_LENGTH 100

class BigNum{
	public:
        BigNum();
        BigNum(int const );
        BigNum(std::string const &);
        BigNum operator+(const BigNum &) const;
        BigNum operator-(const BigNum &) const;
        BigNum operator*(const BigNum &) const;
        BigNum& operator++();
        BigNum operator++(int);
        friend std::ostream &operator<<(std::ostream &,const BigNum &);
        friend std::istream &operator>>(std::istream &, BigNum &);
        friend BigNum sub(BigNum r, BigNum l);
	private:
        int digit[MAX_LENGTH];
        bool positivity;
//Add data feild here to save the data of BigNum.
//Add additional member or global functions to help you set up the class.
};
BigNum sub(BigNum r, BigNum l);
std::ostream &operator<<(std::ostream &,const BigNum &);
std::istream &operator>>(std::istream &, BigNum &);
BigNum operator+(const BigNum &, const int);
BigNum operator+(const int, const BigNum &);
BigNum operator-(const BigNum &, const int);
BigNum operator-(const int, const BigNum &);
BigNum operator*(const BigNum &, const int);
BigNum operator*(const int, const BigNum &);


#endif
