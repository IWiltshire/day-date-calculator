#include <iostream>
#include <map>
#include <cmath>
#include <Date.h>
#include <regex>
#include <limits>
#include <Validity.h>

std::string calculator(Date date);
ValidityCheckResult isUserInputValid(std::string dateString);
std::string dateString;

int main()
{   std::cout << "Hello and welcome to my super cool program. "
    << "Give me a date within the Gregorian calender, and I'll calculate which day of the week it laid on." << '\n' << std::endl;

    std::cout << "How many dates would you like for me to calculate for you?" << std::endl;

    std::regex numberPattern(R"(^(\d)*$)");
    std::string inputNumberOfDates;

    std::cin >> inputNumberOfDates;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (!regex_match(inputNumberOfDates, numberPattern)) {
        std::cout << "Please enter a valid integer." << std::endl;
        std::cin >> inputNumberOfDates;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    };

    int numberOfDates = std::stoi(inputNumberOfDates);
    if (numberOfDates == 0) {std::cout << "...Real funny." << '\n' << "Come back when you want to be serious." << std::endl;}
    else if (numberOfDates == 1) {std::cout << '\n' << "Okay, I will calculate " << numberOfDates << " date." <<'\n' << std::endl;}
    else {std::cout << '\n' << "Great! I will calculate " << numberOfDates << " dates." <<'\n' << std::endl;}

    int i {0};
    while(i<(numberOfDates)) {
        if (i==0) {std::cout << "Please give a date in dd/mm/yyyy format:" << std::endl;}
        else {std::cout << "Please give another date in dd/mm/yyyy format:" << std::endl;}

        std::cin >> dateString;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        ValidityCheckResult inputCheck = isUserInputValid(dateString);
        while(isUserInputValid(dateString) != VALID) {
            switch(inputCheck) {
                case NOT_GREGORIAN:
                    std::cout << "The Gregorian calender was only introduced in Great Britain on the Fourteenth of September 1752. As such, this program will only accept dates after that point."
                    << '\n' << "Please give a new date; one no earlier than 14/09/1752." << std::endl;
                    break;
                case WRONG_FORMAT:
                    std::cout << "Dates must be given in a dd/mm/yyyy format. Please provide a date in the correct format:" << std::endl;
                    break;
                case INVALID_DATE:
                    std::cout << "The date you've provided is invalid. Please correct any mistypings, or provide a valid date:" << std::endl;
                    break;
            }

            std::cin >> dateString;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        Date date = Date(dateString);
        std::cout << dateString << " was a " << calculator(date) << ". \n" <<std::endl;
        i++;
    }

    return 0;
}
