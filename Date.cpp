//
// Created by digas on 17/10/2019.
//

#include "Date.h"

int Date::get_day() const {
    return day;
}
int Date::get_month() const {
    return month;
}
int Date::get_year() const{
    return year;
}
void Date::set_day(int day) {
    this->day = day;
}
void Date::set_month(int month) {
    this->month = month;
}
void Date::set_year(int year) {
    this->year = year;
}
ostream & operator <<(ostream &out){
    if (day < 10 && month < 10) out << "0" << day << "/" << "0" << month << "/" << year << endl;
    else if (month < 10) out  << day << "/" << "0" << month << "/" << year << endl;
    else if (day < 10) out  << "0" << day << "/" << month << "/" << year << endl;
    else out << day << "/" << month << "/" << year << endl;
    return out;
}