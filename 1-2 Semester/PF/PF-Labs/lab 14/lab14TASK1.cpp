#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string fullName[5];
    string secondName[5];
    for (int i = 0; i < 5; i++) 
	{
        cout << "Enter full name " << i + 1 << ": ";
        getline(cin, fullName[i]);
    }
    for (int i = 0; i < 5; i++) 
	{
        int spacePos = fullName[i].find(' ');
        if (spacePos != -1) //find() func return -1 if item not found
		{
            int secondSpacePos = fullName[i].find(' ', spacePos + 1);
            if (secondSpacePos != -1) 
			{
                secondName[i] = fullName[i].substr(spacePos + 1, secondSpacePos - spacePos - 1);
            } 
            /*The substr function is used to extract a subset of characters from a string. It takes two arguments: the starting position of the subset and the length of the subset.
*/
			else 
			{
                secondName[i] = fullName[i].substr(spacePos + 1);
            }
        }
    }
    cout << "Second names:" << endl;
    for (int i = 0; i < 5; i++) 
	{
        cout << secondName[i] << endl;
    }

    return 0;
}


