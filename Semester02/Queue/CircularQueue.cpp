#include "CircularQueue.h"  // 必须引入对应的头文件
#include <iostream>

// 注意 1：删掉了 class CircularQueue { ... } 的外壳
// 注意 2：在每一个函数名前面加上 CircularQueue::

// 构造函数
CircularQueue::CircularQueue(int size) {
    capacity = size + 1;
    arr = new int[capacity];
    front = 0;
    rear = 0;
}

// 析构函数
CircularQueue::~CircularQueue() {
    delete[] arr;
}

// 1. 判满
bool CircularQueue::isFull() {
    return (rear + 1) % capacity == front;
}

// 2. 判空
bool CircularQueue::isEmpty() {
    return front == rear;
}

// 3. 入队
bool CircularQueue::enqueue(int value) {
    if (isFull()) {
        std::cout << "队列已满，无法入队 " << value << std::endl;
        return false;
    }
    arr[rear] = value;
    rear = (rear + 1) % capacity;
    return true;
}

// 4. 出队
bool CircularQueue::dequeue(int &val) {
    if (isEmpty()) {
        std::cout << "队列为空，无法出队" << std::endl;
        return false;
    }
    val = arr[front];
    front = (front + 1) % capacity;
    return true;
}

// 5. 获取当前元素个数
int CircularQueue::getSize() {
    return (rear - front + capacity) % capacity;
}

// 6. 遍历打印
void CircularQueue::display() {
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