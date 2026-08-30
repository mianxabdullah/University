#include"bank.h"
#include<iostream>
using namespace std;

bankAccountSimulation::bankAccountSimulation()
	{
		AccountNumber=" ";
		HolderName=" ";
		balance=0.0;
	}

bankAccountSimulation::bankAccountSimulation(string an,string n,float b) : AccountNumber(an),HolderName(n),balance(b)
	{}
		
		
void bankAccountSimulation::Deposit(float d)
{
	balance+=d;
	cout<<" amount "<<d<<" has been deposited to you account and your current balance is : "<<balance<<endl;
}

void bankAccountSimulation::Withdraw(float amt)
{
	if(isSufficient(amt))
	{
	balance-=amt;
    cout<<" amount "<<amt<<" has been withdrawl from your account and your current balance is : "<<balance<<endl;
    }
    else
	{
	 cout<<"insufficient balance";
	}
}

void bankAccountSimulation::displayAccount()
{
	cout<<"ACCOUNT NUMBER : "<<AccountNumber<<endl;
	cout<<"HOLDER NAME : "<<HolderName<<endl;
	cout<<"Current Balance : "<<balance<<endl;
}

bool bankAccountSimulation::isSufficient(float d)
{
	return (balance>d);
}