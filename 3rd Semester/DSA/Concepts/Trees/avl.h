#ifndef AVL_H
#define AVL_H

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
    int height;
    Node(T v)
    {
        data = v;
        height = 1;
        left = right = NULL;
    }
};
template <typename T>
class AVL
{
private:
    Node<T> *root;
    int getHeight(Node<T> *curr)
    {
        if (curr == NULL)
            return 0;
        return curr->height;
    }
    int heightPrvt(Node<T> *curr)
    {
        if (curr == NULL)
            return 0;
        return 1 + max(getHeight(curr->left), getHeight(curr->right));
    }
    int balancefactor(Node<T> *curr)
    {
        if (curr == NULL)
            return 0;
        return getHeight(curr->left) - getHeight(curr->right);
    }

    Node<T> *LL(Node<T> *gp)
    {
        Node<T> *par = gp->left;
        gp->left = par->right;
        par->right = gp;
        gp->height = max(getHeight(gp->left), getHeight(gp->right)) + 1;
        par->height = max(getHeight(par->left), getHeight(par->right)) + 1;
        return par;
    }

    Node<T> *RR(Node<T> *gp)
    {
        Node<T> *par = gp->right;
        gp->right = par->left;
        par->left = gp;
        gp->height = max(getHeight(gp->left), getHeight(gp->right)) + 1;
        par->height = max(getHeight(par->left), getHeight(par->right)) + 1;
        return par;
    }

    Node<T> *LR(Node<T> *gp)
    {
        gp->left = RR(gp->left);
        return LL(gp);
    }

    Node<T> *RL(Node<T> *gp)
    {
        gp->right = LL(gp->right);
        return RR(gp);
    }

    Node<T> *balance(Node<T> *curr)
    {
        if (curr == NULL)
            return NULL;

        curr->height = max(getHeight(curr->left), getHeight(curr->right)) + 1;
        int bf = balancefactor(curr);

        if (abs(bf) <= 1) // already balanced
            return curr;
        if (bf == 2)
        {
            int bfl = balancefactor(curr->left);
            if (bfl >= 0) // bfl=1 ||0
                return LL(curr);
            else // bfl=-1
                return LR(curr);
        }
        if (bf == -2)
        {
            int bfr = balancefactor(curr->right);
            if (bfr <= 0) // bfr=-1 || 0
                return RR(curr);
            else // bfr=1
                return RL(curr);
        }
        return curr;
    }

    Node<T> *insertPrvt(Node<T> *curr, T key)
    {
        if (curr == NULL)
            return new Node<T>(key);
        if (key < curr->data)
            curr->left = insertPrvt(curr->left, key);
        else if (key > curr->data)
            curr->right = insertPrvt(curr->right, key);
        else
            return curr;// duplicate keys not allowed

        return balance(curr);
    }

    Node<T> *removePrvt(Node<T> *curr, T d)
    {
        if (curr == NULL)
            return NULL;
        if (curr->data > d)
            curr->left = removePrvt(curr->left, d);
        else if (curr->data < d)
            curr->right = removePrvt(curr->right, d);
        else
        {
            if (curr->left == NULL && curr->right == NULL)
            {
                delete curr;
                return NULL;
            }
            else if (curr->left == NULL && curr->right != NULL)
            {

                Node<T> *currR = curr->right;
                delete curr;
                return currR;
            }
            else if (curr->left != NULL && curr->right == NULL)
            {

                Node<T> *currL = curr->left;
                delete curr;
                return currL;
            }
            else
            {
                Node<T> *minNode = minimum(curr->right);
                curr->data = minNode->data;
                curr->right = removePrvt(curr->right, curr->data);
            }
        }
        return balance(curr);
    }
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

    Node<T> *minimum(Node<T> *n)
    {
        if (n == NULL)
        {
            return NULL;
        }
        Node<T> *curr = n;
        while (curr->left != NULL)
        {
            curr = curr->left;
        }
        return curr;
    }
    Node<T> *maximum(Node<T> *n)
    {
        if (n == NULL)
        {
            return NULL;
        }
        Node<T> *curr = n;
        while (curr->right != NULL)
        {
            curr = curr->right;
        }
        return curr;
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
    AVL()
    {
        root = NULL;
    }
    void insert(T v)
    {
        root = insertPrvt(root, v);
    }
    void remove(T d)
    {
        root = removePrvt(root, d);
    }
    void preorder()
    {
        cout << "PreOrder: ";
        preorderPrvt(root);
        cout << endl;
    }
    void postorder()
    {
        cout << "PostOrder: ";
        postorderPrvt(root);
        cout << endl;
    }
    void inorder()
    {
        cout << "InOrder: ";
        inorderPrvt(root);
        cout << endl;
    }
    int height()
    {
        return getHeight(root);
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
    Node<T> *getParent(T value)
    {
        Node<T> *parent = NULL;
        Node<T> *curr = root;
        while (curr != NULL)
        {
            if (value == curr->data)
                return parent;
            parent = curr;
            if (value < curr->data)
                curr = curr->left;
            else
                curr = curr->right;
        }
        return NULL;
    }
    void LevelOrder()
    {
        queue<Node<T> *> q;
        q.push(root);
        while (!q.empty())
        {
            Node<T> *cur = q.front();
            q.pop();
            cout << cur->data << " ";
            if (cur->left)
            {
                q.push(cur->left);
            }
            if (cur->right)
            {
                q.push(cur->right);
            }
        }
    }

    ~AVL()
    {
        destroy(root);
    }
};
#endif
