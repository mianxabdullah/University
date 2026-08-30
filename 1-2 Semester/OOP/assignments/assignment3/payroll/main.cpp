// main.cpp
#include "payroll.h"
int main() {
    payroll p;
    p.loadEmployees();
    p.printSalaries();
    return 0;
}