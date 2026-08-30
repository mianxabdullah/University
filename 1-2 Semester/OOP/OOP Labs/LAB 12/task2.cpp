#include<iostream>
#include<string>
using namespace std;
class shape
{   
    public:
    string name;
    shape(string n): name(n){}
    virtual float area()=0;
    virtual float boundaryLength()=0;
};
class rectangle : public shape
{
   protected:
   float length;
   float width;
   public:
   rectangle(string n,float l,float w) :shape(n), length(l),width(w){}
   float boundaryLength()
   {
    return (2*(length+width));
   }
   float area() override
   {
      return length*width;
   }
};
class circle : public shape
{
    protected:
    float radius;
    public:
    circle(string n,float r) :shape(n),radius(r){}
   float boundaryLength()
   {
    return (2*3.14*radius);
   }
   float area() override
   {
      return 3.14*radius*radius;
   }


};
class triangle : public shape
{
    protected:
    float s1,s2,s3;
    public:
    triangle(string n,float a,float b,float c) :shape(n), s1(a),s2(b),s3(c){}
    float boundaryLength()
   {
    return(s1*s2*s3);
   }

   float area() override
   {
      return 0.5*s1*s2;
   }


};
class square : public shape
{
    protected:
    float len;
    public:
    square(string n, float ln) :shape(n),len(ln){}
    float boundaryLength()
   {
    return (4*len);
   }
   float area() override
   {
      return 2*len;
   }
};
int main()
{
    shape *s[4];
    s[0]=new rectangle("rectangle",2,4);
    s[1]=new triangle("triangle",2,3,4);
    s[2]=new circle("circle",5);
    s[3]=new square("square",2);

    for(int i=0;i<4;i++)
   {
        cout<<"SHAPE NAME :"<<s[i]->name<<endl;
        cout<<"BOUNDERY LENGTH: "<<s[i]->boundaryLength()<<endl;
        cout<<"AREA :"<<s[i]->area()<<endl;
   }
}