#ifndef CDLL_H
#define CDLL_H

#include <iostream>
#include <utility>  // For std::pair
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node<T> *prev;

    Node()
    {
        data = 0;
        next = nullptr;
        prev = nullptr;
    }
    Node(T val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
    ~Node()
    {
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
class CDLL
{
private:
    Node<T> *head;

public:
    CDLL()
    {
        head = nullptr;
    }

    void insertAtHead(T val)
    {
        Node<T> *newNode = new Node<T>(val);

        if (head == nullptr)
        {
            head = newNode;
            head->next = newNode;
            head->prev = newNode;
            return;
        }
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtTail(T val)
    {
        if (head == nullptr)
        {
            insertAtHead(val);
            return;
        }

        Node<T> *newNode = new Node<T>(val);
        head->prev->next = newNode;
        newNode->prev = head->prev;
        newNode->next = head;
        head->prev = newNode;
    }

    void removeAtHead()
    {
        if (head == nullptr)
            return;

        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node<T> *temp = head;
        head = head->next;
        head->prev = temp->prev;
        head->prev->next = head;
        delete temp;
    }

    void removeAtTail()
    {
        if (head == nullptr)
            return;

        if (head->next == head)
        {
            removeAtHead();
            return;
        }

        Node<T> *temp = head->prev;
        head->prev->prev->next = head;
        head->prev = temp->prev;
        delete temp;
    }

    void remove(T val)
    {
        if (head == nullptr)
            return;

        if (head->data == val)
        {
            removeAtHead();
            return;
        }

        if (head->prev->data == val)
        {
            removeAtTail();
            return;
        }

        Node<T> *temp = head;
        while (temp->next != head)
        {
            if (temp->data == val)
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                return;
            }
            temp = temp->next;
        }
    }

    bool search(T key)
    {
        if (head == nullptr)
            return false;

        Node<T> *temp = head;
        do
        {
            if (temp->data == key)
            {
                return true;
            }
            temp = temp->next;
        } while (temp != head);
        return false;
    }

    void update(T key, T val)
    {
        if (head == nullptr)
            return;

        Node<T> *temp = head;
        do
        {
            if (temp->data == key)
            {
                temp->data = val;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }

    int countNodes()
    {
        if (head == nullptr)
            return 0;

        int count = 0;
        Node<T> *temp = head;
        do
        {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
    }

    // Display/Traversal (forward)
    void displayForward()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node<T> *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    // Display/Traversal (backward)
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

    // Reversal (swap next and prev pointers)
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

    // Split at position (0-based, returns two CDLLs: first up to pos, second from pos+1)
    // Note: This modifies the original list; caller must manage the two resulting lists
    pair<CDLL<T>, CDLL<T>> split(int pos)
    {
        CDLL<T> first, second;
        if (head == nullptr || pos < 0 || pos >= countNodes())
        {
            return {first, second}; // Invalid pos, return empty
        }

        if (pos == 0)
        {
            second = *this; // Copy second as original
            first.head = nullptr; // First empty
            this->head = nullptr; // Original emptied
            return {first, second};
        }

        Node<T> *splitNode = head;
        for (int i = 0; i < pos; ++i)
        {
            splitNode = splitNode->next;
        }

        // First list: head to splitNode
        first.head = head;
        first.head->prev = splitNode;
        splitNode->next = head;

        // Second list: splitNode->next to original tail
        second.head = splitNode->next;
        second.head->prev = splitNode;
        splitNode->next = second.head;
        second.head->prev->next = splitNode;

        // Break connection
        splitNode->next = nullptr;
        second.head->prev = nullptr;

        // Update original (now first)
        head = nullptr;

        return {first, second};
    }

    // Merge two CDLLs (appends second to first, assumes T comparable with <)
    void merge(CDLL<T>& other)
    {
        if (other.head == nullptr)
            return;

        if (head == nullptr)
        {
            *this = other; // Copy if empty
            other.head = nullptr;
            return;
        }

        // Append other's tail to this tail
        Node<T> *thisTail = head->prev;
        Node<T> *otherTail = other.head->prev;

        thisTail->next = other.head;
        other.head->prev = thisTail;
        otherTail->next = head;
        head->prev = otherTail;

        // Clear other
        other.head = nullptr;
    }

    // Sort (bubble sort, assumes T has < operator)
    void sort()
    {
        if (head == nullptr || head->next == head)
            return;

        bool swapped;
        Node<T> *ptr1;
        Node<T> *lptr = nullptr;

        do
        {
            swapped = false;
            ptr1 = head;

            // Traverse forward, but stop at lptr due to circular
            while (ptr1->next != head && ptr1->next != lptr)
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

    // New: Shuffle Merge (returns a new CDLL alternating nodes from this and other)
    // Copies data to avoid modifying originals; handles unequal lengths by appending remainder
    CDLL<T> shuffleMerge(const CDLL<T>& other) const
    {
        CDLL<T> result;
        if (head == nullptr)
        {
            result = other; // Copy other if this is empty
            return result;
        }
        if (other.head == nullptr)
        {
            result = *this; // Copy this if other is empty
            return result;
        }

        int count1 = countNodes();
        int count2 = other.countNodes();
        int minCount = min(count1, count2);

        Node<T> *temp1 = head;
        Node<T> *temp2 = other.head;

        // Alternate first minCount nodes
        for (int i = 0; i < minCount; ++i)
        {
            result.insertAtTail(temp1->data);
            result.insertAtTail(temp2->data);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        // Append remainder from longer list
        if (count1 > count2)
        {
            for (int i = minCount; i < count1; ++i)
            {
                result.insertAtTail(temp1->data);
                temp1 = temp1->next;
            }
        }
        else if (count2 > count1)
        {
            for (int i = minCount; i < count2; ++i)
            {
                result.insertAtTail(temp2->data);
                temp2 = temp2->next;
            }
        }

        return result;
    }

    ~CDLL()
    {
        while (head != nullptr)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

#endif