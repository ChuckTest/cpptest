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
    if (source == "A")
    {
        diskNumber = stackA.top();
        stackA.pop();
    }

    if (source == "B")
    {
        diskNumber = stackB.top();
        stackB.pop();
    }

    if (source == "C")
    {
        diskNumber = stackC.top();
        stackC.pop();
    }

    if (destination == "A")
    {
        stackA.push(diskNumber);
    }

    if (destination == "B")
    {
        stackB.push(diskNumber);
    }

    if (destination == "C")
    {
        stackC.push(diskNumber);
    }

    cout << "steps" << steps << ": move disk " << diskNumber << " from " << source << " to " << destination << endl;
}

void hanoi(int n, string source, string middle, string destination)
{
    //cout << "n=" << n << ", source=" << source << ", middle=" << middle << ", destination=" << destination << endl;
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
    int totalDiskCount = 3;
    for (int i = totalDiskCount; i > 0; i--)
    {
        stackA.push(i);
    }
    hanoi(totalDiskCount, "A", "B", "C");
    return 0;
}