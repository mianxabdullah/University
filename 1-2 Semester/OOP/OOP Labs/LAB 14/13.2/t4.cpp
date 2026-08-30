#include <iostream>
#include <fstream>
using namespace std;
int main() 
{
    const int RECORD_SIZE = 50;
    fstream sourceFile("fellows2.txt", ios::in);
    fstream destFile("fellows3.txt", ios::out);

    if (!sourceFile.is_open() || !destFile.is_open()) 
    {
        cout << "Error opening source or destination file!" << endl;
    }

    string line;
    while (getline(sourceFile, line)) 
    {
        destFile << line << endl;
    }

    sourceFile.close();
    destFile.close();

    cout << "Copied fellows2.txt to fellows3.txt successfully.\n";

    // Step 2: Modify the 2nd last record of fellows2.txt
    fstream file("fellows2.txt", ios::in | ios::out | ios::ate); 

    if (!file.is_open()) 
    {
        cout << "Error opening fellows2.txt!" << endl;
    }

    // Calculate number of records
    streampos fileSize = file.tellp();  // total bytes in file
    int totalRecords = fileSize / RECORD_SIZE;

    if (totalRecords < 2) 
    {
        cout << "Not enough records to modify second last!" << endl;
    }

    int recordIndex = totalRecords - 2;
    file.seekp(recordIndex * RECORD_SIZE, ios::beg);

    string newRecord = "BCDF99H999Bara Admi                 4.00";
    newRecord.resize(RECORD_SIZE, ' '); 
    file << newRecord;

    file.close();
}