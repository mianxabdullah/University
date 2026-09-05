#include<iostream>
#include"LSLL.h"
using namespace std;
int main()
{
    // {7 3 4 2}
    cout<<"Task2:"<<endl;
    LSLL<int> list1;
    list1.insertAtEnd(7);
    list1.insertAtEnd(3);
    list1.insertAtEnd(4);
    list1.insertAtEnd(2);
    cout<<"List1: "<<endl;
    list1.display();

    // {5 9}
    LSLL<int> list2;
    list2.insertAtEnd(5);
    list2.insertAtEnd(9);
    cout<<"List2: "<<endl;
    list2.display();

    LSLL<int> list3;
    list3.combine(list1,list2);
    cout<<"Combined List3: "<<endl;
    list3.display();
    cout<<"Updated List1: "<<endl;
    list1.display();
    cout<<"Updated List2: "<<endl;
    list2.display();
}