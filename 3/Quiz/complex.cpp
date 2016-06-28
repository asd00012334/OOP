#include <cstdio>
#include <cstdlib>
#include <cmath>
#include "complex.h"
#include <algorithm>
#define PI 3.14159265
ComplexNumber::ComplexNumber(){
    real=imag=0;
}

ComplexNumber::ComplexNumber(double real, double imag){
    ComplexNumber& This=*this;
    This.real=real;
    This.imag=imag;
}

double ComplexNumber::getReal() const{
    return real;
}

double ComplexNumber::getImag() const{
    return imag;
}

void ComplexNumber::setReal(double input){
    real=input;
}

void ComplexNumber::setImag(double input){
    imag=input;
}

double ComplexNumber::Magnitude() const{
    return sqrt(real*real+imag*imag);
}

double ComplexNumber::Phase() const{
    ///use acos
    /**interval of degree?*/
    if(real==0){
        if(imag>0)
            return 90;
        else
            return -90;
    }
    else if(imag==0){
        if(real>0)
            return 0;
        else
            return 180;
    }
    else{
        if(imag>0){
            double cosine=0;
            cosine=real/this->Magnitude();
            return acos(cosine)*180/PI;
        }
        else{
            double cosine=0;
            cosine=real/this->Magnitude();
            return acos(cosine)*180/PI*(-1);
        }
    }
}
ComplexNumber ComplexNumber::operator!(){
    ComplexNumber output(*this);
    output.imag*=(-1);
    return output;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& right){
    ComplexNumber& left=*this;
    ComplexNumber output;
    output.real=left.real+right.real;
    output.imag=left.imag+right.imag;
    return output;
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& right){
    ComplexNumber& left=*this;
    ComplexNumber output;
    output.real=left.real-right.real;
    output.imag=left.imag-right.imag;
    return output;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& right){
    ComplexNumber output;
    ComplexNumber& left=*this;
    output.real=left.real*right.real-left.imag*right.imag;
    output.imag=left.real*right.imag+left.imag*right.real;
    return output;
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber& right){
    ComplexNumber &left=*this;
    ComplexNumber output,temp;
    temp=right;
    temp=!temp;
    ///(a+bi)/(c+di)=(a+bi)(c-di)/(c^2+d^2)
    output=left*temp;
    output.real/=right.real*right.real+right.imag*right.imag;
    output.imag/=right.real*right.real+right.imag*right.imag;
    return output;
}

void ComplexNumber::polar_coordinate(){
    printf("%lf and %lf degree\n",this->Magnitude(),this->Phase());
}

void ComplexNumber::show(){
    printf("(%lf,%lf)\n",real,imag);
}

