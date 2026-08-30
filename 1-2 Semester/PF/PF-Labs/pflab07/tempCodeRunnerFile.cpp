#include<iostream>
#include<string>
using namespace std;
struct ratio
{
    int num;
    int den;
};
ratio inratio();
void outratio(ratio a);
void adinverse(ratio a);
void reciprocal(ratio a);
void mul(ratio a, ratio b);
void addint(ratio a, int num);
ratio simplify(ratio a);
void convert(int a);
bool equal(ratio a, ratio b);
bool isless(ratio a, ratio b);
ratio inratio()

{
    ratio r;
    cin>>r.num;
    cin>>r.den;
    return r;
}
void outratio(ratio a)
{
    cout<<a.num;
    cout<<"/";
    cout<<a.den;
}
void adinverse(ratio a)
{
    cout<<-a.num;
    cout<<"/";
    cout<<a.den;
}
void reciprocal(ratio a)
{
    cout<<a.den;
    cout<<"/";
    cout<<a.num;
}
void mul(ratio a, ratio b)
{
    cout<<a.num*b.num;
    cout<<"/";
    cout<<a.den*b.den;
}
void addint(ratio a, int num)
{
    cout<<((a.den*num)+a.num)<<"/"<<a.den;
}
ratio simplify(ratio a)
{
    for(int i=2;i<=a.num && i<=a.den;i++)
    {
        while(a.num%i==0 && a.den%i==0)
        {
            a.num=a.num/i;
            a.den=a.den/i;
        } 
    }
    return a;
}
void convert(int a)
{
    cout<<"1/"<<a;
}
bool equal(ratio a, ratio b)
{
    bool r=false;
    if(a.num==b.num && a.den==b.den)
    {
        r=true;
    }
    return r;
}
bool isless(ratio a, ratio b)
{
    bool l=false;
    float y= float(a.num)/float(a.den);
    float z= float(b.num)/float(b.den);
    if(y<z)
    {
        l=true;
    }
    return l;
}
int main()
{
    bool d,e;
    ratio a,b,c;
    int num,num2;
    cout<<"Enter numerator and denominator of 1st ratio:";
    a=inratio();
    cout<<"Enter numerator and denominator of 2nd ratio:";
    b=inratio();
    if(a.den==0 || b.den==0)
    {
        cout<<"the answer is not possible";
        exit(5);
        return 5;
    }
     d=equal(a,b);
    if(d==true)
    {
        cout<<"The ratios are equal";
    }
    else
    {
        cout<<"The ratios are not equal";
    }
    e=isless(a,b);
    if(e==true)
    {
        cout<<endl<<"First ratio is less than second";
    }
    else
    {
        cout<<endl<<"First ratio is not less than second";
    }
    cout<<endl<<"The first ratio is:";
    outratio(a);
    cout<<endl;
    cout<<"Additve inverse of  first ratio is:";
    adinverse(a);
    cout<<endl<<"The reciprocal of the first  ratio is:";
    reciprocal(a);
    cout<<endl<<"The product of two ratio is:";
    mul(a,b);
    cout<<endl<<"Enter integer you want to add with first ratio:";
    cin>>num;
    cout<<"Sum of integer with 1st ratio is: ";
    addint(a,num);
    cout<<endl<<"The simplified form of ratio is :";
    c=simplify(a);
    cout<<c.num<<"/"<<c.den;
    cout<<endl<<"Enter another integer:";
    cin>>num2;
    convert(num2);
    return 0; 
}