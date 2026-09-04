#include <iostream>
using namespace std;

void pattern(int curr_row, int row)
{
    if (curr_row > row)
        return;
    else
    {
        for (int i = 0; i < curr_row; i++)
            cout << "*";
        cout << endl;
        pattern(curr_row + 1, row);
    }
}

int main()
{
    pattern(1, 10);
}