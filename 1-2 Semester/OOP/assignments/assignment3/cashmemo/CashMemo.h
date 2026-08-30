#ifndef CASHMEMO_H
#define CASHMEMO_H

#include "Date.h"
#include "SaleLine.h"
#include <string>
#include <iostream>
#include <iomanip>

class CashMemo {
private:
    static int nextReceiptNumber;
    int receiptNumber;
    Date* saleDate;  // Aggregated
    std::string customerName;
    std::string customerAddress;
    SaleLine* saleLines; // Composite
    int saleLinesCount;
    int saleLinesCapacity;

public:
    // Static initialization
    static void initializeReceiptNumber(int start = 1);

    // Constructors
    CashMemo();
    CashMemo(const std::string& name, const std::string& address);
    CashMemo(Date* date, const std::string& name, const std::string& address);
    CashMemo(const CashMemo& other);
    CashMemo(CashMemo&& other) noexcept;

    // Assignment operators
    CashMemo& operator=(const CashMemo& other);
    CashMemo& operator=(CashMemo&& other) noexcept;

    // Destructor
    ~CashMemo();

    // Methods
    void addSaleLine(const SaleLine& line);
    void addSaleLine(int serial, const std::string& desc, int qty, double rt);
    double calculateTotal() const;
    void displayCashMemo(std::ostream& out) const;

    // Friend operators
    friend std::istream& operator>>(std::istream& in, CashMemo& cashMemo);
    friend std::ostream& operator<<(std::ostream& out, const CashMemo& cashMemo);
};

#endif // CASHMEMO_H
