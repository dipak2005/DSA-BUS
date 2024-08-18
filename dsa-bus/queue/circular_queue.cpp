#include <iostream> 
class CircularQueue {
    int* arr;
    int size;
    int qfront;
    int rear;
    
public:
    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        qfront = rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int value) {
        // Queue is full
        if ((rear + 1) % size == qfront) {
            return false;
        }
        // Queue is empty
        else if (qfront == -1) {
            qfront = rear = 0;
        }
        else if (rear == size - 1 && qfront != 0) {
            rear = 0;
        }
        else {
            rear = (rear + 1) % size;
        }
        arr[rear] = value;
        return true;
    }

    // Dequeues front element from queue. Returns -1 if the queue is empty, otherwise returns the dequeued element.
    int dequeue() {
        // Queue is empty
        if (qfront == -1) {
            return -1;
        }

        int ans = arr[qfront];
        arr[qfront] = -1;

        // Queue has only one element
        if (qfront == rear) {
            qfront = rear = -1;
        }
        else if (qfront == size - 1) {
            qfront = 0;
        }
        else {
            qfront = (qfront + 1) % size;
        }
        return ans;
    }
};
