#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
class BinaryTree
{
private:
    int height;
    bool *status;
    T *data;

    void deleteSubtree(int index, int n) // n=size of array(2^h -1),index=delete subtree of that index
    {
        if (index >= n || status[index] == false || index == -1)
            return;
        status[index] = false;
        deleteSubtree(2 * index + 1, n);
        deleteSubtree(2 * index + 2, n);
    }

public:
    BinaryTree(int h)
    {
        height = h;
        int n = pow(2, h) - 1;
        data = new T[n];
        status = new bool[n];
        for (int i = 0; i < n; i++)
        {
            status[i] = false;
        }
    }

    void setRoot(T val)
    {
        if (status[0] == false)
        {
            data[0] = val;
            status[0] = true;
        }
    }
    T getRoot()
    {
        if (status[0] == true)
        {
            return data[0];
        }
    }
    void setLeftChild(T p, T lc)
    {
        int n = pow(2, height) - 1;
        for (int i = 0; i < n; i++)
        {
            if (status[i]==true && data[i] == p)
            {
                int left = 2 * i + 1;
                if (left < n && status[left]==false)
                {
                    data[left] = lc;
                    status[left] = true;
                }
            }
        }
    }

    void setRightChild(T p, T rc)
    {
        int n = pow(2, height) - 1;
        for (int i = 0; i < n; i++)
        {
            if (status[i] && data[i] == p)
            {
                int right = 2 * i + 2;
                if (right < n && status[right]==false)
                {
                    data[right] = rc;
                    status[right] = true;
                }
            }
        }
    }
    T getParent(T val)
    {
        int n = pow(2, height) - 1;
        for (int i = 1; i < n; i++)
        {
            if (status[i]==true && data[i] == val)
            {
                int parent = (i - 1) / 2;
                if (status[parent]==true)
                    return data[parent];
            }
        }
        cout << "Parent not found for " << val << endl;
        return T();
    }
    void DisplayAncestors(T val)
    {
        if (val == getRoot() || search(val) == false)
        {
            return;
        }
        else
        {
            T p = getParent(val);
            if (p != T())
            {
                cout << p << " ";
            }
            DisplayAncestors(p);
        }
    }
    void DisplayDecendents(T val)
    {
        if (search(val) == false)
        {
            return;
        }
        int ind = search_ind(val);
        preorder(2 * ind + 1);
        preorder(2 * ind + 2);
    }
    void heightOfTree()
    {
        if (height != 0)
        {
            cout << height << endl;
        }
    }
    int findLevelOfNode(T val)
    {
        if (val == getRoot())
        {
            return 0;
        }
        T p = getParent(val);
        return 1 + findLevelOfNode(p);
    }
    bool isEmpty() const
    {
        return (status[0] == false);
    }
    void displaylevel(int levelno)
    {
        int s = pow(2, levelno) - 1;
        int max = pow(2, levelno + 1) - 1;
        for (int i = s; i < max; i++)
        {
            if (status[i] == true)
            {
                cout << data[i] << " ";
            }
        }
        cout << endl;
    }
    void preorder(int index = 0)
    {
        int n = pow(2, height) - 1;
        if (index >= n || status[index] == false)
            return;
        cout << data[index] << " ";
        preorder(2 * index + 1);
        preorder(2 * index + 2);
    }

    void inorder(int index = 0)
    {
        int n = pow(2, height) - 1;
        if (index >= n || status[index] == false)
            return;
        inorder(2 * index + 1);
        cout << data[index] << " ";
        inorder(2 * index + 2);
    }

    void postorder(int index = 0)
    {
        int n = pow(2, height) - 1;
        if (index >= n || status[index] == false)
            return;
        postorder(2 * index + 1);
        postorder(2 * index + 2);
        cout << data[index] << " ";
    }

    void LevelOrder()
    {
        int n = pow(2, height) - 1;
        cout << "Level Order: ";
        for (int i = 0; i < n; i++)
        {
            if (status[i]==true)
                cout << data[i] << " ";
            else
                cout << "_ ";
        }
        cout << endl;
    }
    void displayParenthesis(int index = 0)
    {
        int n = pow(2, height) - 1;
        if (index >= n || status[index] == false)
        {
            return;
        }
        cout << data[index] ;
        int left=2*index+1;
        int right=2*index+2;
        if(left<n && status[left]==true)
        {
            cout<<" (";
            displayParenthesis(2 * index + 1);
            if(right>=n || status[right]==false)
            {
                cout<<", ) ";
            }
        }
        if(right<n && status[right]==true)
        {
            if(left>=n || status[left]==false)
            {
                cout<<" ( ,";
            }
            displayParenthesis(2 * index + 2);
            cout<<" ) ";
        }

    }

    bool search(T val)
    {
        int n = pow(2, height) - 1;
        for (int i = 0; i < n; i++)
        {
            if (status[i]==true && data[i] == val)
                return true;
        }
        return false;
    }
    int search_ind(T val)
    {
        int n = pow(2, height) - 1;
        for (int i = 0; i < n; i++)
        {
            if (status[i]==true && data[i] == val)
                return i;
        }
        return -1;
    }
    void removee(T v)
    {
        int ind = search_ind(v);
        int n = pow(2, height) - 1;
        deleteSubtree(ind, n);
    }
    ~BinaryTree()
    {
        delete[] status;
        delete[] data;
    }
};
#endif
