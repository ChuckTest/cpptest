#include <iostream>
#include <stack>
using namespace std;
stack<int> stackA;
stack<int> stackB;
stack<int> stackC;
int steps = 0;

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
}

void hanoi(int n, string source, string middle, string destination)
{
    // cout << "n=" << n << ", source=" << source << ", middle=" << middle << ", destination=" << destination << endl;
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
    int totalDiskCount = 4;
    for (int i = totalDiskCount; i > 0; i--)
    {
        stackA.push(i);
    }
    hanoi(totalDiskCount, "A", "B", "C");
    return 0;
}