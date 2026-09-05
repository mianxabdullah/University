#include <iostream>
#include <iomanip>

#include <string>
using namespace std;
class HashTable
{
private:
    string *arr;
    int s;
    int n;

public:
    HashTable(int size)
    {
        s = size;
        n = 0;
        arr = new string[s];
        for (int i = 0; i < s; i++)
            arr[i] = "empty";
    }
    int hash(string key)
    {
        int h = 0;
        for (int i = 0; i < key.length(); i++)
            h += key[i];
        return h % s;
    }
    bool isEmpty()
    {
        return (n == 0);
    }
    bool isFull()
    {
        return (n == s);
    }
    float loadFactor()
    {
        return float(n) / s;
    }
    bool insert(string key)
    {
        int i = hash(key);
        int start = i;
        while (arr[i] != "empty")
        {
            cout << endl
                 << "searching for insert in index: " << i << endl;
            i = (i + 1) % s;
            if (i == start)
                break;
        }
        if (arr[i] == "empty")
        {
            cout << endl
                 << "inserted at index: " << i << endl;
            arr[i] = key;
            n += 1;
            return true;
        }
        else
        {
            return false;
        }
    }
    bool search(string key)
    {
        int i = hash(key);
        int start = i;
        while (arr[i] != "empty")
        {
            cout << endl
                 << "searching in index: " << i << endl;
            if (arr[i] == key)
            {
                cout << endl
                     << "inserted at index: " << i << endl;
                return true;
            }
            i = (i + 1) % s;
            if (i == start)
                break;
        }
        return false;
    }

    bool removeKey(string key)
    {
        int i = hash(key);
        int start = i;

        while (arr[i] != "empty")
        {
            if (arr[i] == key)
            {
                arr[i] = "empty";
                n -= 1;
                return true;
            }
            i = (i + 1) % s;
            if (i == start)
            {
                break;
                return false;
            }
        }
    }
    void display()
    {
        for (int i = 0; i < s; i++)
            cout << i << "->" << arr[i] << endl;
    }
};
void menu()
{
    int si;
    cout << "Enter the size of Hash Table: ";
    cin >> si;
    HashTable h(si);
    int ch;
    while (ch != 6)
    {
        cout << "1.  Insert a name  \n2.  Search for a name  \n3.  Remove a name  \n4.  Display the Hash Table  \n5.  Display Load Factor of the table  \n6.  Exit \nEnter your choice: ";
        cin >> ch;
        if (ch == 1)
        {
            string nam;
            cout << endl
                 << "enter name you want to insert" << endl;
            cin >> nam;
            if (h.insert(nam))
            {
                cout << "\nInserted\n";
            }
        }
        if (ch == 2)
        {
            string nam;
            cout << endl
                 << "enter name you want to search" << endl;
            cin >> nam;
            if (h.search(nam))
            {
                cout << "\nfound\n";
            }
        }
        if (ch == 3)
        {
            string nam;
            cout << endl
                 << "enter name you want to remove" << endl;
            cin >> nam;
            if (h.removeKey(nam))
            {
                cout << "\nremoved\n";
            }
        }
        if (ch == 4)
        {
            h.display();
        }
        if (ch == 5)
        {
            cout << "\nLoad Factor: " << h.loadFactor() << endl;
        }
        if (ch == 6)
        {
            return;
        }
    }
}

class HashTableLP
{
private:
    int *arr;
    int size;
    int n;

public:
    HashTableLP(int s)
    {
        size = s;
        arr = new int[size];
        for (int i = 0; i < size; i++)
            arr[i] = -1;
    }
    int hash(int key)
    {
        return key % size;
    }
    bool insert(int key)
    {
        int i = hash(key);
        if (arr[i] != -1)
        {
            return false;
        }
        arr[i] = key;
        return true;
    }

    bool search(int key)
    {
        int i = hash(key);
        if (arr[i] == key)
            return true;
        return false;
    }

    bool removeKey(int key)
    {
        int i = hash(key);
        if (arr[i] == key)
        {
            arr[i] = -1;
            return true;
        }
        return false;
    }
    void display()
    {
        for (int i = 0; i < size; i++)
            cout << i << " → " << arr[i] << endl;
    }
};
int getRandomNumber(int start, int end)
{
    return rand() % (end - start + 1) + start;
}
int experiment(int tabsize)
{
    int count = 0;
    HashTableLP h(tabsize);
    for (int i = 0; i < 50; i++)
    {
        if (h.insert(getRandomNumber(1, 100)))
        {
            count++;
        }
        else
        {
            return count;
        }
    }
}
int main()
{
    menu();
    srand(static_cast<unsigned>(time(0)));
    const int numExperiments = 50;
    cout << "Table Size\tAverage Inserted\n";
    cout << "-----------\t----------------\n";
    // Run experiments for table sizes 10, 20, 30, ..., 100
    for (int S = 10; S <= 100; S += 10)
    {
        double totalInserted = 0.0;
        for (int i = 0; i < numExperiments; i++)
            totalInserted += experiment(S);
        double averageInserted = totalInserted / numExperiments;
        cout << setw(5) << S << "\t\t" << fixed << setprecision(2)
             << averageInserted << endl;
    }
}
