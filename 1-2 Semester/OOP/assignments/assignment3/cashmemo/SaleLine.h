#ifndef SALELINE_H
#define SALELINE_H

#include <string>
#include <iostream>
#include <iomanip>

class SaleLine {
private:
    int serialNumber;
    std::string description;
    int quantity;
    double rate;
    double amount;

public:
    // Constructors
    SaleLine();
    SaleLine(int sn, const std::string& desc, int qty, double rt);
    SaleLine(const SaleLine& other);

    // Assignment operator
    SaleLine& operator=(const SaleLine& other);

    // Getters
    int getSerialNumber() const;
    std::string getDescription() const;
    int getQuantity() const;
    double getRate() const;
    double getAmount() const;

    // Display function
    void displaySaleLine(std::ostream& out) const;

    // Friend operators
    friend std::istream& operator>>(std::istream& in, SaleLine& saleLine);
    friend std::ostream& operator<<(std::ostream& out, const SaleLine& saleLine);
};

#endif // SALELINE_H
