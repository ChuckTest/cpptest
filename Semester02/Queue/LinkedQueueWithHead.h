#pragma once

// 定义节点结构
struct Node {
    int data;
    Node* next;
    Node(int val = 0) : data(val), next(nullptr) {}
};

class LinkedQueueWithHead {
private:
    Node* front; // 始终指向头结点
    Node* rear;  // 指向队尾节点
    int count;   // 记录元素个数

public:
    // 构造函数
    LinkedQueueWithHead();

    // 析构函数
    ~LinkedQueueWithHead();

    // 入队
    void enqueue(int val);

    // 出队
    bool dequeue(int& val);

    // 判空
    bool isEmpty() const;

    // 获取长度
    int getSize() const;
};