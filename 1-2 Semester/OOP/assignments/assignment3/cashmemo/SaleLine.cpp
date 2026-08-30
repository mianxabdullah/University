#include "SaleLine.h"

// Default constructor
SaleLine::SaleLine() : serialNumber(0), description(""), quantity(0), rate(0.0), amount(0.0) {}

// Parameterized constructor
SaleLine::SaleLine(int sn, const std::string& desc, int qty, double rt)
    : serialNumber(sn), description(desc), quantity(qty), rate(rt) {
    amount = quantity * rate;
}

// Copy constructor
SaleLine::SaleLine(const SaleLine& other)
    : serialNumber(other.serialNumber), description(other.description),
      quantity(other.quantity), rate(other.rate), amount(other.amount) {}

// Assignment operator
SaleLine& SaleLine::operator=(const SaleLine& other) {
    if (this != &other) {
        serialNumber = other.serialNumber;
        description = other.description;
        quantity = other.quantity;
        rate = other.rate;
        amount = other.amount;
    }
    return *this;
}

// Getters
int SaleLine::getSerialNumber() const { return serialNumber; }
std::string SaleLine::getDescription() const { return description; }
int SaleLine::getQuantity() const { return quantity; }
double SaleLine::getRate() const { return rate; }
double SaleLine::getAmount() const { return amount; }

// Display sale line
void SaleLine::displaySaleLine(std::ostream& out) const {
    out << std::setw(5) << serialNumber << std::setw(15) << description
        << std::setw(8) << quantity << std::setw(10) << std::fixed << std::setprecision(2) << rate
        << std::setw(12) << std::fixed << std::setprecision(2) << amount;
}

// Input operator
std::istream& operator>>(std::istream& in, SaleLine& saleLine) {
    std::cout << "Enter Serial Number: ";
    in >> saleLine.serialNumber;
    std::cout << "Enter Description: ";
    in.ignore();
    std::getline(in, saleLine.description);
    std::cout << "Enter Quantity: ";
    in >> saleLine.quantity;
    std::cout << "Enter Rate: ";
    in >> saleLine.rate;
    saleLine.amount = saleLine.quantity * saleLine.rate;
    return in;
}

// Output operator
std::ostream& operator<<(std::ostream& out, const SaleLine& saleLine) {
    saleLine.displaySaleLine(out);
    return out;
}
