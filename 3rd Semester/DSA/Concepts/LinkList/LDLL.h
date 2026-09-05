#ifndef LDLL_H
#define LDLL_H

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
class LDLL
{
private:
    Node<T> *Head;
    Node<T> *Tail;

public:
    LDLL()
    {
        Head = NULL;
        Tail = NULL;
    }

    void insertAtHead(T val)
    {
        Node<T> *newNode = new Node<T>(val);
        if (Head == NULL)
        {
            Head = newNode;
            Tail = newNode;
            return;
        }
        newNode->next = Head; // points to where head was pointing earlier
        newNode->pre = NULL;
        Head->pre = newNode;
        Head = newNode; // now head started pointing to this new node
    }

    void removeAtHead()
    {
        if (Head == NULL)
        {
            cout << "List Is Empty" << endl;
            return;
        }
        Node<T> *remov = Head;
        Head = Head->next;
        if (Head != NULL) // for example if head is null there is no head->pre
        {                 // for precaution we use this check
            Head->pre = NULL;
        }
        else
        {
            Tail = NULL;
        }
        delete remov; // remove first node
    }
    void insertAtEnd(T val)
    {
        Node<T> *newNode = new Node<T>(val);
        newNode->next = NULL;
        if (Tail == NULL)
        {
            Head = Tail = newNode;
            return;
        }
        newNode->pre = Tail;
        Tail->next = newNode;
        Tail = Tail->next;
    }
    void removeAtEnd()
    {
        if (Head == NULL)
        {
            cout << "List Is Empty" << endl;
            return;
        }
        if (Head->next == NULL) // if head is pointing to such node whose
        {                       // next=null (means only 1 node is there)
            Node<T> *current = Head;
            Head = Tail = NULL;
            delete current;
            return;
        }

        Node<T> *current = Tail;
        Tail = Tail->pre;
        Tail->next = NULL;
        delete current;
    }
    void insertAfterKey(T key, T val)
    {
        if (Head == NULL)
        {
            return;
        }
        Node<T> *current = Head; // temphead because we dont wanna update actual head
        while (current != NULL)
        {
            if (current->data == key)
            {
                Node<T> *temp = new Node<T>(val);
                temp->next = current->next;
                temp->pre = current;
                if (current != Tail)
                    current->next->pre = temp;
                else
                    Tail = temp;
                current->next = temp;
                return; // to stop after first appearance otherwise obj would be inserted after every matched data with key
            }
            current = current->next;
        }
    }
    void removeAfterKey(T key)
    {
        if (Head == NULL || Head->next == NULL)
        {
            return;
        }
        Node<T> *current = Head;
        while (current != NULL)
        {
            if (current->data == key)
            {
                if (current == Tail)
                {
                    return; // nothing to remove
                }
                Node<T> *temp = current->next;
                current->next = temp->next;
                if (temp->next != NULL)
                    temp->next->pre = current;
                else
                    Tail = current; // if removing 2nd last node
                delete temp;
                return;
            }
            current = current->next;
        }
    }
    void insertBeforeKey(T key, T val)
    {
        if (Head == NULL)
        {
            return;
        }
        if (Head->data == key)
        {
            Node<T> *temp = new Node<T>(val);
            temp->next = Head;
            temp->pre = NULL;
            Head->pre = temp;
            Head = temp;
            return;
        }
        Node<T> *current = Head;
        while (current != NULL)
        {
            if (current->data == key)
            {
                Node<T> *temp = new Node<T>(val);
                temp->next = current;
                temp->pre = current->pre;
                temp->pre->next = temp;
                current->pre = temp;
                return; // to stop after first appearance otherwise obj would be inserted after every matched data with key
            }
            current = current->next;
        }
    }
    void removeBeforeKey(T key)
    {
        if (Head == NULL || Head->next == NULL)
        {
            return;
        }
        if (Head->next->data == key)
        {
            Node<T> *temp = Head;
            Head = Head->next;
            Head->pre = NULL;
            delete temp;
            return;
        }
        Node<T> *current = Head;
        while (current != NULL)
        {
            if (current->data == key)
            {
                Node<T> *temp = current->pre;
                current->pre = temp->pre;
                current->pre->next = temp->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }
    void remove(T val)
    {
        if (Head == NULL)
        {
            return; // empty list
        }
        if (Head->data == val)
        {
            Node<T> *temp = Head;
            Head = Head->next;
            if (Head != NULL)
                Head->pre = NULL;
            else
                Tail = NULL;
            delete temp;
            return;
        }
        Node<T> *current = Head;
        while (current != NULL)
        {
            if (current->data == val)
            {
                Node<T> *temp = current;
                if (current->next != NULL)
                    current->next->pre = temp->pre;
                else
                    Tail = temp->pre;
                temp->pre->next = current->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }
    void reducelist(int n, int m)
    {
        if (countNodes() < (n + m) || Head == NULL )
        {
            return;
        }
        int count = 1;
        Node<T> *curr = Head;
        while (curr != NULL)
        {
            if (count == m)
            {
                int a = 0;
                while (a < n && curr->next != NULL)
                {
                    Node<T> *temp = curr->next;
                    curr->next = temp->next;
                    if (curr->next != NULL)            
                    {
                        curr->next->pre = curr;          
                    }
                    delete temp;
                    a++;
                }
                return;
            }
            count++;
            curr = curr->next;
        }
    }

    void update(T key, T val)
    {
        if (Head == NULL)
        {
            return;
        }
        Node<T> *thead = Head;
        while (thead != NULL)
        {
            if (thead->data == key)
            {
                thead->data = val;
                return;
            }
            thead = thead->next;
        }
    }
    void display()
    {
        Node<T> *temp = Head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
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
        {
            return false;
        }
        int count = 1;
        Node<T> *temp = Head;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                cout << "key: " << key << " Found at position: " << count << endl;
                return true;
            }
            temp = temp->next;
            count++;
        }
        return false;
    }
    int countNodes()
    {
        int count = 0;
        Node<T> *current = Head;
        while (current != NULL)
        {
            count++;
            current = current->next;
        }
        return count;
    }
    ~LDLL()
    {
        Node<T> *current = Head;
        while (current != NULL)
        {
            Node<T> *next = current->next;
            delete current;
            current = next;
        }
        Head = NULL;
        Tail = NULL;
    }
};
#endif