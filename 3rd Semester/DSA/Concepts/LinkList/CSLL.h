#ifndef CSLL_H
#define CSLL_H

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
class CSLL
{
private:
    Node<T> *Head;
    //Node<T> *Tail;

public:
    CSLL()
    {
        Head = NULL;
        Tail = NULL;
    }

    void insertAtHead(T val)
    {
        Node<T> *newNode = new Node<T>(val);
        if(Head == NULL)
        {
            Head=newNode;
            Tail=newNode;
            Tail->next=Head;
            return;
        }
        newNode->next = Head; // points to where head was pointing earlier
        Head = newNode;       // now head started pointing to this new node
        Tail->next=Head;
    }

    void removeAtHead()
    {
        if (Head == NULL)
        {
            cout << "List Is Empty" << endl;
            return;
        }
        if(Head == Tail)
        {
            delete Head;
            Head=Tail=NULL;
            return;
        }
        Node<T> *remov = Head; // take where head was pointing ;first node
        Head = Head->next;     // point head to next node
        Tail->next=Head;
        delete remov;          // remove first node
    }
    void insertAtEnd(T val)
    {
        Node<T> *newNode = new Node<T>(val); 
        if (Head == NULL)
        {
            Head =Tail= newNode; // if there no node before then add at head
            Tail->next=Head;
            return;
        }
        Tail->next=newNode;
        Tail=newNode;
        Tail->next=Head;
    }
    void removeAtEnd()
    {
        if (Head == NULL)
        {
            cout << "List Is Empty" << endl;
            return;
        }
        if (Head==Tail) // if head is pointing to such node whose
        {                       // next=null (means only 1 node is there)
            delete Head;
            Head =Tail= NULL;
            return;
        }
        Node<T> *current = Head;            // incase of multiple nodes take a temphead
                                            // cz we dont wanna change actual head position
        while (current->next != Tail) // loop from head to one object behind end
        {                                   // loop checks if in next of next obj is null
            current = current->next;
        }
        delete Tail;
        Tail=current; 
        Tail->next=Head ;
    }
    void insertAfterKey(T key, T val)
    {
        if (Head == NULL)
        {
            return;
        }
        Node<T> *current = Head; // temphead because we dont wanna update actual head
        do
        {
            if (current->data == key)
            {
                Node<T> *temp = new Node<T>(val);
                temp->next = current->next;
                current->next = temp;
                if(current == Tail)
                    Tail=temp;
                return; // to stop after first appearance otherwise obj would be inserted after every matched data with key
            }
            current = current->next;
        }while (current != Head);
    }
    void removeAfterKey(T key)
    {
        if (Head == NULL)
        {
            return;
        }
        Node<T> *current = Head; // temphead because we dont wanna update actual head
        do 
        {
            if (current->data == key)
            {
                Node<T> *temp = current->next;
                if(temp == Head) Head=Head->next;
                if(temp == Tail) Tail=current;
                current->next = temp->next;
                delete temp;
                Tail->next=Head;
                return;
            }
            current = current->next;
        }while (current != Head);
    }
    void insertBeforeKey(T key, T val)
    {
        if (Head == NULL)
        {
            return;
        }
        if (Head->data == key)
        {
            insertAtHead(val);
            return;
        }
        Node<T> *current = Head; // temphead because we dont wanna update actual head
        do 
        {
            if (current->next->data == key)
            {
                Node<T> *temp = new Node<T>(val);
                temp->next = current->next;
                current->next = temp;
                return; // to stop after first appearance otherwise obj would be inserted after every matched data with key
            }
            current = current->next;
        }while (current != Head);
    }
    void removeBeforeKey(T key)
    {
        if (Head == NULL || Head->next == NULL)
        {
            return;
        }
        if (Head->next->data == key)
        {
            removeAtHead();
            return;
        }
        Node<T> *current = Head; // temphead because we dont wanna update actual head
        do 
        {
            if (current->next->next->data == key)
            {
                Node<T> *temp = current->next;
                if (temp == Head) 
                    Head = temp->next;
                if (temp == Tail) 
                    Tail = current;
                current->next = temp->next;
                delete temp;
                Tail->next=Head;
                return;
            }
            current = current->next;
        }while(current != Head);
    }
    void remove(T val)
    {
        if (Head == NULL)
        {
            return; // empty list
        }
        if (Head->data == val)
        {
            removeAtHead();
            return;
        }
        Node<T> *current = Head;
        do 
        {
            if (current->next->data == val)
            {
                Node<T> *temp = current->next;
                current->next = temp->next;
                if (temp == Tail) 
                    Tail = current;
                delete temp;
                Tail->next = Head;
                return;
            }
            current = current->next;
        }while(current != Head);
    }

    void update(T key, T val)
    {
        if (!Head)
        {
            return;
        }
        Node<T> *thead = Head;
        do 
        {
            if (thead->data == key)
            {
                thead->data = val;
                return;
            }
            thead = thead->next;
        }while(thead != Head);
    }
    void display()
    {
        if (Head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node<T> *temp = Head;
        do 
        {
            cout << temp->data << " ";
            temp = temp->next;
        }while (temp != Head);
        cout << "(back to Head)" << endl;
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
        do 
        {
            if (temp->data == key)
            {
                cout << "key: " << key << " Found at position: " << count << endl;
                return true;
            }
            temp = temp->next;
            count++;
        }while (temp != Head);
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
        }while (current != Head);
        return count;
    }
    ~CSLL()
    {
        if (Head == NULL)
            return;
        Tail->next=NULL;
        Node<T> *current = Head;
        while (current != NULL)
        {
            Node<T> *next = current->next;
            delete current;
            current = next;
        }
        Head =Tail= NULL;
    }
};
#endif