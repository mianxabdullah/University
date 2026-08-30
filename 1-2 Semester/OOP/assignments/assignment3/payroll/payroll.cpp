// payroll.cpp
#include "payroll.h"
#include "officer.h"
#include "daily_wager.h"
#include <iostream>
#include <utility>
using namespace std;

payroll::payroll() : count(0) 
{
    for (int i = 0; i < 5; ++i) 
    {
        employees[i] = nullptr;
    }
}

payroll::~payroll() 
{
    clearEmployees();
}

payroll::payroll(const payroll& other) : count(other.count) 
{
    for (int i = 0; i < count; ++i) 
    {
        if (dynamic_cast<officer*>(other.employees[i])) 
        {
            employees[i] = new officer(*dynamic_cast<officer*>(other.employees[i]));
        } 
        else if (dynamic_cast<daily_wager*>(other.employees[i])) 
        {
            employees[i] = new daily_wager(*dynamic_cast<daily_wager*>(other.employees[i]));
        }
        else if (other.employees[i]) 
        {
            employees[i] = new employee(*other.employees[i]);
        }
        else 
        {
            employees[i] = nullptr;
        }
    }
}

payroll::payroll(payroll&& other) noexcept : count(other.count) 
{
    for (int i = 0; i < count; ++i) 
    {
        employees[i] = other.employees[i];
        other.employees[i] = nullptr;
    }
    other.count = 0;
}

payroll& payroll::operator=(const payroll& other) 
{
    if (this != &other) 
    {
        payroll temp(other);
        for (int i = 0; i < 5; ++i) 
        {
            std::swap(employees[i], temp.employees[i]);
        }
        std::swap(count, temp.count);
    }
    return *this;
}

payroll& payroll::operator=(payroll&& other) noexcept 
{
    if (this != &other) 
    {
        clearEmployees();
        for (int i = 0; i < other.count; ++i) 
        {
            employees[i] = other.employees[i];
            other.employees[i] = nullptr;
        }
        count = other.count;
        other.count = 0;
    }
    return *this;
}

void payroll::loadEmployees() 
{
    clearEmployees();
    
    addEmployee(new officer("ahmad", "se", 18, 50000));
    addEmployee(new daily_wager("kamran", "AI", 5, 1000, 2));
    addEmployee(new officer("akmal", "IT", 21, 100000));
}

void payroll::printSalaries() const 
{
    for (int i = 0; i < count; ++i) {
        if (employees[i]) {
            cout << "Employee Name: " << employees[i]->getName() << endl;
            cout << "Department: " << employees[i]->getDpt() << endl;
            cout << "Scale: " << employees[i]->getScale() << endl;

            try 
            {
                cout << "Take-home income: " << employees[i]->take_home_income() << endl;
            } catch (const std::exception& e) 
            {
                cout << e.what() << endl;
            }

            cout << "-----------------------------\n";
        }
    }
}

void payroll::addEmployee(employee* e) 
{
    if (count < 5) 
    {
        employees[count++] = e;
    } 
    else 
    {
        delete e;  // Prevent memory leak if we can't add
        throw std::runtime_error("Payroll is full");
    }
}

void payroll::clearEmployees() 
{
    for (int i = 0; i < count; ++i) 
    {
        delete employees[i];
        employees[i] = nullptr;
    }
    count = 0;
}