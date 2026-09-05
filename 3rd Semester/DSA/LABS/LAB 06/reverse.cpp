#include<iostream>
#include"LSLL.h"
using namespace std;
int main()
{
LSLL<int> list7;
    cout<<"Task4:"<<endl;
    //{4 2 8 1 9 5 4 6}
    list7.insertAtHead(4);
    list7.insertAtEnd(2);
    list7.insertAtEnd(8);
    list7.insertAtEnd(1);
    list7.insertAtEnd(9);
    list7.insertAtEnd(5);
    list7.insertAtEnd(4);
    list7.insertAtEnd(6);
    cout<<"List: "<<endl;
    list7.display();
    list7.reverseList();
    cout<<"Reversed List: "<<endl;
    list7.display();
}