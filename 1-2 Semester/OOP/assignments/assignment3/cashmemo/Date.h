#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <iomanip>
#include <ctime>

class Date {
private:
    int day;
    int month;
    int year;

public:
    // Constructors
    Date();
    Date(int d, int m, int y);
    Date(const Date& other);

    // Assignment operator
    Date& operator=(const Date& other);

    // Getters
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // Display function
    void displayDate(std::ostream& out) const;

    // Friend operators
    friend std::istream& operator>>(std::istream& in, Date& date);
    friend std::ostream& operator<<(std::ostream& out, const Date& date);
};

#endif // DATE_H
