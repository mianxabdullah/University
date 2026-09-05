#include<iostream>
#include"LSLL.h"
using namespace std;
int main()
{
    cout<<"Task1:"<<endl;
    LSLL<int> list;
    //{4 2 8 1 9 5 4 6}
    list.insertAtHead(4);
    list.insertAtEnd(2);
    list.insertAtEnd(8);
    list.insertAtEnd(1);
    list.insertAtEnd(9);
    list.insertAtEnd(5);
    list.insertAtEnd(4);
    list.insertAtEnd(6);
    list.display();
    int v=0;
    if(list.removeKth(4,v))
    {
        cout<<"ture: kth node removed "<<endl;
    }
    list.display();
}