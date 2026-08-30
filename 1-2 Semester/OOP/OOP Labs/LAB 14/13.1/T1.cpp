#include<iostream>
using namespace std;
int main ()
{
    int val1,val2;
    val1=2300;
    cout<<"Address of val1: "<<&val1<<endl;
    cout<<"Address of val2: "<<&val2<<endl;
    int *myPointer;
    cout<<"Size of Pointer variable in bytes: "<<sizeof(myPointer)<<endl;
    myPointer=&val1;
    cout<<"Value stored in Pointer object: "<<*myPointer<<endl;
    val2=*myPointer;
    cout<<"Value stored in val2: "<<val2<<endl;
    cout<<"Address stored in Pointer: "<<myPointer<<endl;
    cout<<"Value of myPointer: "<<*myPointer<<endl;
    myPointer=NULL;
    cout<<"Value of myPointer after assigning NULL: "<<*myPointer<<endl; // Dereferencing a NULL pointer leads to undefined behavior
}