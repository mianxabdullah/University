#include <iostream>
#include "LSLL.h"   
using namespace std;
class passenger
{
public:
    string name,destination;
    int ticket;
    passenger(string n="",string d="",int t=0)
    {
        name=n;
        destination=d;
        ticket=t;
    }
    bool operator==(const passenger &other) const 
    {
        return name == other.name &&
               destination == other.destination &&
               ticket == other.ticket;
    }

    friend ostream& operator<<(ostream &out, const passenger &p) {
        out << "Name: " << p.name 
            << ", Destination: " << p.destination 
            << ", Ticket: " << p.ticket
            <<endl;

        return out;
    }
};
int main()
{
    LSLL<passenger> list;
    passenger p;
    p.name="abd";
    p.destination="lhr";
    p.ticket=100;
    list.insertAtEnd(p);
    passenger p1;
    p1.name="mus";
    p1.destination="jhang";
    p1.ticket=101;
    list.insertAtEnd(p1);
    passenger p2;
    p2.name="xyz";
    p2.destination="isl";
    p2.ticket=302;
    list.insertAtEnd(p2);
    list.display();
    list.remove(p1);
    list.display();


}