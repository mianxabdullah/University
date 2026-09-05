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
    void destroy(Node<T> *curr)
    {
        if (curr == NULL)
            return;
        destroy(curr->left);
        destroy(curr->right);
        delete curr;
    }

    bool recSearchPrvt(Node<T> *cur, T k)
    {
        if (cur == NULL)
        {
            return false;
        }
        if (cur->data == k)
        {
            return true;
        }
        if (k < cur->data)
        {
            return    recSearchPrvt(cur->left, k);
        }
        else
        {
            return    recSearchPrvt(cur->right, k);
        }
    }
    int countNodesPrvt(Node<T> *curr)
    {
        if (curr == NULL)
        {
            return 0;
        }
        return 1 + countNodesPrvt(curr->left) + countNodesPrvt(curr->right);
    }
    int heightPrvt(Node<T> *curr)
    {
        if (curr == NULL)
        {
            return -1;
        }
        return 1 + max(heightPrvt(curr->left), heightPrvt(curr->right));
    }
    void doublePrvt(Node<T> *curr)
    {
        if (curr == NULL)
        {
            return;
        }
        doublePrvt(curr->left);
        doublePrvt(curr->right);
        if (curr != NULL)
        {
            Node<T> *newNode = new Node<T>(curr->data);
            newNode->left = curr->left;
            curr->left = newNode;
        }
    }
    
    void allpathPrvt(Node<T> *curr, int arr[], int n)
    {
        if (curr == NULL)
        {
            return;
        }
        arr[n] = curr->data;
        if (curr->left == NULL && curr->right == NULL)
        {
            for (int i = 0; i <= n; i++)
            {
                cout << arr[i];
                if (i<n)
                {
                    cout << "->";
                }
            }
            cout << endl;
            return;
        }
        allpathPrvt(curr->left, arr, n + 1);
        allpathPrvt(curr->right, arr, n + 1);
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
    T minimum(Node<T> *n)
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
    T maximum(Node<T> *n)
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
            T mini = minimum(curr->right);
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
    ~BST()
    {
        destroy(root);
        root = NULL;
    }
    bool recSearch(int key)
    {
        return recSearchPrvt(root, key);
    }
    int countNodes()
    {
        return countNodesPrvt(root);
    }
    int height()
    {
        return heightPrvt(root);
    }

    void doubleTree()
    {
        doublePrvt(root);
    }

    void printAllPaths()
    {
        int a[100];
        for (int i = 0; i < 100; i++)
        {
            a[i] = 0;
        }
        allpathPrvt(root, a, 0);
    }
};
int main()
{
    BST<int> tree;
    tree.insert(29);
    tree.insert(2);
    tree.insert(6);
    tree.insert(31);
    tree.insert(18);
    tree.inorder();
    if (tree.recSearch(31))
    {
        cout << "Found" << endl;
    }
    cout << "Count Nodes: " << tree.countNodes() << endl;
    cout << "Height: " << tree.height() << endl;

    BST<int> t;
    t.insert(2);
    t.insert(1);
    t.insert(3);
    t.doubleTree();
    t.inorder();
    cout << endl;
    tree.printAllPaths();
}