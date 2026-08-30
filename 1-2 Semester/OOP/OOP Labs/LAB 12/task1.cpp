#include<iostream>
#include<string>
using namespace std;
class painting
{
    protected:
    string title;
    string name;
    public:
    int value;
    painting(string t,string n) : title(t),name(n),value(400)
    {}
    virtual void display()
    {
        cout<<"PAINTING TITLE: "<<title<<endl;
        cout<<"ARTIST NAME: "<<name<<endl;
        cout<<"PAINTING VALUE: "<<value<<"$"<<endl;
    }

};
class FamousPainting :public painting
{
    public:
    FamousPainting(string t,string n) : painting(t,n)
    {
        value=25000;
    }

    void display() override
    {
        cout<<"PAINTING TITLE: "<<title<<endl;
        cout<<"ARTIST NAME: "<<name<<endl;
        cout<<"PAINTING VALUE: "<<value<<"$"<<endl;
    }
};
int main()
{
   painting *p[7];
   
   for(int i=0;i<2;i++)
   {
      string tit,nam;
      cout<<"enter painting title , artist name for painting :"<<i+1<<endl;
      cin>>tit>>nam;
       
      for(int j=0;j<nam.length();j++)
      { 
        nam[j]=toupper(nam[j]);
      }

      if(nam=="DEGAS"||nam=="MONET"||nam=="PICASSO"||nam=="REMBRRANDT")
      {
        p[i]=new FamousPainting(tit,nam);
      }
      else
      {
        p[i]=new painting(tit,nam);
      }
   }
   for(int i=0;i<7;i++)
   {
     p[i]->display();
   }
}