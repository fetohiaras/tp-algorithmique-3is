#include <iostream>

using namespace std;

const int MAX = 10000;

struct Queue {
    int data[MAX];  
    int front;
    int rear;
    int n;  
};

void QueueInit(Queue& queue) {
    queue.front = 0;
    queue.rear = MAX - 1;
    queue.n = 0;
}

void Push(Queue& queue, int V) {
    if (queue.n == MAX) {
        cout << "Queue is Full" << endl;
    } else {
        queue.rear = (queue.rear + 1) % MAX;
        queue.data[queue.rear] = V;
        queue.n++;
    }
}

int Pop(Queue& queue) {
    if (queue.n == 0) {
        cout << "Queue is Empty" << endl;
        return 0;  
    } else {
        int val = queue.data[queue.front];
        queue.front = (queue.front + 1) % MAX;
        queue.n--;
        return val;
    }
}

int main() {
    Queue myQueue;
    QueueInit(myQueue);

    for (int i = 1; i <= 6000; i++) {
        Push(myQueue, i);
    }
    cout << "After 6000 Push: n = " << myQueue.n << ", front = " << myQueue.front << ", rear = " << myQueue.rear << endl;

    for (int i = 1; i <= 6000; i++) {
        Pop(myQueue);
    }
    cout << "After 6000 Pop: n = " << myQueue.n << ", front = " << myQueue.front << ", rear = " << myQueue.rear << endl;

    for (int i = 1; i <= 6000; i++) {
        Push(myQueue, i);
    }
    cout << "After another 6000 Push: n = " << myQueue.n << ", front = " << myQueue.front << ", rear = " << myQueue.rear << endl;

    cout << "First Pop: " << Pop(myQueue) << endl;  
    cout << "Second Pop: " << Pop(myQueue) << endl;  

    
    for (int i = 6001; i <= MAX + 1; i++) {
        Push(myQueue, i);  
    }

    for (int i = 1; i <= myQueue.n + 1; i++) {
        Pop(myQueue);  
    }

    return 0;
}