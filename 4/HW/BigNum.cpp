#include <bits/stdc++.h>
#include "BigNum.h"

BigNum::BigNum(){
    for(int cnt=0;cnt<MAX_LENGTH;cnt++)
        digit[cnt]=0;
    positivity=true;
}

BigNum::BigNum(int const input){
    if(input<0)
        positivity=false;
    else
        positivity=true;
    int temp=abs(input);
    for(int cnt=0;cnt<MAX_LENGTH;cnt++){
        if(temp){
            digit[cnt]=temp%10;
            temp/=10;
            continue;
        }
        digit[cnt]=0;
    }
}

BigNum::BigNum(std::string const& input){
    if(input[0]=='-') positivity=false;
    else positivity=true;
    int siz=input.size();
    int start=positivity?0:1;
    memset(digit,0,MAX_LENGTH*sizeof(int));
    for(int cnt=start;cnt<MAX_LENGTH;cnt++)
        if(cnt<siz)
            digit[siz-1-cnt]=input[cnt]-'0';
}

BigNum BigNum::operator*(BigNum const& right)const{
    BigNum output;
    output.positivity=!(positivity^right.positivity);
    for(int cnt=0;cnt<MAX_LENGTH;cnt++)
    for(int cnt2=0;cnt2<MAX_LENGTH;cnt2++)
        output.digit[cnt+cnt2]+=digit[cnt]*right.digit[cnt2];
    for(int cnt=0;cnt<MAX_LENGTH-1;cnt++)
        if(output.digit[cnt]>9){
            int temp=output.digit[cnt]/10;
            output.digit[cnt]-=10*temp;
            output.digit[cnt+1]+=temp;
        }
    return output;
}

BigNum BigNum::operator+(BigNum const& right)const{
    BigNum output;
    if(!(positivity^right.positivity)){
        output.positivity=positivity;
        for(int cnt=0;cnt<MAX_LENGTH;cnt++){
            output.digit[cnt]+=digit[cnt]+right.digit[cnt];
            if(cnt<MAX_LENGTH-1&&output.digit[cnt]>9){
                output.digit[cnt]-=10;
                output.digit[cnt+1]++;
            }
        }
    }
    else{
        bool rever=false;
        for(int cnt=MAX_LENGTH-1;cnt>=0;cnt--)
            if(digit[cnt]<right.digit[cnt]){
                rever=true;
                break;
            }
            else if(digit[cnt]>right.digit[cnt])
                break;
        if(rever){

            output=sub(right,*this);
            if(right.positivity){
                output.positivity=true;

            }
            else{
                output.positivity=false;
            }
        }
        else{
            output=sub(*this,right);
            if(positivity)
                output.positivity=true;
            else
                output.positivity=false;
        }
    }
    return output;
}

BigNum BigNum::operator-(BigNum const& right)const{
    BigNum output(right);
    output.positivity=!right.positivity;
    return *this+output;
}

BigNum& BigNum::operator++(){
    *this= *this+(BigNum)"1";
    return *this;
}

BigNum BigNum::operator++(int a){
    BigNum output(*this);
    ++(*this);
    return output;
}

BigNum operator+(const BigNum& left, const int right){
    BigNum r(right);
    return left+r;
}

BigNum operator+(const int l, const BigNum &r){
    return r+l;
}

BigNum operator*(const BigNum &l, const int r){
    BigNum rr(r);

    return l*rr;
}

BigNum operator*(const int l, const BigNum & r){
    return r*l;
}

BigNum operator-(const BigNum &l, const int r){
    BigNum rr(r);
    return l-rr;
}

BigNum operator-(const int l, const BigNum &r){
    BigNum ll(l);
    return ll-r;
}

std::ostream &operator<<(std::ostream& out,const BigNum& input){
    int num;
    for(num=MAX_LENGTH-1;num>=0&&input.digit[num]==0;num--);
    if(num==-1){
        out<<"0";
        return out;
    }
    else if(!input.positivity)
        out<<"-";
    for(int cnt=num;cnt>=0;cnt--)
        out<<(char)(input.digit[cnt]+'0');
    return out;
}

BigNum sub(BigNum r, BigNum l){
    BigNum output;
    output.positivity=true;
    for(int cnt=0;cnt<MAX_LENGTH;cnt++){
        output.digit[cnt]+=r.digit[cnt]-l.digit[cnt];
        if(output.digit[cnt]<0){
            output.digit[cnt]+=10;
            output.digit[cnt+1]--;
        }
    }
    return output;
}

std::istream& operator>>(std::istream& in,BigNum& a){
    std::string b;
    in>>b;
    BigNum c(b);
    a=c;
    return in;
}

/**
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

	private:

//Add data feild here to save the data of BigNum.
//Add additional member or global functions to help you set up the class.
};

BigNum operator+(const BigNum &, const int);
BigNum operator+(const int, const BigNum &);
BigNum operator-(const BigNum &, const int);
BigNum operator-(const int, const BigNum &);
BigNum operator*(const BigNum &, const int);
BigNum operator*(const int, const BigNum &);


#endif
*/
