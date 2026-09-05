#include"myint.h"
int main() {
    MyInt a(10);
    MyInt b = a;          // copy constructor
    MyInt c = MyInt(20);  // move constructor
    MyInt d;
    d = a;                // copy assignment
    MyInt e;
    e = MyInt(30);        // move assignment

    cout << "a = " << a.getValue() << endl;
    cout << "b = " << b.getValue() << endl;
    cout << "c = " << c.getValue() << endl;
    cout << "d = " << d.getValue() << endl;
    cout << "e = " << e.getValue() << endl;

    return 0;
}