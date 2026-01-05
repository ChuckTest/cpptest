#include <iostream>
#include "LinkedQueueWithHead.h"

class LinkedQueueWithHead {
private:
    Node* front; // 始终指向头结点
    Node* rear;  // 指向队尾节点

public:
    LinkedQueueWithHead() {
        // 初始化：创建一个附加头结点
        front = rear = new Node(); 
    }

    ~LinkedQueueWithHead() {
        while (front) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // 入队：无论队列是否为空，逻辑完全一致
    void enqueue(int val) {
        Node* newNode = new Node(val);
        rear->next = newNode; // 直接连在 rear 后面
        rear = newNode;       // 移动 rear 到新节点
    }

    // 出队
    bool dequeue(int& val) {
        if (isEmpty()) return false;

        // 注意：真正的队头是头结点的下一个节点
        Node* firstNode = front->next; 
        val = firstNode->data;

        front->next = firstNode->next; // 头结点指向第二个元素

        // 特殊处理：如果删掉的是最后一个节点，需重置 rear
        if (rear == firstNode) {
            rear = front;
        }

        delete firstNode;
        return true;
    }

    bool isEmpty() {
        return front == rear;
    }
};