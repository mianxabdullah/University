#include<iostream>
using namespace std;
class employee
{
  public:
  string name;
  string dpt;
  int scale;

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
};
class officer : public employee
{
  public:
  int monthly_salary;

  void setMsalary(int ms)
  {
    monthly_salary=ms;
  }

  int getMsalary()
  {
    return monthly_salary;
  }

  int take_home_income()
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
int take_home_income()
{
    return salary();
}

};

int main()
{
   officer a;
   a.setName("abdullah");
   a.setDpt("devsinc");
   a.setScale(22);
   a.setMsalary(1000);
   cout<<"Name: "<<a.getName()<<endl<<"Department: "<<a.getDpt()<<endl<<" scale: "<<a.getScale()<<" Salary: "<<a.getMsalary()<<endl<<"Take home income: "<<a.take_home_income();
}