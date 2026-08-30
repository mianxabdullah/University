// employee.h
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
using namespace std;

class employee {
protected:
    string name;
    string dpt;
    int scale;

public:
    employee();
    employee(string n, string d, int s);

    void setName(string nam);
    void setDpt(string dp);
    void setScale(int s);

    string getName() const;
    string getDpt() const;
    int getScale() const;

    virtual int take_home_income();
    virtual ~employee();
};

#endif
