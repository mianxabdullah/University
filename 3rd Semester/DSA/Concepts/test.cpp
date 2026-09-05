#include <iostream>
#include "LSLL.h"   // include your class header
using namespace std;

int main()
{
    LSLL<int> list;

    cout << "=== Testing Circular Singly Linked List (CSLL) ===\n\n";

    cout << "--- Insert at Head ---\n";
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtHead(30);
    list.display();  // Expected: 30 20 10 (back to Head)

    cout << "\n--- Insert at End ---\n";
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    list.display();  // Expected: 30 20 10 40 50

    cout << "\n--- Remove at Head ---\n";
    list.removeAtHead();
    list.display();  // Expected: 20 10 40 50

    cout << "\n--- Remove at End ---\n";
    list.removeAtEnd();
    list.display();  // Expected: 20 10 40

    cout << "\n--- Insert After Key (10 -> 15) ---\n";
    list.insertAfterKey(10, 15);
    list.display();  // Expected: 20 10 15 40

    cout << "\n--- Insert Before Key (10 -> 5) ---\n";
    list.insertBeforeKey(10, 5);
    list.display();  // Expected: 20 5 10 15 40

    cout << "\n--- Remove After Key (10) ---\n";
    list.removeAfterKey(10);
    list.display();  // Expected: 20 5 10 40

    cout << "\n--- Remove Before Key (10) ---\n";
    list.removeBeforeKey(10);
    list.display();  // Expected: 5 10 40

    cout << "\n--- Remove Specific Value (10) ---\n";
    list.remove(10);
    list.display();  // Expected: 5 40

    cout << "\n--- Update Node (40 -> 99) ---\n";
    list.update(40, 99);
    list.display();  // Expected: 5 99

    cout << "\n--- Search for 99 ---\n";
    list.search(99); // Should print found message

    cout << "\n--- Count Nodes ---\n";
    cout << "Total Nodes: " << list.countNodes() << endl;

    cout << "\n--- Remove All Nodes ---\n";
    list.removeAtHead();
    list.removeAtHead(); // list becomes empty
    list.display();

    cout << "\n--- Destructor Check ---\n";
    // Destructor will run automatically at program end.

    cout << "\n=== Test Complete ===\n";

    return 0;
}
