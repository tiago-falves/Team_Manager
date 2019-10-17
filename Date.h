//
// Created by digas on 17/10/2019.
//

#ifndef AEDA_TEAM_MANAGER_DATE_H
#define AEDA_TEAM_MANAGER_DATE_H
#include "Date.h"

class Date {
    int day, month, year;
public:
    int get_day() const;
    int get_month() const;
    int get_year() const;
    void set_day(int day);
    void set_month(int month);
    void set_year(int year);
    friend ostream & operator << () const;
};


#endif //AEDA_TEAM_MANAGER_DATE_H
