#include <iostream>
#include "CircularQueue.h"

class CircularQueue {
private:
    int* arr;         // 动态数组
    int front;        // 队头指针
    int rear;         // 队尾指针（指向下一个存入位置）
    int capacity;     // 数组的总大小 (m)

public:
    // 构造函数：size 是用户想要存入的数据个数
    CircularQueue(int size) {
        // 实际申请 size + 1 个空间，因为要浪费一个格子来区分空满
        capacity = size + 1;
        arr = new int[capacity];
        front = 0;
        rear = 0;
    }

    // 析构函数
    ~CircularQueue() {
        delete[] arr;
    }

    // 1. 判满：(rear + 1) % m == front
    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    // 2. 判空：front == rear
    bool isEmpty() {
        return front == rear;
    }

    // 3. 入队
    bool enqueue(int value) {
        if (isFull()) {
            std::cout << "队列已满，无法入队 " << value << std::endl;
            return false;
        }
        arr[rear] = value;
        rear = (rear + 1) % capacity; // 关键：取模 m
        return true;
    }

    // 4. 出队
    bool dequeue(int &val) {
        if (isEmpty()) {
            std::cout << "队列为空，无法出队" << std::endl;
            return false;
        }
        val = arr[front];
        front = (front + 1) % capacity; // 关键：取模 m
        return true;
    }

    // 5. 获取当前元素个数
    int getSize() {
        return (rear - front + capacity) % capacity;
    }

    // 6. 遍历打印（不破坏队列）
    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }
        std::cout << "Queue elements: ";
        int count = getSize();
        for (int i = 0; i < count; i++) {
            int index = (front + i) % capacity;
            std::cout << arr[index] << " ";
        }
        std::cout << std::endl;
    }
};
