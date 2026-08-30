#include <iostream>
#include <cstring>
using namespace std;

const int MAX_LENGTH = 100;
int main() 
{
    char fullName[MAX_LENGTH];
    char secondName[MAX_LENGTH];

    for (int i = 0; i < 5; i++) 
	{
        cout << "Enter full name " << i + 1 << ": ";
        cin.getline(fullName, MAX_LENGTH);

        int spacePos = -1;
        for (int j = 0; j < strlen(fullName); j++) 
		{
            if (fullName[j] == ' ') 
			{
                spacePos = j;
                break;
            }
        }

        if (spacePos != -1) 
		{
            int secondSpacePos = -1;
            for (int j = spacePos + 1; j < strlen(fullName); j++) 
			{
                if (fullName[j] == ' ') 
				{
                    secondSpacePos = j;
                    break;
                }
            }

            if (secondSpacePos != -1) 
			{
                strncpy(secondName, fullName + spacePos + 1, secondSpacePos - spacePos - 1);
                secondName[secondSpacePos - spacePos - 1] = '\0';
            } 
			else 
			{
                strcpy(secondName, fullName + spacePos + 1);
            }
        }

        cout << "Second name: " << secondName << endl;
    }
}
