#include "CashMemo.h"

// Initialize static member
int CashMemo::nextReceiptNumber = 1;

void CashMemo::initializeReceiptNumber(int start) {
    nextReceiptNumber = start;
}

// Constructors
CashMemo::CashMemo() : receiptNumber(nextReceiptNumber++), saleDate(new Date()), 
                      customerName(""), customerAddress(""), 
                      saleLines(nullptr), saleLinesCount(0), saleLinesCapacity(0) {}

CashMemo::CashMemo(const std::string& name, const std::string& address)
    : receiptNumber(nextReceiptNumber++), saleDate(new Date()), 
      customerName(name), customerAddress(address), 
      saleLines(nullptr), saleLinesCount(0), saleLinesCapacity(0) {}

CashMemo::CashMemo(Date* date, const std::string& name, const std::string& address)
    : receiptNumber(nextReceiptNumber++), saleDate(date), 
      customerName(name), customerAddress(address), 
      saleLines(nullptr), saleLinesCount(0), saleLinesCapacity(0) {}

// Copy constructor
CashMemo::CashMemo(const CashMemo& other)
    : receiptNumber(other.receiptNumber),
      saleDate(new Date(*other.saleDate)),
      customerName(other.customerName),
      customerAddress(other.customerAddress),
      saleLines(nullptr),
      saleLinesCount(other.saleLinesCount),
      saleLinesCapacity(other.saleLinesCount) {
    if (other.saleLinesCount > 0) {
        saleLines = new SaleLine[saleLinesCapacity];
        for (int i = 0; i < saleLinesCount; ++i) {
            saleLines[i] = other.saleLines[i];
        }
    }
}

// Move constructor
CashMemo::CashMemo(CashMemo&& other) noexcept
    : receiptNumber(other.receiptNumber),
      saleDate(other.saleDate),
      customerName(std::move(other.customerName)),
      customerAddress(std::move(other.customerAddress)),
      saleLines(other.saleLines),
      saleLinesCount(other.saleLinesCount),
      saleLinesCapacity(other.saleLinesCapacity) {
    other.receiptNumber = 0;
    other.saleDate = nullptr;
    other.saleLines = nullptr;
    other.saleLinesCount = 0;
    other.saleLinesCapacity = 0;
}

// Assignment operator
CashMemo& CashMemo::operator=(const CashMemo& other) {
    if (this != &other) {
        receiptNumber = other.receiptNumber;
        delete saleDate;
        saleDate = new Date(*other.saleDate);
        customerName = other.customerName;
        customerAddress = other.customerAddress;

        delete[] saleLines;
        saleLinesCount = other.saleLinesCount;
        saleLinesCapacity = other.saleLinesCount;
        if (saleLinesCount > 0) {
            saleLines = new SaleLine[saleLinesCapacity];
            for (int i = 0; i < saleLinesCount; ++i) {
                saleLines[i] = other.saleLines[i];
            }
        } else {
            saleLines = nullptr;
        }
    }
    return *this;
}

// Move assignment operator
CashMemo& CashMemo::operator=(CashMemo&& other) noexcept {
    if (this != &other) {
        delete saleDate;
        delete[] saleLines;
        
        receiptNumber = other.receiptNumber;
        saleDate = other.saleDate;
        customerName = std::move(other.customerName);
        customerAddress = std::move(other.customerAddress);
        saleLines = other.saleLines;
        saleLinesCount = other.saleLinesCount;
        saleLinesCapacity = other.saleLinesCapacity;
        
        other.receiptNumber = 0;
        other.saleDate = nullptr;
        other.saleLines = nullptr;
        other.saleLinesCount = 0;
        other.saleLinesCapacity = 0;
    }
    return *this;
}

// Destructor
CashMemo::~CashMemo() {
    delete saleDate;
    delete[] saleLines;
}

// Methods
void CashMemo::addSaleLine(const SaleLine& line) {
    if (saleLinesCount >= saleLinesCapacity) {
        int newCapacity = (saleLinesCapacity == 0) ? 1 : saleLinesCapacity * 2;
        SaleLine* newSaleLines = new SaleLine[newCapacity];
        for (int i = 0; i < saleLinesCount; ++i) {
            newSaleLines[i] = saleLines[i];
        }
        delete[] saleLines;
        saleLines = newSaleLines;
        saleLinesCapacity = newCapacity;
    }
    saleLines[saleLinesCount++] = line;
}

void CashMemo::addSaleLine(int serial, const std::string& desc, int qty, double rt) {
    SaleLine newLine(serial, desc, qty, rt);
    addSaleLine(newLine);
}

double CashMemo::calculateTotal() const {
    double total = 0.0;
    for (int i = 0; i < saleLinesCount; ++i) {
        total += saleLines[i].getAmount();
    }
    return total;
}

void CashMemo::displayCashMemo(std::ostream& out) const {
    out << "\n\t\t  CASH MEMO\n";
    out << "-----------------------------------------\n";
    out << "Receipt No: " << std::setw(10) << receiptNumber << std::endl;
    out << "Date:       ";
    if (saleDate) {
        out << *saleDate;
    } else {
        out << "N/A";
    }
    out << std::endl;
    out << "Customer:   " << customerName << std::endl;
    out << "Address:    " << customerAddress << std::endl;
    out << "-----------------------------------------\n";
    out << std::setw(5) << "S.No." << std::setw(15) << "Description"
        << std::setw(8) << "Qty" << std::setw(10) << "Rate"
        << std::setw(12) << "Amount" << std::endl;
    out << "-----------------------------------------\n";
    for (int i = 0; i < saleLinesCount; ++i) {
        out << saleLines[i] << std::endl;
    }
    out << "-----------------------------------------\n";
    out << std::setw(40) << "Total Amount: "
        << std::setw(12) << std::fixed << std::setprecision(2) << calculateTotal() << std::endl;
    out << "-----------------------------------------\n";
    out << "\t\tThank You!\n";
}

// Friend operators
std::istream& operator>>(std::istream& in, CashMemo& cashMemo) {
    std::cout << "Enter Customer Name: ";
    in.ignore();
    std::getline(in, cashMemo.customerName);
    std::cout << "Enter Customer Address: ";
    std::getline(in, cashMemo.customerAddress);
    
    int day, month, year;
    std::cout << "Enter Date (DD MM YYYY): ";
    in >> day >> month >> year;
    delete cashMemo.saleDate;
    cashMemo.saleDate = new Date(day, month, year);

    int numItems;
    std::cout << "Enter the number of items: ";
    in >> numItems;

    delete[] cashMemo.saleLines;
    cashMemo.saleLines = nullptr;
    cashMemo.saleLinesCount = 0;
    cashMemo.saleLinesCapacity = 0;

    for (int i = 0; i < numItems; ++i) {
        SaleLine item;
        std::cout << "\nEnter details for item " << i + 1 << ":\n";
        in >> item;
        cashMemo.addSaleLine(item);
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const CashMemo& cashMemo) {
    cashMemo.displayCashMemo(out);
    return out;
}
