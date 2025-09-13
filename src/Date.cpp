#include "Date.h"

Date::Date(std::string date)
    : m_day {std::stoi(date.substr(0,2))}
    , m_month {std::stoi(date.substr(3,2))}
    , m_year {std::stoi(date.substr(6,4))}
{
}

Date::Date(int day, int month, int year)
    : m_day {day}
    , m_month {month}
    , m_year {year}
{
}

void Date::setDate(std::string date) {
    m_day = std::stoi(date.substr(0,2));
    m_month = std::stoi(date.substr(3,2));
    m_year = std::stoi(date.substr(6,4));
}

void Date::setDate(int day, int month, int year) {
    m_day = day;
    m_month = month;
    m_year = year;
}

bool Date::isLeapyear() {
    if (m_year%100==0 && m_year%400==0) return true;
    else if (m_year%4==0) return true;
    return false;
}

bool Date::isGregorianBritain() {
    // Gregorian calendar in Great Britain was adopted on the 14th September 1752
    if (m_year > 1752) return true;
    else if (m_year == 1752) {
        if (m_day >= 14 && m_month >= 9) return true;
    }
    return false;
}

bool Date::isValid() {
    // Year
    if (m_year<1) return false;
    // Month
    if (m_month<1 || m_month>12) return false;
    // Day
    if (m_day<1 || m_day>31) return false;

    switch (m_month) {
        case 2:
            if (m_day == 29) return isLeapyear(); // 29th of Feb is only valid on leap years
            else if (m_day>28) return false;
            break;
        // Thirty days hath September, April, June and November
        case 4:
        case 6:
        case 9:
        case 11:
            if (m_day>30) return false;
            break;
    }
    return true;
}
