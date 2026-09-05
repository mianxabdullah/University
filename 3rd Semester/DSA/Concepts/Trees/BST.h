#ifndef BST_H
#define BST_H

#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *left;
    Node<T> *right;

    Node(T v)
    {
        data = v;
        left = right = NULL;
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
        cout << curr->data << " ";
        inorderPrvt(curr->right);
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
public:
    BST()
    {
        root = NULL;
    }
    void insert(T v)
    {
        if (root == NULL)
        {
            root = new Node<T>(v);
            return;
        }
        Node<T> *curr = root;
        Node<T> *pre = NULL;
        while (curr != NULL)
        {
            if (v < curr->data)
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
        if (v < pre->data)
            pre->left = new Node<T>(v);
        else
            pre->right = new Node<T>(v);
    }
    bool search(T v)
    {
        Node<T> *curr = root;
        while (curr != NULL)
        {
            if (curr->data == v)
                return true;
            if (v < curr->data)
                curr = curr->left;
            else
                curr = curr->right;
        }
        return false;
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
    Node<T> *getNode(T v)
    {
        Node<T> *curr = root;
        while (curr != NULL)
        {
            if (curr->data == v)
                return curr;
            if (v < curr->data)
                curr = curr->left;
            else
                curr = curr->right;
        }
        return NULL;
    }
    Node<T> *getParent(Node<T> *cur, T c)
    {
        if (cur == NULL)
        {
            return NULL;
        }
        if (cur->data == c)
        {
            return NULL;
        }
        if ((cur->left != NULL && cur->left->data == c) || (cur->right != NULL && cur->right->data == c))
        {
            return cur;
        }
        Node<T> *t = getParent(cur->left, c);
        if (t == NULL)
        {
            t = getParent(cur->right, c);
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
    void remove(T d)
    {
        if (root == NULL)
        {
            return;
        }
        Node<T> *curr = getNode(d);
        Node<T> *p = getParent(root, d);
        if (curr->left == NULL && curr->right == NULL)
        {
            if (p == NULL)
            {
                delete curr;
                root = NULL;
                return;
            }
            if (p->left == curr)
            {
                p->left = NULL;
            }
            else
                p->right = NULL;

            delete curr;
            return;
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
                return;
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
            return;
        }
        if (curr->left != NULL && curr->right != NULL)
        {
            T mini = min(curr->right);
            Node<T> *minNode = getNode(mini);
            Node<T> *minPar = getParent(root, mini);
            if (minNode == NULL)
                return;
            swap(curr->data, minNode->data);
            if (minPar->left == minNode)
            {
                minPar->left = minNode->right;
            }
            else
                minPar->right = minNode->right;

            delete minNode;
        }
    }
};
#endif