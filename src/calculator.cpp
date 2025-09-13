#include <iostream>
#include <map>
#include <cmath>
#include <Date.h>
#include <regex>
#include <Validity.h>

int doomsdayByMonth[12] = {
     3  // 4th on a leap-year
    ,28 // 29th on a leap-year
    ,14
    ,4
    ,9
    ,6
    ,11
    ,8
    ,5
    ,10
    ,7
    ,12};

std::string weekdays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

std::regex datePattern(R"(^(\d{2})(/*.*)(\d{2})(/*.*)(\d{4})$)");

ValidityCheckResult isUserInputValid(std::string dateString) {
    if (!regex_match(dateString, datePattern)) return WRONG_FORMAT;

    Date date = Date(dateString);
    if (!date.isGregorianBritain()) return NOT_GREGORIAN;
    if (!date.isValid()) return INVALID_DATE;
    return VALID;
}

std::string calculator(Date date)
{   // CALCULATING DOOMSDAY
    int cent_doom; // Doomsday for the start of the century.
    int diff = date.getYear()%100; // Difference between current year and start of century.
    int remainder = (date.getYear()-diff-1700)%400;
    switch(remainder) {
        // Pattern is periodic with a period of 400 years. It goes: Sun -> Fri -> Wed -> Tue -> (repeat)
        case 0:
            cent_doom = 0;
            break;
        case 100:
            cent_doom = 5;
            break;
        case 200:
            cent_doom = 3;
            break;
        case 300:
            cent_doom = 2;
            break;
    }

    int doomsday = (cent_doom + diff + diff/4)%7; // Doomsday for the specific year

    // CALCULATING DAY OF THE WEEK
    int result;
    int specialDay = doomsdayByMonth[date.getMonth()-1];
    if (date.getMonth()<3 && date.isLeapyear()) specialDay+=1;

    int dayDiff = abs(specialDay-date.getDay());
    /*
    In the line below, we need to add a multiple of 7 before taking the modulo b/c C++ does not wrap around when negative index is passed to an array.
    The worst possible scenario is 01/02 on a leap-year -> -27%7, hence +28.
    */
    if (date.getDay() < specialDay) result = (doomsday - dayDiff + 28)%7;
    else result = (doomsday + dayDiff)%7;

    return weekdays[result];
}
