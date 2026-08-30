#include <iostream>
#include <fstream>
using namespace std;
int main() 
{
    fstream file;
    file.open("fellows1.txt", ios::app);  

    if (!file.is_open()) 
    {
        cout << "Error: Could not open the file 'fellows1.txt'!" << endl;
    }

    string rollNumber, fullName;
    float cgpa;
    char choice;

    do {
        cout << "Enter Roll Number : ";
        getline(cin, rollNumber);

        cout << "Enter Full Name: ";
        getline(cin, fullName);

        cout << "Enter CGPA: ";
        cin >> cgpa;
        cin.ignore();  // Clear newline character from input buffer

        file << rollNumber << ", " << fullName << ", " << cgpa << endl;

        cout << "Do you want to enter more data (Y/N)? ";
        cin >> choice;
        cin.ignore(); 

    } while (choice == 'Y' || choice == 'y');

    file.close();  
}