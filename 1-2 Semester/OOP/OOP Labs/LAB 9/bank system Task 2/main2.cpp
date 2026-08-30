#include"bank.h"
#include<iostream>
using namespace std;
int main()
{
	bankAccountSimulation a("pk001","abdullah",500000);
	bankAccountSimulation b("pk002","ali",20000);
	
	a.Deposit(20000);
	a.Withdraw(40000);
	
	b.Deposit(10000);
	b.Withdraw(4000);
	
	a.displayAccount();
	b.displayAccount();
	

}