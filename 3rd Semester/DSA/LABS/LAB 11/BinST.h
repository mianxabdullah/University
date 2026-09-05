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

    int heightPrvt(Node<T> *curr)
    {
        if (curr == NULL)
            return -1;
        return 1 + max(heightPrvt(curr->left), heightPrvt(curr->right));
    }

    int countNodesPrvt(Node<T> *curr)
    {
        if (curr == NULL)
            return 0;
        return 1 + countNodesPrvt(curr->left) + countNodesPrvt(curr->right);
    }

    int countLeavesPrvt(Node<T> *curr)
    {
        if (curr == NULL)
            return 0;
        if (curr->left == NULL && curr->right == NULL)
            return 1;
        return countLeavesPrvt(curr->left) + countLeavesPrvt(curr->right);
    }

    int countInternalPrvt(Node<T> *curr)
    {
        if (curr == NULL || (curr->left == NULL && curr->right == NULL))
            return 0;
        return 1 + countInternalPrvt(curr->left) + countInternalPrvt(curr->right);
    }

    bool isBSTPrvt(Node<T> *curr, T *minv, T *maxv)
    {
        if (curr == NULL)
            return true;
        if ((minv && curr->data <= *minv) || (maxv && curr->data >= *maxv))
            return false;
        return isBSTPrvt(curr->left, minv, &curr->data) &&
               isBSTPrvt(curr->right, &curr->data, maxv);
    }

    void clearPrvt(Node<T> *curr)
    {
        if (curr == NULL)
            return;
        clearPrvt(curr->left);
        clearPrvt(curr->right);
        delete curr;
    }

    void mirrorPrvt(Node<T> *curr)
    {
        if (curr == NULL)
            return;
        swap(curr->left, curr->right);
        mirrorPrvt(curr->left);
        mirrorPrvt(curr->right);
    }

    Node<T> *clonePrvt(Node<T> *curr)
    {
        if (!curr)
            return NULL;
        Node<T> *n = new Node<T>(curr->data);
        n->left = clonePrvt(curr->left);
        n->right = clonePrvt(curr->right);
        return n;
    }

    int countLevelPrvt(Node<T> *curr, int level)
    {
        if (curr == NULL)
            return 0;
        if (level == 0)
            return 1;
        return countLevelPrvt(curr->left, level - 1) +
               countLevelPrvt(curr->right, level - 1);
    }
    bool identicalPrvt(Node<T> *a, Node<T> *b)
    {
        if (a == NULL && b == NULL)
            return true;
        if (a == NULL || b == NULL)
            return false;

        return (a->data == b->data &&
                identicalPrvt(a->left, b->left) &&
                identicalPrvt(a->right, b->right));
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
            if (minNode == NULL)
                return;
            swap(curr->data, minNode->data);
            Node<T> *minPar = getParent(root, mini);
            if (minPar->left == minNode)
            {
                minPar->left = minNode->right;
            }
            else
                minPar->right = minNode->right;

            delete minNode;
        }
    }

    int height()
    {
        return heightPrvt(root);
    }

    int countNodes()
    {
        return countNodesPrvt(root);
    }

    int countLeaves()
    {
        return countLeavesPrvt(root);
    }

    int countInternalNodes()
    {
        return countInternalPrvt(root);
    }

    void levelOrder()
    {
        if (root == NULL)
            return;

        queue<Node<T> *> q;
        q.push(root);

        while (!q.empty())
        {
            Node<T> *curr = q.front();
            q.pop();

            cout << curr->data << " ";

            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
    }

    bool isBST()
    {
        return isBSTPrvt(root, NULL, NULL);
    }

    T successor(T v)
    {
        Node<T> *curr = getNode(v);
        if (curr == NULL)
            return T();

        if (curr->right != NULL)
            return min(curr->right);

        Node<T> *succ = NULL;
        Node<T> *a = root;

        while (a != NULL)
        {
            if (v < a->data)
            {
                succ = a;
                a = a->left;
            }
            else
                a = a->right;
        }
        return (succ ? succ->data : T());
    }

    T predecessor(T v)
    {
        Node<T> *curr = getNode(v);
        if (curr == NULL)
            return T();

        if (curr->left != NULL)
            return max(curr->left);

        Node<T> *pred = NULL;
        Node<T> *a = root;

        while (a != NULL)
        {
            if (v > a->data)
            {
                pred = a;
                a = a->right;
            }
            else
                a = a->left;
        }
        return (pred ? pred->data : T());
    }

    void mirror()
    {
        mirrorPrvt(root);
    }

    BST<T> cloneTree()
    {
        BST<T> newTree;
        newTree.root = clonePrvt(root);
        return newTree;
    }

    int countLevel(int level)
    {
        return countLevelPrvt(root, level);
    }

    bool identical(BST<T> &other)
    {
        return identicalPrvt(root, other.root);
    }

    bool isEmpty()
    {
        return root == NULL;
    }

    void clear()
    {
        clearPrvt(root);
        root = NULL;
    }
};
#endif
