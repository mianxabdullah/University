#include "Date.h"

// Default constructor
Date::Date() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    year = 1900 + ltm->tm_year;
    month = 1 + ltm->tm_mon;
    day = ltm->tm_mday;
}

// Parameterized constructor
Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

// Copy constructor
Date::Date(const Date& other) : day(other.day), month(other.month), year(other.year) {}

// Assignment operator
Date& Date::operator=(const Date& other) {
    if (this != &other) {
        day = other.day;
        month = other.month;
        year = other.year;
    }
    return *this;
}

// Getters
int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }

// Display date
void Date::displayDate(std::ostream& out) const {
    out << std::setfill('0') << std::setw(2) << day << std::setfill(' ') << "-"
        << std::setfill('0') << std::setw(2) << month << std::setfill(' ') << "-"
        << year;
}

// Input operator
std::istream& operator>>(std::istream& in, Date& date) {
    std::cout << "Enter date (DD MM YYYY): ";
    in >> date.day >> date.month >> date.year;
    return in;
}

// Output operator
std::ostream& operator<<(std::ostream& out, const Date& date) {
    date.displayDate(out);
    return out;
}
