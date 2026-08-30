// officer.h
#ifndef OFFICER_H
#define OFFICER_H
#include "employee.h"

class officer : public employee {
    int monthly_salary;

public:
    officer(string n, string d, int s, int ms);
    void setMsalary(int ms);
    int getMsalary() const;
    int take_home_income() override;
    ~officer() override = default;
};

#endif