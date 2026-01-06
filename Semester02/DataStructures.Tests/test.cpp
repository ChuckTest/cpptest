#include "pch.h" // 如果是 VS 自动生成的项目需要保留
#include "CircularQueue.h"
#include "LinkedQueueWithHead.h"

// --- 测试循环队列 (CircularQueue) ---
TEST(CircularQueueTest, BasicOperations) {
    int capacity = 4;
    CircularQueue q(capacity);

    // A. 初始状态测试
    EXPECT_TRUE(q.isEmpty());
    EXPECT_EQ(q.getSize(), 0);

    // B. 基础入队出队与 FIFO 测试
    q.enqueue(10);
    q.enqueue(20);
    EXPECT_EQ(q.getSize(), 2);

    int val;
    EXPECT_TRUE(q.dequeue(val));
    EXPECT_EQ(val, 10);
    EXPECT_EQ(q.getSize(), 1);

    // C. 满状态拦截测试
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    EXPECT_TRUE(q.isFull());
    EXPECT_FALSE(q.enqueue(60)); // 应该失败，返回 false

    // D. 循环绕回测试
    EXPECT_TRUE(q.dequeue(val));
    EXPECT_EQ(val, 20);
    EXPECT_TRUE(q.enqueue(60));  // 测试绕回写入
    EXPECT_EQ(q.getSize(), 4);
}

// --- 测试链式队列 (LinkedQueueWithHead) ---
TEST(LinkedQueueTest, EmptyQueueBehavior) {
    LinkedQueueWithHead q;
    int val;
    // A. 空队列出队测试
    EXPECT_FALSE(q.dequeue(val));
}

TEST(LinkedQueueTest, PressureTest) {
    LinkedQueueWithHead q;
    int val;

    // B. 大数据量压力测试
    for (int i = 0; i < 1000; i++) {
        q.enqueue(i);
    }
    EXPECT_FALSE(q.isEmpty());

    // C. 彻底清空后的状态测试
    for (int i = 0; i < 1000; i++) {
        ASSERT_TRUE(q.dequeue(val)); // 如果这里失败，后面没必要比对了，所以用 ASSERT
        EXPECT_EQ(val, i);
    }
    EXPECT_TRUE(q.isEmpty());
}

TEST(LinkedQueueTest, BoundaryReset) {
    LinkedQueueWithHead q;
    int val;

    // D. 边界：最后一个元素出队后 rear 的重置验证
    q.enqueue(99);
    EXPECT_TRUE(q.dequeue(val));
    EXPECT_TRUE(q.isEmpty());

    q.enqueue(100);
    EXPECT_TRUE(q.dequeue(val));
    EXPECT_EQ(val, 100);
}