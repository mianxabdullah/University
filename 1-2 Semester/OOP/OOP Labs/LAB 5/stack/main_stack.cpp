#include"stack.h"
using namespace std;
#include<iostream>
int main()
{   try 
    {
        stack s;
        
        string expr1 = "2 + [ 3 * { 9 / 3 – (6+1)} + 5]";
        string expr2 = "[2 / { 4 – 3] + 9 )";

        cout << "Expression 1 is " << (s.isValidExpression(expr1) ? "Valid" : "Invalid") << endl;
        cout << "Expression 2 is " << (s.isValidExpression(expr2) ? "Valid" : "Invalid") << endl;

        // Test Palindrome Function
        string word1 = "level";
        string word2 = "hello";

        cout << "Word \"" << word1 << "\" is " << (s.isPalindrome(word1) ? "a palindrome" : "not a palindrome") << endl;
        cout << "Word \"" << word2 << "\" is " << (s.isPalindrome(word2) ? "a palindrome" : "not a palindrome") << endl;

        // Test Search Function
        s.push('a');
        s.push('b');
        s.push('c');
        s.push('d');

        char searchChar = 'b';
        cout << "Character '" << searchChar << "' is " << (s.search(searchChar) ? "found" : "not found") << " in the stack." << endl;
         
       
        string str="ali";
        cout<<s.reverse(str);
        
        
        cout<<endl;
        
        
        string str2="aabbccdde";
        cout<<s.remove_duplicates(str2);


    } 
	catch (string e) 
	{
        cout << "Exception: " << e << endl;
    }
}