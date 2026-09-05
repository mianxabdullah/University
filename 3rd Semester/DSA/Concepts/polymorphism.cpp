#include<iostream>
#include<vector>
using namespace std;
class shape
{
    public:
    virtual void area() =0;
};
class rect : public shape
{
    protected:
    float l,w;
    public:
    rect(float len=0,float wid =0)
    {
        l=len;
        w=wid;
    }
    void area() override
    {
        cout<<"Area of Rectangle: "<<(l*w)<<endl;
    }
};
class triangle : public shape
{
    protected:
    float h,b;
    public:
    triangle(float hi=0,float bs =0) : h(hi),b(bs){}
    void area() override
    {
        cout<<"Area of triangle: "<<(0.5*h*b)<<endl;
    }
};
int main()
{
    shape *s=new rect(5,6);
    shape *s1=new triangle(5,6);
    s->area();
    s1->area();
}