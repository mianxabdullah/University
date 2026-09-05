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

public:
    Node<T> *Head;
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
        if (Head == NULL || Head->next == Head) // single code
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

    void sort()
    {
        if (Head == NULL || Head->next == Head)
            return;

        bool swapped;
        Node<T> *ptr1;
        Node<T> *lptr = NULL;

        do
        {
            swapped = false;
            ptr1 = Head;

            // Traverse forward, but stop at lptr due to circular
            while (ptr1->next != Head && ptr1->next != lptr)
            {
                if (ptr1->data > ptr1->next->data)
                {
                    // Swap data (simple for bubble)
                    T temp = ptr1->data;
                    ptr1->data = ptr1->next->data;
                    ptr1->next->data = temp;
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }
    void merge(DCLL<T> &list1, DCLL<T> &list2)
    {
        if (list1.Head == NULL && list2.Head == NULL)
            return;
        if (list1.Head == NULL && list2.Head != NULL)
        {
            Head = list2.Head;
            list2.Head = NULL;
            return;
        }
        if (list2.Head == NULL && list1.Head != NULL)
        {
            Head = list1.Head;
            list1.Head = NULL;
            return;
        }

        Node<T> *t1 = list1.Head;
        Node<T> *t2 = list2.Head;
        Node<T> *curr = NULL;

        // Break circular links temporarily to avoid infinite loops
        list1.Head->pre->next = NULL;
        list2.Head->pre->next = NULL;

        if (t1->data <= t2->data)
        {
            Head = t1;
            curr = t1;
            t1 = t1->next;
        }
        else
        {
            Head = t2;
            curr = t2;
            t2 = t2->next;
        }

        // ✅ Merge remaining nodes
        while (t1 != NULL && t2 != NULL)
        {
            if (t1->data <= t2->data)
            {
                curr->next = t1;
                t1->pre = curr; //
                curr = t1;
                t1 = t1->next;
            }
            else
            {
                curr->next = t2;
                t2->pre = curr; //
                curr = t2;
                t2 = t2->next;
            }
        }

        // ✅ Attach remaining part of list1 if any
        if (t1 != NULL)
        {
            curr->next = t1;
            t1->pre = curr; //
            while (t1->next != NULL)
                t1 = t1->next; //
            curr = t1;
        }

        // ✅ Attach remaining part of list2 if any
        if (t2 != NULL)
        {
            curr->next = t2;
            t2->pre = curr; //
            while (t2->next != NULL)
                t2 = t2->next; //
            curr = t2;
        }

        //  Re-circularize merged list
        curr->next = Head;
        Head->pre = curr;

        list1.Head = NULL;
        list2.Head = NULL;
    }
    void splitList(DCLL &leftHalf, DCLL &rightHalf)
    {
        if (Head == NULL)
            return;

        int total = this->countNodes();
        int count = 0;
        leftHalf.Head = Head;
        rightHalf.Head = Head;
        while (count < (total + 1) / 2)
        {
            rightHalf.Head = rightHalf.Head->next;
            count++;
        }
        Head->pre->next = rightHalf.Head->next;
        rightHalf.Head->next->pre = Head->pre;
        rightHalf.Head->next = leftHalf.Head;
        leftHalf.Head->pre = rightHalf.Head;
        rightHalf.Head = rightHalf.Head->next;

        Head = NULL;
    }
    void combine(DCLL &l1, DCLL &l2)
    {
        if (l1.Head == NULL && l2.Head == NULL)
            return;
        if (l1.Head == NULL && l2.Head != NULL)
        {
            Head = l2.Head;
            l2.Head = NULL;
            return;
        }
        if (l1.Head != NULL && l2.Head == NULL)
        {
            Head = l1.Head;
            l1.Head = NULL;
            return;
        }
        Head = l1.Head;
        Head->pre->next = l2.Head;

        Node<T> *temp = l2.Head->pre; // store tail of l2

        l2.Head->pre = Head->pre; // head of l2 -> prev = tail of l1
        Head->pre = temp;         // head of final list -> prev = tail of l2
        temp->next = Head;        // tail of l2 -> next = head of final list

        l1.Head = NULL;
        l2.Head = NULL;
    }
    void shuffleMerge(DCLL<T> &list1, DCLL<T> &list2)
    {
        if (list1.Head == NULL || list2.Head == NULL)
        {
            if (list1.Head != NULL)
            {
                Head = list1.Head;
                list1.Head = NULL;
            }
            else if (list2.Head != NULL)
            {
                Head = list2.Head;
                list2.Head = NULL;
            }
            return;
        }

        this->Head = list1.Head;
        Node<T> *temp1 = list1.Head->next;
        Node<T> *temp2 = list2.Head;
        Node<T> *curr = this->Head;

        while (temp1 != list1.Head && temp2 != list2.Head)
        {
            // link to node from list2
            curr->next = temp2;
            temp2->pre = curr;
            curr = curr->next;
            temp2 = temp2->next;

            // link back to node from list1
            curr->next = temp1;
            temp1->pre = curr;
            curr = curr->next;
            temp1 = temp1->next;
        }

        // attach remaining nodes if any
        if (temp1 != list1.Head)
        {
            curr->next = temp1;
            temp1->pre = curr;
            // find tail of remaining temp1 nodes
            while (temp1->next != list1.Head)
                temp1 = temp1->next;
            temp1->next = this->Head;
            this->Head->pre = temp1;
        }
        else if (temp2 != list2.Head)
        {
            curr->next = temp2;
            temp2->pre = curr;
            // find tail of remaining temp2 nodes
            while (temp2->next != list2.Head)
                temp2 = temp2->next;
            temp2->next = this->Head;
            this->Head->pre = temp2;
        }
        else
        {
            // close the circle if no remaining nodes
            curr->next = this->Head;
            this->Head->pre = curr;
        }

        list1.Head = NULL;
        list2.Head = NULL;
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
