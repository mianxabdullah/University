#include<iostream>
#include"LSLL.h"
using namespace std;
int main()
{
   // {7 3 4 2}
    cout<<"Task3:"<<endl;
    LSLL<int> list1;
    list1.insertAtEnd(2);
    list1.insertAtEnd(6);
    list1.insertAtEnd(4);
    cout<<"List1: "<<endl;
    list1.display();

    // {5 9}
    LSLL<int> list2;
    list2.insertAtEnd(8);
    list2.insertAtEnd(1);
    list2.insertAtEnd(3);
    cout<<"List2: "<<endl;
    list2.display();

    LSLL<int> list3;
    list3.shuffleMerge(list1,list2);
    cout<<"Merged List3: "<<endl;
    list3.display();
    cout<<"Updated List1: "<<endl;
    list1.display();
    cout<<"Updated List2: "<<endl;
    list2.display();
}