#include<iostream>
using namespace std;
class employee
{
  public:
  string name;
  string dpt;
  int scale;
  
  employee()
  {}

  employee(string n, string d, int s) : name(n),dpt(d),scale(s)
  {}


  void setName(string nam)
  {
    name=nam;
  }
  void setDpt(string dp)
  {
    dpt=dp;
  }
  void setScale(int s)
  {
    scale=s;
  }
  string getName ()
  {
    return name;
  }
  string getDpt ()
  {
    return dpt;
  }
  int getScale ()
  {
    return scale;
  }

  virtual int take_home_income()
  {
    throw 0;
    return 0;
  }
};
class officer : public employee
{
  public:
  int monthly_salary;
  officer(string n,string d,int s,int ms):employee(n,d,s)
  {
    monthly_salary=ms;
  }
  void setMsalary(int ms)
  {
    monthly_salary=ms;
  }

  int getMsalary()
  {
    return monthly_salary;
  }

  int take_home_income() override
  {
    int final_salary=monthly_salary*0.90;
    return final_salary;
  }
};
class daily_wager : public employee
{
 public:
 int daily_wage;
 int absent_count;

 daily_wager(string n, string d, int s, int dw, int ab) : employee(n, d, s), daily_wage(dw), absent_count(ab) {}

void setDailywage(int dw)
{
    daily_wage=dw;
}
int getDailywage()
{
    return daily_wage;
}

void setAbsent(int ab)
{
    absent_count=ab;
}
int getAbsent()
{
    return absent_count;
}

int salary()
{
    int present_count=30-absent_count;
    int sal=daily_wage*present_count;
    return sal;
}
int take_home_income () override
{
    return salary();
}

};

int main()
{
  employee *e[5];

  e[0]=new employee("ali","ds",17);
  e[1]=new officer("ahmad","se",18,50000);
  e[2]=new daily_wager("kamran","AI",5,1000,2);
  e[3]=new officer("akmal","IT",21,100000);
  e[4]=new employee("arshad","cs",22);

  
    // Demonstrate polymorphism
    for (int i = 0; i < 5; ++i) 
    {
      cout << "Employee Name: " << e[i]->getName() << endl;
      cout << "Department: " << e[i]->getDpt() << endl;
      cout << "Scale: " << e[i]->getScale() << endl;

      try 
      {
          cout << "Take-home income: " << e[i]->take_home_income() << endl;
      } 
      catch (...) 
      {
          cout << "Base employee does not have a take-home income calculation.\n";
      }

      cout << "-----------------------------\n";
  }

  
  for (int i = 0; i < 5; ++i) 
  {
      delete e[i];
  }

}