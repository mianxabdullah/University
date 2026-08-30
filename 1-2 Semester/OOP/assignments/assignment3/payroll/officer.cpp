// officer.cpp
#include "officer.h"
officer::officer(string n, string d, int s, int ms) : employee(n, d, s), monthly_salary(ms) {}
void officer::setMsalary(int ms) { monthly_salary = ms; }
int officer::getMsalary() const { return monthly_salary; }
int officer::take_home_income() { return monthly_salary * 0.90; }