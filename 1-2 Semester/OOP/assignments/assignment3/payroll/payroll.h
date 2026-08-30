// payroll.h
#ifndef PAYROLL_H
#define PAYROLL_H

#include "employee.h"

class payroll {
    employee* employees[5];  // Fixed-size array of pointers
    int count;               // Current number of employees

public:
    payroll();
    ~payroll();
    payroll(const payroll& other);
    payroll(payroll&& other) noexcept;
    payroll& operator=(const payroll& other);
    payroll& operator=(payroll&& other) noexcept;

    void loadEmployees();
    void printSalaries() const;
    void addEmployee(employee* e);
    void clearEmployees();
    int getCount() const { return count; }
};

#endif

