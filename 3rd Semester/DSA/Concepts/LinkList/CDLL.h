#ifndef DCLL_H
#define DCLL_H

#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node<T> *pre;

    Node(T val)
    {
        data = val;
        next = NULL;
        pre = NULL;
    }
    Node()
    {
        next = NULL;
        pre = NULL;
    }
    Node(T val, Node<T> *np, Node<T> *pp)
    {
        data = val;
        next = np;
        pre = pp;
    }
};

template <typename T>
class DCLL 
{
private:
    Node<T> *Head;
    Node<T> *Tail;

public:
    DCLL()
    {
        Head = NULL;
        Tail = NULL;
    }

    void insertAtHead(T val)
    {
        Node<T> *newNode = new Node<T>(val);
        if (Head == NULL)
        {
            Head = Tail = newNode;
            Head->next = Head;  // 
            Head->pre = Head;   // 
            return;
        }
        newNode->next = Head;
        newNode->pre = Tail;    // 
        Head->pre = newNode;    
        Tail->next = newNode;   //
        Head = newNode;
    }

    void removeAtHead()
    {
        if (Head == NULL)
        {
            cout << "List Is Empty" << endl;
            return;
        }
        if (Head == Tail) //  single node case
        {
            delete Head;
            Head = Tail = NULL;
            return;
        }

        Node<T> *temp = Head;
        Head = Head->next;
        Head->pre = Tail;   //
        Tail->next = Head;  // 
        delete temp;
    }

    void insertAtEnd(T val)
    {
        Node<T> *newNode = new Node<T>(val);
        if (Tail == NULL)
        {
            Head = Tail = newNode;
            Head->next = Head;  // 
            Head->pre = Head;   // 
            return;
        }
        newNode->pre = Tail;
        newNode->next = Head;   // 
        Tail->next = newNode;
        Head->pre = newNode;    // 
        Tail = newNode;
    }

    void removeAtEnd()
    {
        if (Head == NULL)
        {
            cout << "List Is Empty" << endl;
            return;
        }
        if (Head == Tail) //  only one node
        {
            delete Head;
            Head = Tail = NULL;
            return;
        }

        Node<T> *temp = Tail;
        Tail = Tail->pre;
        Tail->next = Head;  // 
        Head->pre = Tail;   // 
        delete temp;
    }

    void insertAfterKey(T key, T val)
    {
        if (Head == NULL)
            return;

        Node<T> *current = Head;
        do  // 
        {
            if (current->data == key)
            {
                Node<T> *temp = new Node<T>(val);
                temp->next = current->next;
                temp->pre = current;
                current->next->pre = temp;
                current->next = temp;
                if (current == Tail)
                    Tail = temp; // 
                return;
            }
            current = current->next;
        } while (current != Head); // 
    }

    void removeAfterKey(T key)
    {
        if (Head == NULL || Head->next == Head) // 
            return;

        Node<T> *current = Head;
        do
        {
            if (current->data == key)
            {
                Node<T> *temp = current->next;
                if (temp == Head)
                    return; // nothing to remove before head
                current->next = temp->next;
                temp->next->pre = current;
                if (temp == Tail)
                    Tail = current; // 
                delete temp;
                return;
            }
            current = current->next;
        } while (current != Head);
    }

    void insertBeforeKey(T key, T val)
    {
        if (Head == NULL)
            return;

        Node<T> *current = Head;
        do
        {
            if (current->data == key)
            {
                Node<T> *temp = new Node<T>(val);
                temp->next = current;
                temp->pre = current->pre;
                current->pre->next = temp;
                current->pre = temp;
                if (current == Head)
                    Head = temp; // 
                return;
            }
            current = current->next;
        } while (current != Head);
    }

    void removeBeforeKey(T key)
    {
        if (Head == NULL || Head->next == Head)
            return;

        Node<T> *current = Head;
        do
        {
            if (current->data == key)
            {
                Node<T> *temp = current->pre;
                if (temp == current)
                    return; // only one node
                temp->pre->next = current;
                current->pre = temp->pre;
                if (temp == Head)
                    Head = current; // 
                if (temp == Tail)
                    Tail = current->pre; // 
                delete temp;
                return;
            }
            current = current->next;
        } while (current != Head);
    }

    void remove(T val)
    {
        if (Head == NULL)
            return;

        if (Head->data == val)
        {
            if (Head == Tail)
            {
                delete Head;
                Head = Tail = NULL;
                return;
            }
            Node<T> *temp = Head;
            Head = Head->next;
            Head->pre = Tail;
            Tail->next = Head;
            delete temp;
            return;
        }

        Node<T> *current = Head;
        do
        {
            if (current->data == val)
            {
                Node<T> *temp = current;
                temp->pre->next = current->next;
                current->next->pre = temp->pre;
                if (current == Tail)
                    Tail = temp->pre; // 
                delete temp;
                return;
            }
            current = current->next;
        } while (current != Head);
    }

    void update(T key, T val)
    {
        if (Head == NULL)
            return;

        Node<T> *thead = Head;
        do
        {
            if (thead->data == key)
            {
                thead->data = val;
                return;
            }
            thead = thead->next;
        } while (thead != Head); // 
    }

    void display()
    {
        if (Head == NULL)
        {
            cout << "List is Empty" << endl;
            return;
        }
        Node<T> *temp = Head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != Head); // 
        cout << "(back to Head)" << endl; // 
    }

    T head()
    {
        if (Head == NULL)
            throw runtime_error("List is empty!");
        return Head->data;
    }

    bool search(T key)
    {
        if (Head == NULL)
            return false;

        int count = 1;
        Node<T> *temp = Head;
        do
        {
            if (temp->data == key)
            {
                cout << "key: " << key << " Found at position: " << count << endl;
                return true;
            }
            temp = temp->next;
            count++;
        } while (temp != Head); // 
        return false;
    }

    int countNodes()
    {
        if (Head == NULL)
            return 0;
        int count = 0;
        Node<T> *current = Head;
        do
        {
            count++;
            current = current->next;
        } while (current != Head); // 
        return count;
    }

    ~DCLL()
    {
        if (Head == NULL)
            return;
        Node<T> *current = Head;
        do
        {
            Node<T> *next = current->next;
            delete current;
            current = next;
        } while (current != Head); // 
        Head = NULL;
        Tail = NULL;
    }
};

#endif
