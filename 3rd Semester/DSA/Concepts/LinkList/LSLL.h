#ifndef LSLL_H
#define LSLL_H

#include <iostream>
using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T val)
    {
        data = val;
        next = NULL;
    }
    Node()
    {
        next = NULL;
    }
    Node(T val, Node<T> *p)
    {
        data = val;
        next = p;
    }
};
template <typename T>
class LSLL
{
private:
    Node<T> *Head;

public:
    LSLL()
    {
        Head = NULL;
    }

    void insertAtHead(T val)
    {
        Node<T> *newNode = new Node<T>(val);
        newNode->next = Head; // points to where head was pointing earlier
        Head = newNode;       // now head started pointing to this new node
    }

    void removeAtHead()
    {
        if (Head == NULL)
        {
            cout << "List Is Empty" << endl;
            return;
        }
        Node<T> *remov = Head; // take where head was pointing ;first node
        Head = Head->next;     // point head to next node
        delete remov;          // remove first node
    }
    void insertAtEnd(T val)
    {
        Node<T> *newNode = new Node<T>(val);
        newNode->next = NULL; // make new node with data as parameter and next=null
        if (Head == NULL)
        {
            Head = newNode; // if there no node before then add at head
            return;
        }
        Node<T> *current = Head;      // if not take head in a temp and loop from head
        while (current->next != NULL) // to last node in whose next null is stored
        {
            current = current->next;
        }
        current->next = newNode; // lastnode->newNode
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
            delete Head;
            Head = NULL;
            return;
        }
        Node<T> *current = Head;            // incase of multiple nodes take a temphead
                                            // cz we dont wanna change actual head position
        while (current->next->next != NULL) // loop from head to one object behind end
        {                                   // loop checks if in next of next obj is null
            current = current->next;
        }
        delete current->next; // remove last node
        current->next = NULL; // store null inplace of lastnode addr
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
                current->next = temp;
                return; // to stop after first appearance otherwise obj would be inserted after every matched data with key
            }
            current = current->next;
        }
    }
    void removeAfterKey(T key)
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
                if (current->next == NULL)
                {
                    return; // nothing to remove
                }
                Node<T> *temp = current->next;
                current->next = temp->next;
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
            Head = temp;
            return;
        }
        Node<T> *current = Head; // temphead because we dont wanna update actual head
        while (current->next != NULL)
        {
            if (current->next->data == key)
            {
                Node<T> *temp = new Node<T>(val);
                temp->next = current->next;
                current->next = temp;
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
            delete temp;
            return;
        }
        Node<T> *current = Head; // temphead because we dont wanna update actual head
        while (current->next != NULL && current->next->next != NULL)
        {
            if (current->next->next->data == key)
            {
                Node<T> *temp = current->next;
                current->next = temp->next;
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
            delete temp;
            return;
        }
        Node<T> *current = Head;
        while (current->next != NULL)
        {
            if (current->next->data == val)
            {
                Node<T> *temp = current->next;
                current->next = temp->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }

    void update(T key, T val)
    {
        if (Head != NULL)
        {
            return;
        }
        Node<T> *curr = Head;
        while (curr != NULL)
        {
            if (curr->data == key)
            {
                curr->data = val;
                return;
            }
            curr = curr->next;
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
    ~LSLL()
    {
        Node<T> *current = Head;
        while (current != NULL)
        {
            Node<T> *next = current->next;
            delete current;
            current = next;
        }
        Head = NULL;
    }
};
#endif