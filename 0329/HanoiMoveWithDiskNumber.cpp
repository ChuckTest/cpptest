#include <iostream>
#include <stack>
using namespace std;
stack<int> stackA;
stack<int> stackB;
stack<int> stackC;
int steps = 0;
int totalDiskCount = 4;

void move(string source, string destination)
{
    steps++;
    int diskNumber = 0;
    // 从源栈获取盘子
    if (source == "A" && !stackA.empty())
    {
        diskNumber = stackA.top();
        stackA.pop();
    }
    else if (source == "B" && !stackB.empty())
    {
        diskNumber = stackB.top();
        stackB.pop();
    }
    else if (source == "C" && !stackC.empty())
    {
        diskNumber = stackC.top();
        stackC.pop();
    }
    else
    {
        cerr << "Error: Trying to move from an empty stack!" << endl;
        return;
    }

    // 放入目标栈
    if (destination == "A")
    {
        stackA.push(diskNumber);
    }
    else if (destination == "B")
    {
        stackB.push(diskNumber);
    }
    else if (destination == "C")
    {
        stackC.push(diskNumber);
    }
    else
    {
        cerr << "Error: Invalid destination!" << endl;
        return;
    }

    cout << "Step " << steps << ": Move disk " << diskNumber << " from " << source << " to " << destination << endl;

    // 最简单的解决方案：当盘子移动到C，并且这个盘子是"关键盘子"时打印空行
    // 关键盘子就是从最大的盘子totalDiskCount开始，依次递减到1
    if (destination == "C") {
        // 这里我们不检查栈的状态，而是简单地按照盘子编号来判断
        // 每次有盘子移动到C，就检查它是否是下一个应该打印空行的盘子
        static int nextKeyDisk = totalDiskCount;
        
        if (diskNumber == nextKeyDisk) {
            cout << endl;
            nextKeyDisk--; // 下一个关键盘子
        }
    }
}

void hanoi(int n, string source, string middle, string destination)
{
    if (n == 1)
    {
        move(source, destination);
    }
    else
    {
        hanoi(n - 1, source, destination, middle);
        move(source, destination);
        hanoi(n - 1, middle, source, destination);
    }
}

int main()
{
    for (int i = totalDiskCount; i > 0; i--)
    {
        stackA.push(i);
    }
    hanoi(totalDiskCount, "A", "B", "C");
    return 0;
}