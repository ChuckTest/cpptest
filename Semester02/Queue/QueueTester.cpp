#include <iostream>
#include <cassert>
#include <string>
#include "CircularQueue.h"
#include "LinkedQueueWithHead.h"

// --- 单元测试类 ---
class QueueTester {
public:
    // 1. 测试数组循环队列
    static void testArrayQueue(int capacity) {
        std::cout << "正在测试: CircularQueue (数组实现)..." << std::endl;
        CircularQueue q(capacity);

        // A. 初始状态测试
        assert(q.isEmpty());
        assert(q.getSize() == 0);

        // B. 基础入队出队与 FIFO 测试
        q.enqueue(10);
        q.enqueue(20);
        assert(q.getSize() == 2);
        
        int val;
        q.dequeue(val);
        assert(val == 10); // 第一个入队的应该第一个出来
        assert(q.getSize() == 1);

        // C. 满状态拦截测试 (数组版核心)
        // 之前 capacity 是 4，现在里面有 1 个，再加 3 个就该满了
        q.enqueue(30);
        q.enqueue(40);
        q.enqueue(50);
        assert(q.isFull());
        assert(!q.enqueue(60)); // 应该失败

        // D. 循环绕回测试 (数组版核心)
        // 当前：front=1, rear=0 (假设数组大小5, 存了20,30,40,50)
        q.dequeue(val); assert(val == 20);
        q.enqueue(60);  // 此时 rear 应该从数组末尾绕回到 0
        assert(q.getSize() == 4);

        std::cout << ">> CircularQueue 测试通过！" << std::endl << std::endl;
    }

    // 2. 测试带头结点的链式队列
    static void testLinkedQueue() {
        std::cout << "正在测试: LinkedQueueWithHead (链表实现)..." << std::endl;
        LinkedQueueWithHead q;

        // A. 空队列出队测试
        int val;
        assert(!q.dequeue(val)); // 不应崩溃，应返回 false

        // B. 大数据量压力测试（验证指针稳定性）
        for (int i = 0; i < 1000; i++) {
            q.enqueue(i);
        }
        assert(!q.isEmpty());

        // C. 彻底清空后的状态测试
        for (int i = 0; i < 1000; i++) {
            assert(q.dequeue(val));
            assert(val == i);
        }
        assert(q.isEmpty());
        
        // D. 边界：最后一个元素出队后 rear 的重置验证
        q.enqueue(99);
        assert(q.dequeue(val));
        assert(q.isEmpty());
        q.enqueue(100); // 如果上次重置 rear 失败，这次 enqueue 会崩溃
        assert(q.dequeue(val));
        assert(val == 100);

        std::cout << ">> LinkedQueueWithHead 测试通过！" << std::endl << std::endl;
    }
};

int main() {
    try {
        // 执行测试
        QueueTester::testArrayQueue(4); // 传入最大存储量
        QueueTester::testLinkedQueue();

        std::cout << "============================" << std::endl;
        std::cout << "所有单元测试运行成功 (Passed)!" << std::endl;
        std::cout << "============================" << std::endl;
    } catch (...) {
        std::cerr << "测试过程中发生未知异常！" << std::endl;
    }

    return 0;
}