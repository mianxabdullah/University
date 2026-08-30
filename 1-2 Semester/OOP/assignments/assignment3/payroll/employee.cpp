// employee.cpp
#include "employee.h"
employee::employee() {}
employee::employee(string n, string d, int s) : name(n), dpt(d), scale(s) {}
void employee::setName(string nam) { name = nam; }
void employee::setDpt(string dp) { dpt = dp; }
void employee::setScale(int s) { scale = s; }
string employee::getName() const { return name; }
string employee::getDpt() const { return dpt; }
int employee::getScale() const { return scale; }
int employee::take_home_income() { throw 0; return 0; }
employee::~employee() {}