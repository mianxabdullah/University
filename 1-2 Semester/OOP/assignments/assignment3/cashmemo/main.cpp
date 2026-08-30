#include "CashMemo.h"
#include <iostream>
using namespace std;
int main() {
       // AGGREGATION: Create Date outside, pass it into CashMemo
    Date *externalDate = new Date(10, 5, 2025); 
    CashMemo aggregatedMemo(externalDate, "Ali", "123 Ahmad Street");

    // Add SaleLines (composition)
    aggregatedMemo.addSaleLine(1, "Pen", 10, 1.50);
    aggregatedMemo.addSaleLine(2, "Notebook", 5, 3.00);

    cout << "DATE CREATED EXTERNALLY: (AGGREGATION EXAMPLE) :"<<endl;
    cout << aggregatedMemo;

    // COMPOSITION: Let CashMemo manage SaleLines entirely (created and owned internally)
    CashMemo composedMemo("abdullah", "456 LDA Avenue");

    // Add SaleLines directly (composed within CashMemo)
    composedMemo.addSaleLine(1, "Marker", 3, 2.00);
    composedMemo.addSaleLine(2, "Eraser", 4, 1.25);

    cout << " Composition Example (SaleLines managed by CashMemo) "<<endl;
    cout << composedMemo;
}
