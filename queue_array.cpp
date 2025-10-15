#include <iostream>

using namespace std;

const int MAX = 10;

struct Queue {
    int data[MAX + 1];  
    int rear;
    int front;
};

void QueueInit(Queue& queue) {
    queue.front = 1;
    queue.rear = 0;
}

void AddToQueue(Queue& queue, int data) {
    if (queue.rear == MAX) {
        cout << "Overflow" << endl;
    } else {
        queue.rear++;
        queue.data[queue.rear] = data;
    }
}

int RemoveFromQueue(Queue& queue) {
    if (queue.front > queue.rear) {
        cout << "Queue is Empty" << endl;
        return 0;  
    } else {
        int temp = queue.data[queue.front];
        queue.front++;
        return temp;
    }
}

int main() {
    Queue myQueue;
    QueueInit(myQueue);

    AddToQueue(myQueue, 1);
    AddToQueue(myQueue, 1);
    AddToQueue(myQueue, 2);
    AddToQueue(myQueue, 3);
    AddToQueue(myQueue, 5);
    AddToQueue(myQueue, 8);

    cout << "Current queue front: " << myQueue.front << endl;
    cout << "Current queue rear: " << myQueue.rear << endl;

    cout << "Item removed from queue: " << RemoveFromQueue(myQueue) << endl;

    cout << "Current queue front after removal: " << myQueue.front << endl;

    cout << "Next remove: " << RemoveFromQueue(myQueue) << endl;  
    cout << "Next remove: " << RemoveFromQueue(myQueue) << endl;  


    return 0;
}