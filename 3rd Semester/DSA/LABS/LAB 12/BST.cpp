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
            recSearchPrvt(cur->left, k);
        }
        else
        {
            recSearchPrvt(cur->right, k);
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
                if (i < n)
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

    Node<T> *LL(Node<T> *gp)
    {
        Node<T> *par = gp->left;
        gp->left = par->right;
        par->right = gp;
        return par;
    }

    Node<T> *RR(Node<T> *gp)
    {
        Node<T> *par = gp->right;
        gp->right = par->left;
        par->left = gp;
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

    Node<T>* constructHelper(vector<int>& in_order, vector<int>& pre_order, 
                               int in_start, int in_end, int& pre_idx)
    {
        if (in_start > in_end)
        {
            return NULL;
        }
        
        Node<T>* node = new Node<T>(pre_order[pre_idx++]);
        
        if (in_start == in_end)
        {
            return node;
        }
        
        int in_idx = -1;
        for (int i = in_start; i <= in_end; i++)
        {
            if (in_order[i] == node->data)
            {
                in_idx = i;
                break;
            }
        }
        
        node->left = constructHelper(in_order, pre_order, in_start, in_idx - 1, pre_idx);
        node->right = constructHelper(in_order, pre_order, in_idx + 1, in_end, pre_idx);
        
        return node;
    }

    void construct_from_traversals(vector<int> in_order, vector<int> pre_order)
    {
        if (in_order.size() == 0 || pre_order.size() == 0)
        {
            return;
        }
        int pre_idx = 0;
        root = constructHelper(in_order, pre_order, 0, in_order.size() - 1, pre_idx);
    }
    
    void createBalanced(T *arr, int st, int end)
    {
        int m = (st + end) / 2;
        if (st > end)
        {
            return;
        }
        insert(arr[m]);
        createBalanced(arr, st, m - 1);
        createBalanced(arr, m + 1, end);
    }

    void createBackbone(Node<T> *&curr)
    {
        Node<T> *t = curr;
        while (t != NULL)
        {
            if (t->left != NULL)
            {
                t = LL(t);
            }
            else
            {
                t = t->right;
            }
        }
    }

    void createPerfectTree(Node<T> *&curr)
    {
        int n = countNodesPrvt(curr);
        int m = (1 << (int)floor(log2(n + 1))) - 1;
        int a = n - m;
        
        Node<T> *t = curr;
        for (int i = 0; i < a; i++)
        {
            t = RR(t);
            curr = t;
        }
        
        m = m / 2;
        while (m > 0)
        {
            t = curr;
            for (int i = 0; i < m; i++)
            {
                t = RR(t);
                curr = t;
                if (t->right != NULL)
                    t = t->right;
            }
            m = m / 2;
        }
    }

    void perfectTree()
    {
        createPerfectTree(root);
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

    cout<<endl<<"Task 1:"<<endl;
    BST<int> bst;
    vector<int> in1 = {1, 2, 3, 4, 5, 6};
    vector<int> pre1 = {3, 1, 2, 5, 4, 6};

    bst.construct_from_traversals(in1, pre1);

    cout << "In-order traversal (Example 1): ";
    bst.inorder();
    cout<<endl;
    cout << "Post-order traversal (Example 1): ";
    bst.postorder();

    BST<int> bst2;
    vector<int> in2 = {5, 10, 15, 25, 27, 30, 35, 40, 45, 50, 52, 55, 60, 65, 70, 75, 80, 85, 90, 100};
    vector<int> pre2 = {50, 25, 10, 5, 15, 40, 30, 27, 35, 45, 75, 60, 55, 52, 65, 70, 90, 80, 85, 100};

    bst2.construct_from_traversals(in2, pre2);

    cout << "\nIn-order traversal (Example 2): ";
    bst2.inorder();
    cout<<endl;
    cout << "Post-order traversal (Example 2): ";
    bst2.postorder();

    cout << endl
         << "Task 2:" << endl;
    BST<int> b;
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    b.createBalanced(arr, 0, n - 1);
    cout << "Pre-order: ";
    b.preorder();
    cout << endl
         << "In-order: ";
    b.inorder();
    cout << endl
         << "Post-order: ";
    b.postorder();


    cout<<endl<<"Task 3:"<<endl;
    BST<int> bs;
    bs.insert(1);
    bs.insert(5);
    bs.insert(10);
    bs.insert(20);
    bs.insert(25);
    bs.insert(30);
    bs.insert(35);
    bs.insert(40);
    bs.insert(45);

    cout << "Original BST  Height: " << bs.height() << endl;
    cout << "\nOriginal BST (Inorder): ";
    bs.inorder();
    cout << "\nOriginal BST Pre-order: ";
    bs.preorder();
    cout << "\nOriginal BST Post-order: ";
    bs.postorder();

    bs.perfectTree();
    cout << "\nHeight After DSW: " << bs.height() << endl;
    cout << "\nBalanced BST using DSW (Inorder): ";
    bs.inorder();
    cout << "\nBalanced BST using (DSWPre-order:) ";
    bs.preorder();
    cout << "\nBalanced BST using DSW (Post-order:) ";
    bs.postorder();
}