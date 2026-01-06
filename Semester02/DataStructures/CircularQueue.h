#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

class CircularQueue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;

public:
    CircularQueue(int size);
    ~CircularQueue();
    bool isFull();
    bool isEmpty();
    bool enqueue(int value);
    bool dequeue(int &val);
    int getSize();
    void display();
};

#endif