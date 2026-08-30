#include <iostream>
#include <string>
using namespace std;
class shape
{
public:
    string name;
    shape(string n) : name(n) {}
    virtual float boundaryLength() = 0;
};
class rectangle : public shape
{
protected:
    float length;
    float width;

public:
    rectangle(string n, float l, float w) : shape(n), length(l), width(w) {}
    float boundaryLength()
    {
         return (2 * (length + width));
    }
    float area()
    {
        return length * width;
    }
};
class circle : public shape
{
protected:
    float radius;

public:
    circle(string n, float r) : shape(n), radius(r) {}
    float boundaryLength()
    {
         return (2 * 3.14 * radius);
    }
    float area()
    {
        return 3.14 * radius * radius;
    }
};
int main()
{
    shape *s[4];
    s[0] = new rectangle("rectangle", 2, 4);
    s[1] = new rectangle("rectangle", 2, 3);
    s[2] = new circle("circle", 5);
    s[3] = new circle("circle", 2);

    for (int i = 0; i < 4; i++)
    {
        cout << "SHAPE NAME :" << s[i]->name << endl;//upcasting
//to access (not virtual)derived class func with base pointer down casting is used
//and virtual will automatically be accessed using upcast implicit
        if (rectangle *r = dynamic_cast<rectangle *>(s[i]))
        {
            cout << "AREA :" << r->area() << endl;
        }
        else if (circle *c = dynamic_cast<circle *>(s[i]))
        {
            cout << "AREA :" << c->area() << endl;
        }
    }
}