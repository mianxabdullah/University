#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;
class Student
{
public:
    double cgpa;
    int rollNo;
    Student()
    {
        cgpa = 0.0;
        rollNo = 0;
    }
    Student(int r, double c)
    {
        rollNo = r;
        cgpa = c;
    }
};
class StudentMaxHeap
{
private:
    Student *st;
    int currSize;
    int maxSize;

    bool isGreater(const Student &a, const Student &b)
    {
        if (a.cgpa > b.cgpa)
        {
            return true;
        }
        if (a.cgpa < b.cgpa)
        {
            return false;
        }
        if (a.cgpa == b.cgpa)
        {
            if (a.rollNo > b.rollNo)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }

    void heap_up(int i)
    {
        int parent = (i - 1) / 2;
        while (i != 0 && st[i].cgpa >= st[parent].cgpa)
        {
            if (st[i].cgpa == st[parent].cgpa)
            {
                if (st[i].rollNo < st[parent].rollNo)
                {
                    swap(st[i], st[parent]);
                }
            }
            else if (st[i].cgpa > st[parent].cgpa)
            {
                swap(st[i], st[parent]);
            }
            i = parent;
            parent = (i - 1) / 2;
        }
    }

    void heap_down(int i)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int max = i;
        if (left < currSize && st[left].cgpa > st[max].cgpa)
            max = left;
        else if (left < currSize && st[left].cgpa == st[max].cgpa)
        {
            if (st[left].rollNo < st[max].rollNo)
                max = left;
        }

        if (right < currSize && st[right].cgpa > st[max].cgpa)
            max = right;
        else if (right < currSize && st[right].cgpa == st[max].cgpa)
        {
            if (st[right].rollNo < st[max].rollNo)
                max = right;
        }
        if (max != i)
        {
            swap(st[i], st[max]);
            heap_down(max);
        }
    }

public:
    StudentMaxHeap(int size)
    {
        currSize = 0;
        maxSize = size;
        st = new Student[size];
    }
    ~StudentMaxHeap()
    {
        delete[] st;
    }
    bool isEmpty()
    {
        return (currSize == 0);
    }
    bool isFull()
    {
        return (currSize == maxSize);
    }

    bool insert(int r, double c)
    {
        if (currSize < maxSize)
        {
            st[currSize].cgpa = c;
            st[currSize].rollNo = r;
            int i = currSize;
            currSize++;
            heap_up(i);
            return true;
        }
        else
        {
            return false;
        }
    }
    bool removeBestStudent(int &rollNo, double &cgpa)
    {
        if (currSize == 0)
        {
            return false;
        }
        rollNo = st[0].rollNo;
        cgpa = st[0].cgpa;
        swap(st[currSize - 1], st[0]);
        currSize--;
        heap_down(0);
        return true;
    }

    void LevelOrder()
    {
        for (int i = 0; i < currSize; i++)
            cout << "RollNo: " << st[i].rollNo << " Cgpa: " << st[i].cgpa << endl;
        cout << endl;
    }

    int height()
    {
        int h = ceil(log2(currSize + 1));
        return h;
    }
};
void print(string input)
{
    vector<pair<char, int>> freq(26, pair<char, int>(0, 0));
    char c = 'A';
    for (int i = 0; i < 26; i++)
    {
        freq[i].first = char(c + i);
        freq[i].second = 0;
    }
    for (char a : input)
    {
        freq[a - 65].second += 1;
    }
    sort(freq.begin(), freq.end(), [](const pair<char, int> &a, const pair<char, int> &b)
         { return a.second < b.second; });

    for(int i=0;i<26;i++)
    {
        while(freq[i].second!=0)
        {
            cout<<freq[i].first;
            freq[i].second--;
        }
    }
}

int nonrep(vector<int> in)
{
    sort(in.begin(),in.end());
    vector<int> v;
    int temp=in[0];
    for(int i=1;i<in.size();i++)
    {
        if(temp!=in[i])
        {
            temp=in[i];
        }
    }
    return temp;
}


int main()
{
    StudentMaxHeap heap(20);
    heap.insert(10, 3.2);
    heap.insert(5, 3.9);
    heap.insert(12, 3.5);
    heap.insert(3, 3.9);
    heap.insert(7, 2.8);
    heap.insert(18, 3.7);
    heap.insert(1, 4.0);
    heap.insert(20, 3.4);
    heap.insert(11, 3.7);
    heap.insert(4, 3.8);
    cout << "===== Level Order After Insertions =====\n";
    heap.LevelOrder();
    cout << endl;

    cout << "\nHeight of the heap: " << heap.height() << endl;
    int roll;
    double cg;
    if (heap.removeBestStudent(roll, cg))
    {
        cout << "Removed Student - Roll No: " << roll
             << ", CGPA: " << cg << endl;
    }
    if (heap.removeBestStudent(roll, cg))
    {
        cout << "Removed Student - Roll No: " << roll
             << ", CGPA: " << cg << endl;
    }
    cout << "\n===== Level Order After Two Removals =====\n";
    heap.LevelOrder();
    cout << "\nHeight of the heap: " << heap.height() << endl;

    cout << "Task 2:" << endl;

    string st="DACDACCDCBC";
    print(st);

    cout<<endl << "Task 3:" << endl;
    vector<int> a={4,5,6,7,4,6,5,6,4,5,5,6};
    int x=nonrep(a);
    cout<<x;
}
