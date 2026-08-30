/* 
LAB 6:
TASK 1: Reverse a String using Stack
	•Push all characters of a string onto the stack.
	•Pop characters one by one to construct the reversed string.
	
TASK 2: Remove Consecutive Duplicates from a String using Stack
    •Given a string (e.g., "aabbccdde"), remove consecutive duplicate characters ("abcde").

*/


#include<iostream>
#include<string>
using namespace std;
template<typename T>
class stack
{
	protected:
		T data[100];
		int n;
		
	public:
		void push(T);
		T pop();
		T top() const;
		int size() const;
		bool isEmpty() const;
		bool isFull() const;
		bool isValidExpression(const string& expr);  
		bool isPalindrome(const string& str);
		bool search(T target);
		stack();
		//LAB 6:
		string reverse(string s);
		string remove_duplicates(string str);
		
};
template<typename T>
void stack<T>::push(T a)
{
    if (n<100) 
	{
        data[n] = a;
        n++;
    }
}
template<typename T>
T stack<T>::pop()
{
    if (n > 0) 
	{
        T removedValue = data[n-1];
        
        n--;
        return removedValue;
    } 
	else 
	{
         throw string("Empty");
    }
}
template<typename T>
T stack<T>::top() const
{
	if(n>0)
	{
		return this->data[0];
	}
	else
    {
        throw string("Empty");
    }
}

template<typename T>
bool stack<T>::isEmpty() const
{
	bool r=false;
	if(n==0)
	{
		r=true;
	}
	return r;
}
template<typename T>
bool stack<T>::isFull() const
{
	bool r=false;
	if(n==100)
	{
		r=true;
	}
	return r;
}
template<typename T>
int stack<T>::size() const
{	
	return this->n;
}
template<typename T>
stack<T>::stack ()
{
	n=0;
}
template<typename T>
bool stack<T>::isValidExpression(const string& expr) 
{
    stack st;
    for (char ch : expr) 
	{
        if (ch == '{' || ch == '(' || ch == '[') 
		{
            st.push(ch); 
        } 
		else if (ch == '}' || ch == ')' || ch == ']') 
		{
            if (st.isEmpty() || (ch == '}' && st.pop() != '{') ||
                (ch == ')' && st.pop() != '(') ||
                (ch == ']' && st.pop() != '[')) 
			{
                return false; 
            }
        }
    }
    return st.isEmpty();
}
template<typename T>
bool stack<T>::isPalindrome(const string& str) 
{
    stack st;
    int i;
    int len = str.length();
    for (i = 0; i < len / 2; i++) 
	{
        st.push(str[i]);
    }
    i += len % 2; 
    while (i < len) 
	{
        if (st.pop() != str[i]) 
		{
		return false;
		} 
        i++;
    }
    return true;
}
template<typename T>
bool stack<T>::search(T target) 
{
    for (int i = 0; i < n; i++) 
	{
        if (data[i] == target)
		{ 
		   return true; 
	    }
    }
    return false;
}
//-------------------------------------------------------------------------------------------------------------------------------
//TASK 1:
template<typename T>
string stack<T>::reverse(string s)
{
    stack st;
    string rev;
    for(int i =0; i < s.length(); i++)
    {
       st.push(s[i]);   
    }
    for(int i =0; i < s.length(); i++)
    {
       rev += st.pop(); 
    }
    return rev;
}
//TASK 2:
template<typename T>
string stack<T>::remove_duplicates(string str)
{
  stack rem;
  string updated;
  rem.push(str[0]);
  int count = 1;
  for(int i = 1; i < str.length(); i++)
  {
    if(str[i] != str[i-1])
    {
     rem.push(str[i]);
     count++;
    }
  }
  for(int i = 0; i < count; i++)
  {
    updated += rem.pop();
  }
  string ans = reverse(updated);
  return ans;
}

int main()
{   
    try 
    {
        stack<int> s;
        
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