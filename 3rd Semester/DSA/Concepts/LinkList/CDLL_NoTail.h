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

public:
    DCLL()
    {
        Head = NULL;
    }

    void insertAtHead(T val)
    {
        Node<T> *newNode = new Node<T>(val);
        if (Head == NULL)
        {
            Head = newNode;
            Head->next = Head;
            Head->pre = Head;
            return;
        }
        newNode->next = Head;
        newNode->pre = Head->pre;
        Head->pre->next = newNode;
        Head->pre = newNode;
        Head = newNode;
    }

    void removeAtHead()
    {
        if (Head == NULL)
        {
            cout << "List Is Empty" << endl;
            return;
        }
        if (Head == Head->pre) //  single node case
        {
            delete Head;
            Head = NULL;
            return;
        }

        Node<T> *temp = Head;
        Head->pre->next = Head->next;
        Head->next->pre = Head->pre;
        Head = Head->next;
        delete temp;
    }

    void insertAtEnd(T val)
    {
        Node<T> *newNode = new Node<T>(val);
        if (Head == NULL)
        {
            Head = newNode;
            Head->next = Head; //
            Head->pre = Head;  //
            return;
        }
        newNode->pre = Head->pre;
        newNode->next = Head; //
        Head->pre->next = newNode;
        Head->pre = newNode; //
    }

    void removeAtEnd()
    {
        if (Head == NULL)
        {
            cout << "List Is Empty" << endl;
            return;
        }
        if (Head->pre == Head) //  only one node
        {
            delete Head;
            Head = NULL;
            return;
        }

        Node<T> *temp = Head->pre;
        Head->pre = Head->pre->pre;
        Head->pre->next = Head; //
        delete temp;
    }

    void remove(T val)
    {
        if (Head == NULL)
            return;

        if (Head->data == val)
        {
            if (Head == Head->pre) // only 1 node
            {
                delete Head;
                Head = NULL;
                return;
            }
            Node<T> *temp = Head; // value to be removed is at head
            Head->next->pre = Head->pre;
            Head->pre->next = Head->next;
            Head = Head->next;
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

        Node<T> *curr = Head;
        do
        {
            if (curr->data == key)
            {
                curr->data = val;
                return;
            }
            curr = curr->next;
        } while (curr != Head);
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
    void displayBackward()
    {
        if (Head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node<T> *temp = Head->pre;
        do
        {
            cout << temp->data << " ";
            temp = temp->pre;
        } while (temp != Head->prev);
        cout << endl;
    }
    void reverse()
    {
        if (Head == NULL || Head->next == Head) //single code
            return;

        Node<T> *temp = Head;
        do
        {
            // Swap next and prev
            Node<T> *next = temp->next;
            Node<T> *pre = temp->pre;
            temp->next = pre;
            temp->pre = next;
            temp = next;
        } while (temp != Head);
        Head = Head->pre;
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
        Node<T> *current = Head->next;
        while (current != Head)
        {
            Node<T> *next = current->next;
            delete current;
            current = next;
        }
        delete Head;
        Head = NULL;
    }
};

#endif
