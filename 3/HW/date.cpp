#include <cstdio>
#include <cstdlib>
#include "date.h"

unsigned short int Date::getDate_data()const{
    return Date_data;
}

unsigned short int Date::getDay()const{
    return Date_data%(1<<5);
}

unsigned short int Date::getMon()const{
    return (Date_data>>5)%(1<<4);
}

unsigned short int Date::getYr()const{
    return (Date_data>>9)+2000;
}

void Date::setDate(const short int& yr,const short int& mon,const short int& day){
    Date_data=((yr-2000)<<9)+(mon<<5)+day;
}

void Date::showDate(){
    printf("%d %d %d\n",getYr(),getMon(),getDay());
}

/**
#ifndef DATE
#define DATE
#include<iostream>

class Date{
	 unsigned short int Date_data;
public:
	//constructors
	Date():Date_data(0){};

	//get_funcs
	unsigned short int getDate_data()const;
	unsigned short int getDay()const;
	unsigned short int getMon()const;
	unsigned short int getYr()const;

	//set_funcs
	void setDate(const short int&,const short int&,const short int&);

	void showDate();
};
#endif
*/
