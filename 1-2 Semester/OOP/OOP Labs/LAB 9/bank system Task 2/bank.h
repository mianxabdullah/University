#ifndef BankAcc
#define BankAcc

#include<iostream>
using namespace std;
class bankAccountSimulation
{
	protected:
		string AccountNumber;
		string HolderName;
		float balance;
	public:
		bankAccountSimulation();
		bankAccountSimulation(string, string, float);
		void Deposit(float);
		void Withdraw(float);
		void displayAccount();
		bool isSufficient(float amt);
		
};

#endif