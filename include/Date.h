#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date
{
private:
    int m_day{};
    int m_month{};
    int m_year{};

public:
    Date(std::string date="14/09/1752"); // Default arguments get put in the header file, but not the .cpp
    Date(int day, int month, int year);

    void setDate(std::string);
    void setDate(int day, int month, int year);
    bool isLeapyear();
    bool isValid();
    bool isGregorianBritain();

    // Access functions are typically defined in the header file for neatness
    int getDay() { return m_day ;}
    int getMonth() { return m_month ;}
    int getYear() { return m_year ;}

    void setDay(int day) { m_day = day ;}
    void setMonth(int month) { m_month = month ;}
    void setYear(int year) { m_year = year ;}
};

#endif // DATE_H
