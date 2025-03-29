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

    // Get disk from source stack
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

    // Place the disk into the destination stack
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

    // Simplest solution: Print a newline when a disk is moved to C and it is a "key disk"
    // A key disk is defined as starting from the largest disk (totalDiskCount) and decrementing to 1
    if (destination == "C") {
        // We do not check the stack state here, but simply check by disk number
        // Each time a disk is moved to C, we check if it is the next key disk that should trigger a newline
        static int nextKeyDisk = totalDiskCount;
        
        if (diskNumber == nextKeyDisk) {
            cout << endl;
            nextKeyDisk--; // Move to the next key disk
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
