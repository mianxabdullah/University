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
            return curr;

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

    int countLeaves(Node<T> *curr)
    {
        if (curr == NULL)
            return 0;
        if (curr->left == NULL && curr->right == NULL)
            return 1;
        return countLeaves(curr->left) + countLeaves(curr->right);
    }

    bool isAVL(Node<T> *curr)
    {
        if (curr == NULL)
            return true;
        int lh = getHeight(curr->left);
        int rh = getHeight(curr->right);
        if (abs(lh - rh) > 1)
            return false;
        return isAVL(curr->left) && isAVL(curr->right);
    }

    Node<T> *successor(Node<T> *n) // next bigger value
    {
        if (!n)
            return NULL;
        if (n->right)
        {
            Node<T> *cur = n->right;
            while (cur->left)
                cur = cur->left;
            return cur;
        }
        Node<T> *succ = NULL;
        Node<T> *cur = root;
        while (cur)
        {
            if (n->data < cur->data)
            {
                succ = cur;
                cur = cur->left;
            }
            else
                cur = cur->right;
        }
        return succ;
    }

    Node<T> *predecessor(Node<T> *n) // next smaller
    {
        if (!n)
            return NULL;
        if (n->left)
        {
            Node<T> *cur = n->left;
            while (cur->right)
                cur = cur->right;
            return cur;
        }
        Node<T> *pred = NULL;
        Node<T> *cur = root;
        while (cur)
        {
            if (n->data > cur->data)
            {
                pred = cur;
                cur = cur->right;
            }
            else
                cur = cur->left;
        }
        return pred;
    }

    vector<T> pathToNode(T value)
    {
        vector<T> path;
        Node<T> *curr = root;
        while (curr)
        {
            path.push_back(curr->data);
            if (value == curr->data)
                break;
            else if (value < curr->data)
                curr = curr->left;
            else
                curr = curr->right;
        }
        return path;
    }
    void toSortedArray(Node<T> *curr, vector<T> &arr)
    {
        if (!curr)
            return;
        toSortedArray(curr->left, arr);
        arr.push_back(curr->data);
        toSortedArray(curr->right, arr);
    }
    Node<T> *getRoot()
    {
        return root;
    }
};
int main()
{
    AVL<int> a;
    a.insert(50);
    a.insert(30);
    a.insert(70);
    a.insert(20);
    a.insert(40);
    a.insert(60);
    a.insert(80);

    a.inorder();
    a.preorder();
    a.postorder();
    a.LevelOrder();

    cout << "Height: " << a.height() << endl;
    cout << "Leaf count: " << a.countLeaves(a.getRoot()) << endl;
    cout << "Is AVL? " << (a.isAVL(a.getRoot()) ? "Yes" : "No") << endl;

    Node<int> *n = a.getNode(40);
    Node<int> *succ = a.successor(n);
    Node<int> *pred = a.predecessor(n);
    if (succ)
        cout << "Successor of 40: " << succ->data << endl;
    if (pred)
        cout << "Predecessor of 40: " << pred->data << endl;

    vector<int> path = a.pathToNode(60);
    cout << "Path to 60: ";
    for (int x : path)
        cout << x << " ";
    cout << endl;

    vector<int> arr;
    a.toSortedArray(a.getRoot(), arr);
    cout << "Sorted array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}