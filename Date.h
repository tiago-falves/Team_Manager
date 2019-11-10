//
// Created by digas on 17/10/2019.
//


#pragma once

#include <iostream>
#include <string>
#include <vector>



using namespace std;

class Date{
private:
    unsigned short day;
    unsigned short month;
    unsigned year;

public:

    Date();
    Date(string  date); // Assuming "dd/mm/yyyy"
    Date(unsigned short day, unsigned short month, unsigned year);


    // GET methods
    unsigned short getDay() const;
    unsigned short getMonth() const;
    unsigned getYear() const;


    // SET methods
    void setDay(unsigned short day);
    void setMonth(unsigned short month);
    void setYear(unsigned year);

    // Other methods

    /*Converts a Date to a string
    @param - /
    @return string - the date in a string
    */
    string toString() const;

    /*Verifies if a Date is valid (months have 1 - 31 days, etc.)
    @param - /
    @return bool - true if date is valid
    */
    bool isValid();

    /*Verifies if a Date is equal to another, alternative to == operator
    @param - date of Date Class
    @return bool - true if dates are equal
    */
    bool isEqualTo(const Date &d);

    /*Verifies if a Date comes after another
    @param - date of Date Class
    @return bool - true if date is after the date specified in parenthesis
    */
    bool isAfter(const Date &d);

    /*Prints date to the screen, formatted, as an alternative to the << operator
    @param - date of Date Class
    @return bool - true if date is after the date specified in parenthesis
    */
    void showDate() const;

    friend bool operator==(const Date& date1, const Date& date2);
    friend ostream& operator<<(ostream& out, const Date& date);
    friend bool operator<=(const Date& date1, const Date& date2);
    friend bool operator>=(const Date& date1, const Date& date2);

    //Static Methods

    /*Returns an integer that represents the number of days in a given month of a given year
    @param - month - a month represented by it's numerical value
    @param - year - a year
    @return int - number of days in the given date
    */
    static int daysInMonth(int month, int year);

    /*Returns true if the given year is a leap year
    @param - year - a year to be verified
    @return bool - true if leap year, false otherwise
    */
    static bool isLeapYear(int year);

    /*Copies a date to another date object, alternative to the = operator
    @param - copy - date of Date Class to be copied
    @param - date - date of Date Class to copy
    @return void
    */
    static void copyDate(Date &copy, Date date);

    /*Converts date in a string to a date of a Date Class
    @param - dateText - date as a string to be converted
    @return Date - Date Class
    */
    static Date dateTextConverter(string dateText);

    /*Converts date in a string to a date of a Date Class from a file
    @param - dateText - date as a string to be converted
    @return Date - Date Class
    */
    static Date dateTextConverterFile(string dateText);

    /*Verifies if a date in a string is valid
    @param - dateText - date as a string to be verified
    @return bool - true if date is valid (ex. days go from 1-31, year > 1000 not accepted, etc.)
    */
    static bool validDateText(string dateText);

    /*Converts date in string to days*/
    int dateToDays() const;

};

class InvalidDate {
public:
    int day;
    int month;
    int year;

    const string getMessage() const {return "Invalid Date: " + to_string(day) + "/" + to_string(month) + "/" + to_string( year);}

    InvalidDate(int d,int m, int y):day(d), month(m), year(y) {}

};

