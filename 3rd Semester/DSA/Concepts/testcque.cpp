#include"TempCirQueue.h"
int main()
{
    // Queue<int> q(10);
    // for(int i=0;i<10;i++) q.enqueue(i+10);
    // q.display();
    // for(int i=0;i<5;i++) q.dequeue();
    // for(int i=0;i<3;i++) q.enqueue(i+20);
    // q.display();

        // Create a queue of integers with capacity 5
    Queue<int> q(5);

    cout << "Enqueueing 1, 2, 3, 4" << endl;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.display();   // should print: 1 2 3 4

    cout << "Front: " << q.QueueFront() << endl;  // should be 1
    cout << "Rare: " << q.QueueRare() << endl;    // should be 4

    cout << "Dequeuing two elements..." << endl;
    cout << "Dequeued: " << q.dequeue() << endl;  // removes 1
    cout << "Dequeued: " << q.dequeue() << endl;  // removes 2
    q.display();   // should print: 3 4

    cout << "Enqueueing 5, 6, 7 (wrap-around)" << endl;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.display();   // should print: 3 4 5 6 7

    cout << "Resizing queue to 10" << endl;
    q.resize(10);
    q.display();   // should still print: 3 4 5 6 7

    cout << "Enqueueing more after resize..." << endl;
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(10);
    q.display();   // should print: 3 4 5 6 7 8 9 10

    cout << "Dequeuing all elements..." << endl;
    while (!q.isEmpty()) {
        cout << q.dequeue() << " ";
    }
    cout << endl;

    return 0;

}
