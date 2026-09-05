#include<iostream>
#include"LSLL.h"
using namespace std;
int main()
{
    LSLL<int> list8;
    cout<<"Task4:"<<endl;
    //{4 2 8 1 9 5 4 6}
    list8.insertAtHead(4);
    list8.insertAtEnd(2);
    list8.insertAtEnd(8);
    list8.insertAtEnd(2);
    list8.insertAtEnd(9);
    list8.insertAtEnd(6);
    list8.insertAtEnd(4);
    list8.insertAtEnd(6);
    cout<<"List with Duplicates: "<<endl;
    list8.display();
    list8.removeDuplicate();
    cout<<"List without Duplicates: "<<endl;
    list8.display();
}