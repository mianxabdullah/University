#ifndef STACK_H
#define STACK_H


#include<iostream>
using namespace std;
class stack
{
	protected:
		char data[100];
		int n;
		
	public:
		void push(char);
		char pop();
		char top() const;
		int size() const;
		bool isEmpty() const;
		bool isFull() const;
		bool isValidExpression(const string& expr);  
		bool isPalindrome(const string& str);
		bool search(char target);
		string reverse(string s);
		string remove_duplicates(string str);
		stack();
};

#endif