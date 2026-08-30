#include <iostream>
#include <fstream>
#include <iomanip>  
using namespace std;
void readFellows2() 
{
    ifstream file("fellows2.txt");
    if (!file.is_open()) 
    {
        cout << "Error: Cannot open fellows2.txt" << endl;
    }
    cout << "Reading fellows2.txt:\n";

    string line;
    int count = 1;
    while (getline(file, line)) 
    {
        if (line.length() < 50) continue; // skip invalid lines

        string roll = line.substr(0, 10);
        string name = line.substr(10, 35);
        string cgpa = line.substr(45, 5);

        cout << count << " " << name << ", " << roll << endl;
        cout << "   CGPA: " << cgpa << endl;
        count++;
    }

    file.close();
    cout << endl;
}
void readFellows1() 
{
    ifstream file("fellows1.txt");
    if (!file.is_open()) 
    {
        cout << "Error: Cannot open fellows1.txt" << endl;
    }
    cout << "Reading fellows1.txt:\n";

    string line;
    int count = 1;
    while (getline(file, line)) 
    {
        size_t firstComma = line.find(',');
        size_t secondComma = line.find(',', firstComma + 1);

        if (firstComma == string::npos || secondComma == string::npos) continue;

        string roll = line.substr(0, firstComma);
        string name = line.substr(firstComma + 2, secondComma - firstComma - 2);
        string cgpa = line.substr(secondComma + 2);

        cout << count << " " << name << ", " << roll << endl;
        cout << "   CGPA: " << cgpa << endl;
        count++;
    }

    file.close();
    cout << endl;
}
int main() {
    readFellows2(); 
    readFellows1(); 
}