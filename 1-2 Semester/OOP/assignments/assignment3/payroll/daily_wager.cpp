// daily_wager.cpp
#include "daily_wager.h"
daily_wager::daily_wager(string n, string d, int s, int dw, int ab) : employee(n, d, s), daily_wage(dw), absent_count(ab) {}
void daily_wager::setDailywage(int dw) { daily_wage = dw; }
int daily_wager::getDailywage() const { return daily_wage; }
void daily_wager::setAbsent(int ab) { absent_count = ab; }
int daily_wager::getAbsent() const { return absent_count; }
int daily_wager::salary() const { return daily_wage * (30 - absent_count); }
int daily_wager::take_home_income() { return salary(); }