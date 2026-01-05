#include "LinkedQueueWithHead.h"
#include <iostream>

// 构造函数
LinkedQueueWithHead::LinkedQueueWithHead() {
    front = rear = new Node(); 
}

// 析构函数
LinkedQueueWithHead::~LinkedQueueWithHead() {
    while (front) {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

// 入队
void LinkedQueueWithHead::enqueue(int val) {
    Node* newNode = new Node(val);
    rear->next = newNode;
    rear = newNode;
}

// 出队
bool LinkedQueueWithHead::dequeue(int& val) {
    if (isEmpty()) return false;

    Node* firstNode = front->next; 
    val = firstNode->data;
    front->next = firstNode->next;

    if (rear == firstNode) {
        rear = front;
    }

    delete firstNode;
    return true;
}

// 关键点：必须带上 const，与 .h 文件完全匹配
bool LinkedQueueWithHead::isEmpty() const {
    return front == rear;
}

// 关键点：必须带上 const，且实现获取长度的逻辑
int LinkedQueueWithHead::getSize() const {
    int count = 0;
    Node* p = front->next; // 从第一个有效节点开始数
    while (p) {
        count++;
        p = p->next;
    }
    return count;
}