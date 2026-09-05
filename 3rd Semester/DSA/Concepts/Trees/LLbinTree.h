#ifndef LLBINARYTREE_H
#define LLBINARYTREE_H

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
class BinaryTree
{
private:
    Node<T> *root;

    void deleteSubtree(Node<T> *cur)
    {
        if (cur == NULL)
            return;
        deleteSubtree(cur->left);
        deleteSubtree(cur->right);
        delete cur;
    }

    void displayLevel(Node<T> *cur, int levelno)
    {
        if (cur == NULL)
            return;

        if (levelno == 0)
        {
            cout << cur->data << " ";
            return;
        }

        displayLevel(cur->left, levelno - 1);
        displayLevel(cur->right, levelno - 1);
    }
    int SumLevel(Node<T> *cur, int levelno)
    {
        if (cur == NULL)
            return 0;

        if (levelno == 0)
        {
            return cur->data;
        }

        int a = SumLevel(cur->left, levelno - 1);
        int b = SumLevel(cur->right, levelno - 1);
        return a + b;
    }

    void preorder(Node<T> *cur)
    {
        if (cur == NULL)
            return;
        cout << cur->data << " ";
        preorder(cur->left);
        preorder(cur->right);
    }

    void postorder(Node<T> *cur)
    {
        if (cur == NULL)
            return;
        postorder(cur->left);
        postorder(cur->right);
        cout << cur->data << " ";
    }

    void inorder(Node<T> *cur)
    {
        if (cur == NULL)
            return;
        inorder(cur->left);
        cout << cur->data << " ";
        inorder(cur->right);
    }

    void displayParenthesizedView(Node<T> *cur)
    {
        if (cur == NULL)
        {
            return;
        }
        cout << cur->data;
        if (cur->left != NULL)
        {
            cout << " (";
            displayParenthesizedView(cur->left);
            if (cur->right == NULL)
            {
                cout << ", ) ";
            }
        }
        if (cur->right != NULL)
        {
            if (cur->left == NULL)
            {
                cout << " ( ,";
            }
            displayParenthesizedView(cur->right);
            cout << " ) ";
        }
    }
    void mirrorhelper(Node<T> *cur)
    {
        if (cur == NULL)
            return;
        mirrorhelper(cur->left);
        mirrorhelper(cur->right);
        swap(cur->left, cur->right);
    }
    Node<T> *copySubtree(Node<T> *org)
    {
        if (org == NULL)
            return NULL;
        Node<T> *newNode = new Node<T>(org->data);
        newNode->left = copySubtree(org->left);
        newNode->right = copySubtree(org->right);
        return newNode;
    }

public:
    BinaryTree()
    {
        root = NULL;
    }

    void setRoot(T val)
    {
        if (root == NULL)
        {
            root = new Node<T>(val);
        }
    }

    T getRoot()
    {
        if (root != NULL)
        {
            return root->data;
        }
    }

    Node<T> *getRootNode()
    {
        if (root != NULL)
        {
            return root;
        }
    }

    Node<T> *search(Node<T> *cur, T p)
    {
        if (cur == NULL)
        {
            return NULL;
        }
        if (cur->data == p)
        {
            return cur;
        }
        Node<T> *t = search(cur->left, p);
        if (t == NULL)
        {
            t = search(cur->right, p);
        }
        return t;
    }
    void setLeftChild(T p, T lc)
    {
        Node<T> *n = search(root, p);
        if (n != NULL)
        {
            n->left = new Node<T>(lc);
        }
    }

    void setRightChild(T p, T lc)
    {
        Node<T> *n = search(root, p);
        if (n != NULL)
        {
            n->right = new Node<T>(lc);
        }
    }

    void displaypre()
    {
        preorder(root);
    }
    void displaypost()
    {
        postorder(root);
    }
    void displayin()
    {
        inorder(root);
    }
    void displayParenthesized()
    {
        displayParenthesizedView(root);
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
    T findNodeSiblings(T node)
    {
        Node<T> *p = getParent(root, node);
        if (p->left != NULL && p->left->data == node)
        {
            if (p->right != NULL)
            {
                return p->right->data;
            }
            else
                return T();
        }
        if (p->right != NULL && p->right->data == node)
        {
            if (p->left != NULL)
            {
                return p->left->data;
            }
            else
                return T();
        }
    }
    bool isExternalNode(T node)
    {
        Node<T> *n = search(root, node);
        if (n->left == NULL && n->right == NULL)
        {
            return true;
        }
        return false;
    }
    bool isInternalNode(T node)
    {
        Node<T> *n = search(root, node);
        if (n->left != NULL || n->right != NULL)
        {
            return true;
        }
        return false;
    }
    BinaryTree<T> operator=(BinaryTree<T> &b)
    {
        if (b.getRootNode() != NULL)
            root = b.root;

        return *this;
    }
    BinaryTree(const BinaryTree<T> &other)
    {
        if (other.root == NULL)
            root = NULL;
        else
            root = copySubtree(other.root);
    }
    BinaryTree<T> getMirrorImage()
    {
        BinaryTree<T> a(*this);
        mirrorhelper(a.getRootNode());
        return a;
    }
    void remove(T v)
    {
        Node<T> *p = getParent(root, v);
        if (p != NULL)
        {
            if (p->left != NULL && p->left->data == v)
            {
                deleteSubtree(p->left);
                p->left = NULL;
            }
            else if (p->right != NULL && p->right->data == v)
            {
                deleteSubtree(p->right);
                p->right = NULL;
            }
        }
    }

    void DisplayAncestors(T val)
    {
        if (val == getRoot() || search(root, val) == NULL)
        {
            return;
        }
        else
        {
            Node<T> *p = getParent(root, val);
            if (p != NULL)
            {
                cout << p->data << " ";
                DisplayAncestors(p->data);
            }
        }
    }
    void DisplayDecendents(T val)
    {
        if (search(root, val) == NULL)
        {
            return;
        }
        Node<T> *n = search(root, val);
        preorder(n->left);
        preorder(n->right);
    }
    int height(Node<T> *cur)
    {
        if (cur == NULL)
            return 0;
        int leftHeight = height(cur->left);
        int rightHeight = height(cur->right);
        return 1 + max(leftHeight, rightHeight);
    }
    int findLevelOfNode(T val)
    {
        if (root == NULL || search(root, val) == NULL)
            return -1;
        if (val == getRoot())
        {
            return 0;
        }
        Node<T> *p = getParent(root, val);
        if (p == NULL)
            return -1;
        return 1 + findLevelOfNode(p->data);
    }

    void displayLevel(int levelno)
    {
        displayLevel(root, levelno);
        cout << endl;
    }

    bool isEmpty() const
    {
        return (root == NULL);
    }

    void sum(int levelno)
    {
        int x = SumLevel(root, levelno);
        cout << x << endl;
    }
    int countLeafNodes(Node<T> *node)
    {
        if (!node)
            return 0;
        if (!node->left && !node->right)
            return 1;
        return countLeafNodes(node->left) + countLeafNodes(node->right);
    }

    int countNonLeafNodes(Node<T> *node)
    {
        if (!node || (!node->left && !node->right))
            return 0;
        return 1 + countNonLeafNodes(node->left) + countNonLeafNodes(node->right);
    }

    T sumNodes(Node<T> *node)
    {
        if (node==NULL)
            return T();
        return node->data + sumNodes(node->left) + sumNodes(node->right);
    }

    T findMax(Node<T> *node)
    {
        if (node == NULL)
            return T();

        T res = node->data;
        if (node->left != NULL)
        {
            T lres = findMax(node->left);
            if (lres > res)
                res = lres;
        }
        if (node->right != NULL)
        {
            T rres = findMax(node->right);
            if (rres > res)
                res = rres;
        }
        return res;
    }

    T findMin(Node<T> *node)
    {
        if (!node)
            return T();

        T res = node->data;
        if (node->left)
        {
            T lres = findMin(node->left);
            if (lres < res)
                res = lres;
        }
        if (node->right)
        {
            T rres = findMin(node->right);
            if (rres < res)
                res = rres;
        }
        return res;
    }

    int diameter(Node<T> *node)
    {
        if (!node)
            return 0;
        int lh = height(node->left);
        int rh = height(node->right);
        int ld = diameter(node->left);
        int rd = diameter(node->right);
        return max(lh + rh + 1, max(ld, rd));
    }
    ~BinaryTree()
    {
        deleteSubtree(root);
        root = NULL;
    }
};
#endif
