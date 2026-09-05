#include <iostream>
#include <string>
using namespace std;

class HashNode
{
public:
    string key;
    int value;
    HashNode *next;

    HashNode(string k, int v)
    {
        key = k;
        value = v;
        next = NULL;
    }
};

class HashTable
{
private:
    HashNode **table; // its not 2d array its a pointer to 1d array of pointers of LL
    int size;

    int hashFunction(string key)
    {
        int h = 0;
        for (int i = 0; i < key.length(); i++)
            h += key[i];
        return h % size;
    }

public:
    HashTable(int s)
    {
        size = s;
        table = new HashNode *[size];
        for (int i = 0; i < size; i++)
            table[i] = NULL;
    }

    void insert(string key, int value)
    {
        int index = hashFunction(key);
        HashNode *head = table[index];
        HashNode *temp = head;
        while (temp != NULL) // check all nodes if key already exist so it updates
        {
            if (temp->key == key)
            {
                temp->value = value;
                return;
            }
            temp = temp->next;
        }
        HashNode *newNode = new HashNode(key, value); // create newnode if key doent exist
        newNode->next = head;                         // insert at head
        table[index] = newNode;
    }
    bool get(string key, int &value)
    {
        int index = hashFunction(key);
        HashNode *temp = table[index];

        while (temp != NULL)
        {
            if (temp->key == key)
            {
                value = temp->value;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void remove(string key)
    {
        int index = hashFunction(key);
        HashNode *temp = table[index];
        HashNode *prev = NULL;

        while (temp != NULL && temp->key != key)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
            return; // key not found

        if (prev == NULL)              // means key is at head
            table[index] = temp->next; // remove head node
        else
            prev->next = temp->next;

        delete temp;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "INDEX " << i << ": ";
            HashNode *temp = table[i];
            while (temp != NULL)
            {
                cout << "[" << temp->key << " : " << temp->value << "] -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }

    ~HashTable()
    {
        for (int i = 0; i < size; i++)
        {
            HashNode *temp = table[i];
            while (temp != NULL)
            {
                HashNode *rm = temp;
                temp = temp->next;
                delete rm;
            }
        }
        delete[] table;
    }
};

class HashTableLP
{
private:
    int *arr;
    int size;

public:
    HashTableLP(int s)
    {
        size = s;
        arr = new int[size];
        for (int i = 0; i < size; i++)
            arr[i] = -1; // -1 means empty
    }

    int hash(int key)
    {
        return key % size;
    }

    void insert(int key)
    {
        int i = hash(key);

        while (arr[i] != -1)
        {
            i = (i + 1) % size;
        }

        arr[i] = key;
    }

    bool search(int key)
    {
        int i = hash(key);
        int start = i;

        while (arr[i] != -1)
        {
            if (arr[i] == key)
                return true;
            i = (i + 1) % size;
            if (i == start)
                break;
        }

        return false;
    }

    void removeKey(int key)
    {
        int i = hash(key);
        int start = i;

        while (arr[i] != -1)
        {
            if (arr[i] == key)
            {
                arr[i] = -2; // -2 means deleted
                return;
            }
            i = (i + 1) % size;
            if (i == start)
                break;
        }
    }

    void display()
    {
        for (int i = 0; i < size; i++)
            cout << i << " → " << arr[i] << endl;
    }
};

class HashTableQuadratic
{
private:
    int *table;
    int size;

public:
    HashTableQuadratic(int s)
    {
        size = s;
        table = new int[size];
        for (int i = 0; i < size; i++)
            table[i] = -1;
    }

    int hash(int key)
    {
        return key % size;
    }
    void insert(int key)
    {
        int index = hash(key);

        for (int i = 0; i < size; i++)
        {
            int newIndex = (index + i * i) % size;

            if (table[newIndex] == -1)
            {
                table[newIndex] = key;
                return;
            }
        }
        cout << "Hash table full, cannot insert " << key << endl;
    }

    bool search(int key)
    {
        int index = hash(key);

        for (int i = 0; i < size; i++)
        {
            int newIndex = (index + i * i) % size;

            if (table[newIndex] == key)
                return true;
            if (table[newIndex] == -1)
                return false;
        }
        return false;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
            cout << i << " -> " << table[i] << endl;
    }
};
bool isAnagram(string s1, string s2)
{
    HashTable ht(26);
    for (int i = 0; i < s1.length(); i++)
    {
        char c = s1[i];
        string x(1, c);
        int freq;
        if (ht.get(x, freq))
            ht.insert(x, freq + 1);
        else
            ht.insert(x, 1);
    }
    for (int i = 0; i < s2.length(); i++)
    {
        char c = s2[i];
        string x(1, c);
        int freq;
        if (!ht.get(x, freq))
            return false;
        ht.insert(x, freq - 1);
    }
    return true;
}
void wordfrequency(string arr[], int n)
{
    HashTable h(n * 2);
    for (int i = 0; i < n; i++)
    {
        int freq;
        if (h.get(arr[i], freq))
            h.insert(arr[i], freq + 1);
        else
            h.insert(arr[i], 1);
    }
    cout << "Word Frequency:" << endl;
    h.display();
}
void removeDuplicatesLPTask(int arr[], int n)
{
    cout << " Remove Duplicates " << endl;
    HashTableLP lp(2 * n);
    for (int i = 0; i < n; i++)
    {
        if (!lp.search(arr[i]))
            lp.insert(arr[i]);
    }
    lp.display();
}
void unionArraysLPTask(int A[], int n1, int B[], int n2)
{
    cout << " Union of Two Arrays (Linear Probing) " << endl;
    HashTableLP lp(2 * (n1 + n2));

    for (int i = 0; i < n1; i++)
        if (!lp.search(A[i]))
            lp.insert(A[i]);
    for (int i = 0; i < n2; i++)
        if (!lp.search(B[i]))
            lp.insert(B[i]);

    lp.display();
}

int main()
{
    HashTable ht(10);
    ht.insert("Abd", 90);
    ht.insert("ali", 85);
    ht.insert("raza", 92);
    ht.insert("Dawood", 88);
    ht.insert("ahmad", 95);
    cout << "Initial Hash Table:"<<endl;
    ht.display();
    int val;
    if (ht.get("raza", val))
        cout<<endl << "raza's Marks: " << val << endl;

    ht.remove("ali");
    cout<<endl << "After removing ali:"<<endl;
    ht.display();
    // frequency counter
    string arr[] = {"apple", "mango", "apple", "mango", "banana", "apple"};
    int n = 6;
    cout << "Word Frequency:" << endl;
    wordfrequency(arr, n);
    // anagrams
    cout << (isAnagram("listen", "silent") ? "Yes" : "No");
    // remove dup
    int arrLP[] = {5, 3, 7, 3, 5, 9};
    removeDuplicatesLPTask(arrLP, 6);
    // union
    int A[] = {1, 2, 3, 4};
    int B[] = {3, 4, 5, 6};
    unionArraysLPTask(A, 4, B, 4);
}
