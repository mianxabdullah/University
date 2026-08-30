// daily_wager.h
#ifndef DAILY_WAGER_H
#define DAILY_WAGER_H
#include "employee.h"

class daily_wager : public employee {
    int daily_wage;
    int absent_count;

public:
    daily_wager(string n, string d, int s, int dw, int ab);
    void setDailywage(int dw);
    int getDailywage() const;
    void setAbsent(int ab);
    int getAbsent() const;
    int salary() const;
    int take_home_income() override;
    ~daily_wager() override = default;
};

#endif