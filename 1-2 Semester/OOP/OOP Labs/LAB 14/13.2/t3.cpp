#include <iostream>
#include <fstream>
using namespace std;
int main() 
{
    fstream file;
    file.open("fellows2.txt", ios::in);  

    if (!file.is_open()) 
    {
        cout << "Error: Could not open 'fellows2.txt'!" << endl;
    }

    const int RECORD_SIZE = 50;  // Approximate size per record
    int recordNumber;

    cout << "Enter the record number you want to read: ";
    cin >> recordNumber;

    int bytePosition = (recordNumber - 1) * RECORD_SIZE;
    file.seekg(bytePosition, ios::beg);  

    char buffer[RECORD_SIZE + 1] = {0};  
    file.read(buffer, RECORD_SIZE);

    if (file.gcount() < RECORD_SIZE) 
    {
        cout << "Error: Record does not exist!" << endl;
        file.close();
    }

    string rollNumber(buffer, 10);
    string name(buffer + 10, 35);
    string cgpaStr(buffer + 45, 5);

    cout << "Fellow Number: " << recordNumber << endl;
    cout << "Roll Number: " << rollNumber << endl;
    cout << "Name: " << name << endl;
    cout << "CGPA: " << cgpaStr << endl;

    file.close();
}