#include"stack.h"
using namespace std;

void stack::push(char a)
{
    if (n<100) 
	{
        data[n] = a;
        n++;
    }
}

char stack::pop()
{
    if (n > 0) 
	{
        char removedValue = data[n-1];
        
        n--;
        return removedValue;
    } 
	else 
	{
         throw string("Empty");
    }
}
char stack::top() const
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


bool stack::isEmpty() const
{
	bool r=false;
	if(n==0)
	{
		r=true;
	}
	return r;
}
bool stack::isFull() const
{
	bool r=false;
	if(n==100)
	{
		r=true;
	}
	return r;
}
int stack::size() const
{	
	return this->n;
}
stack::stack ()
{
	n=0;
}

//Task 2 part A.(already evaluated)
bool stack::isValidExpression(const string& expr) 
{
    stack st;
    for (char ch : expr) 
	{
        if (ch == '{' || ch == '(' || ch == '[') 
		{
            st.push(ch); // Push opening brackets
        } 
		else if (ch == '}' || ch == ')' || ch == ']') 
		{
            if (st.isEmpty() || (ch == '}' && st.pop() != '{') ||
                (ch == ')' && st.pop() != '(') ||
                (ch == ']' && st.pop() != '[')) 
			{
                return false; // Mismatched or extra closing bracket
            }
        }
    }
    return st.isEmpty(); // If stack is empty, it's valid
}
//Task 2 part B.
bool stack::isPalindrome(const string& str) 
{
    stack st;
    int i;
    int len = str.length();
    for (i = 0; i < len / 2; i++) 
	{
        st.push(str[i]); // Push first half of the string
    }
    i += len % 2; // Skip middle character for odd-length strings
    while (i < len) 
	{
        if (st.pop() != str[i]) // Compare remaining half
		{
		return false;
		} 
        i++;
    }
    return true;
}

//Task 2 part C.
// Function to search for an element in the stack
bool stack::search(char target) 
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

string stack::reverse(string s)
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

string stack::remove_duplicates(string str)
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