#include <iostream>
#include <string>
using namespace std;

string longest_word(const string& paragraph) 
{
    string word = "";
    string longest = "";
    int max_len = 0;
    
    for(int i = 0;i < paragraph.length();i++) 
	{
        if (paragraph[i] == ' ') 
		{
            if (word.length() > max_len) 
			{
                max_len = word.length();
                longest = word;
            }
            word = "";
        } 
		else 
		{
            word =word+paragraph[i];
        }
        
    }

    // for last word
    if (word.length() > max_len) 
	{
        longest = word;
    }

    return longest;
}


int main() 
{
   string paragraph = "This is a test paragraph with multiple sentences.";
   cout << longest_word(paragraph) << endl;
}