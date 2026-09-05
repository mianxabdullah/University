#include "TempStack.h"

void sum(string a, string b)
{
    int carry = 0;
    Stack<int> one(a.length());
    Stack<int> two(b.length());
    int maxi = max(a.size(), b.size());
    Stack<int> res(maxi);
    for (int i = 0; i < a.length(); i++)
    {
        one.push(a[i] - '0');
    }
    for (int i = 0; i < b.length(); i++)
    {
        two.push(b[i] - '0');
    }

    while (!one.isEmpty() || !two.isEmpty())
    {
        int sum = carry + (one.pop() + two.pop());
        carry = sum / 10;
        res.push(sum % 10);
    }
    if (carry != 0)
    {
        res.push(carry);
    }
    for (int i = 0; i < maxi; i++)
    {
        cout << res.pop();
    }
}
int main()
{
    cout << "Sum: ";
    sum("5", "3784");
}
