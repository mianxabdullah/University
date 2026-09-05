#include<iostream>
#include"CDLL_NoTail.h"
using namespace std;
int main()
{
    DCLL<int> lista,listb;
    lista.insertAtEnd(4);
    lista.insertAtEnd(7);
    lista.insertAtEnd(10);
    lista.insertAtEnd(12);

    lista.insertAtEnd(1);
    lista.insertAtEnd(3);
    lista.insertAtEnd(6);
    lista.insertAtEnd(8);
    lista.insertAtEnd(9);
    lista.insertAtEnd(15);

    DCLL<int> listc;
    listc.merge(lista,listb);
    listc.display();
    lista.display();
    listb.display();

}
