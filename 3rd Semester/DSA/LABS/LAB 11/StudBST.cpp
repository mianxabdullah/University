#ifndef BST_H
#define BST_H

#include <iostream>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

template <typename T>
class Node
{
public:
    int rollNo;
    string name;
    double cgpa;
    Node<T> *left;
    Node<T> *right;

    Node(int r, string n, double c)
    {
        rollNo = r;
        name = n;
        cgpa = c;
        left = NULL;
        right = NULL;
    }
};
template <typename T>
class BST
{
private:
    Node<T> *root;
    void inorderPrvt(Node<T> *curr)
    {
        if (curr == NULL)
        {
            return;
        }
        inorderPrvt(curr->left);
        cout << curr->rollNo << " " << curr->name << " " << curr->cgpa << endl;
        inorderPrvt(curr->right);
    }
    void inRangePrvt(Node<T> *curr, double st, double end)
    {
        if ((curr == NULL))
        {
            return;
        }
        inRangePrvt(curr->left, st, end);
        if ((curr->cgpa <= end && curr->cgpa >= st))
        {
            cout << curr->rollNo << " " << curr->name << " " << curr->cgpa << endl;
        }
        inRangePrvt(curr->right, st, end);
    }
    void preorderPrvt(Node<T> *curr)
    {
        if (curr == NULL)
        {
            return;
        }
        cout << curr->data << " ";
        preorderPrvt(curr->left);
        preorderPrvt(curr->right);
    }
    void postorderPrvt(Node<T> *curr)
    {
        if (curr == NULL)
        {
            return;
        }
        postorderPrvt(curr->left);
        postorderPrvt(curr->right);
        cout << curr->data << " ";
    }
    void destroy(Node<T> *curr)
    {
        if (curr == NULL)
            return;
        destroy(curr->left);
        destroy(curr->right);
        delete curr;
    }

public:
    BST()
    {
        root = NULL;
    }
    bool insert(int r, string n, double c)
    {
        if (root == NULL)
        {
            root = new Node<T>(r, n, c);
            return true;
        }
        if (search(r))
        {
            cout << "Already Exist" << endl;
            return false;
        }
        else
        {
            Node<T> *curr = root;
            Node<T> *pre = NULL;
            while (curr != NULL)
            {
                if (r < curr->rollNo)
                {
                    pre = curr;
                    curr = curr->left;
                }
                else
                {
                    pre = curr;
                    curr = curr->right;
                }
            }
            if (r < pre->rollNo)
                pre->left = new Node<T>(r, n, c);
            else
                pre->right = new Node<T>(r, n, c);

            return true;
        }
    }
    bool search(int r)
    {
        Node<T> *curr = root;
        while (curr != NULL)
        {
            if (curr->rollNo == r)
            {
                cout << curr->rollNo << " " << curr->name << " " << curr->cgpa << endl;
                return true;
            }
            if (r < curr->rollNo)
                curr = curr->left;
            else
                curr = curr->right;
        }
        return false;
    }
    ~BST()
    {
        destroy(root);
        root = NULL;
    }

    void preorder()
    {
        preorderPrvt(root);
    }
    void postorder()
    {
        postorderPrvt(root);
    }
    void inorder()
    {
        inorderPrvt(root);
    }
    Node<T> *getNode(T r)
    {
        Node<T> *curr = root;
        while (curr != NULL)
        {
            if (curr->rollNo == r)
                return curr;
            if (r < curr->data)
                curr = curr->left;
            else
                curr = curr->right;
        }
        return NULL;
    }
    Node<T> *getParent(Node<T> *cur, T r)
    {
        if (cur == NULL)
        {
            return NULL;
        }
        if (cur->rollNo == r)
        {
            return NULL;
        }
        if ((cur->left != NULL && cur->left->rollNo == r) || (cur->right != NULL && cur->right->rollNo == r))
        {
            return cur;
        }
        Node<T> *t = getParent(cur->left, r);
        if (t == NULL)
        {
            t = getParent(cur->right, r);
        }
        return t;
    }
    T min(Node<T> *n)
    {
        if (n == NULL)
        {
            return T();
        }
        Node<T> *curr = n;
        while (curr->left != NULL)
        {
            curr = curr->left;
        }
        return curr->data;
    }
    T max(Node<T> *n)
    {
        if (n == NULL)
        {
            return T();
        }
        Node<T> *curr = n;
        while (curr->right != NULL)
        {
            curr = curr->right;
        }
        return curr->data;
    }
    bool remove(int r)
    {
        if (search(r))
        {
            if (root == NULL)
            {
                return false;
            }
            Node<T> *curr = getNode(r);
            Node<T> *p = getParent(root, r);
            if (curr->left == NULL && curr->right == NULL)
            {
                if (p == NULL)
                {
                    delete curr;
                    root = NULL;
                    return true;
                }
                if (p->left == curr)
                {
                    p->left = NULL;
                }
                else
                    p->right = NULL;

                delete curr;
                return true;
            }
            if ((curr->left == NULL && curr->right != NULL) || (curr->left != NULL && curr->right == NULL))
            {
                if (p == NULL)
                {
                    if (curr->right != NULL)
                    {
                        root = curr->right;
                    }
                    else
                        root = curr->left;
                    delete curr;
                    return true;
                }
                if (p->left == curr)
                {
                    if (curr->left != NULL)
                    {
                        p->left = curr->left;
                    }
                    else
                        p->left = curr->right;
                }
                else if (p->right == curr)
                {
                    if (curr->right != NULL)
                    {
                        p->right = curr->right;
                    }
                    else
                        p->right = curr->left;
                }
                delete curr;
                return true;
            }
            if (curr->left != NULL && curr->right != NULL)
            {
                T mini = min(curr->right);
                Node<T> *minNode = getNode(mini);
                if (minNode == NULL)
                    return false;
                swap(curr->rollNo, minNode->rollNo);
                swap(curr->name, minNode->name);
                swap(curr->cgpa, minNode->cgpa);
                Node<T> *minPar = getParent(root, mini);
                if (minPar->left == minNode)
                {
                    minPar->left = minNode->right;
                }
                else
                    minPar->right = minNode->right;

                delete minNode;
                return true;
            }
        }
        else
        {
            return false;
        }
    }

    void displayInRange(double cgpaS, double cgpaE)
    {
        inRangePrvt(root, cgpaS, cgpaE);
    }
};
#endif
void menu()
{
    BST<int> a;
    int ch;
    while (ch != 4)
    {
        cout << "1.  Insert a new student  \n2.  Search for a student  \n3.  See the list of students  \n4.  Quit  \nEnter your choice: ";
        cin >> ch;
        if (ch == 1)
        {
            int r;
            string n;
            double c;
            cout << endl
                 << "enter rollno,name,cgpa you want to insert" << endl;
            cin >> r >> n >> c;
            if (a.insert(r, n, c))
            {
                cout << "\nInserted\n";
            }
        }
        if (ch == 2)
        {
            int r;
            cout << endl
                 << "enter rollno you want to search" << endl;
            cin >> r;
            if (a.search(r))
            {
                cout << "\nfound\n";
            }
        }
        if (ch == 3)
        {
            a.inorder();
        }
        if (ch == 4)
        {
            return;
        }
    }
}
int main()
{
    menu();
    BST<int> tree;
    tree.insert(29, "abd", 3.91);
    tree.insert(2, "has", 3.87);
    tree.insert(6, "huz", 3.84);
    tree.insert(31, "ahad", 3.55);
    tree.insert(18, "sufi", 3.26);
    tree.displayInRange(3.25, 3.85);
}