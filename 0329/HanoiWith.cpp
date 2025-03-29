#include <iostream>
using namespace std;
int diskNumber;
int diskCount = 2;
int steps = 0;

void move(int n, string source, string destination)
{
    steps++;
    cout << "steps" << steps << ": move " << n << " from " << source << " to " << destination << endl;
}

void hanoi(int n, string source, string middle, string destination)
{
    if (n == 1)
    {
        move(diskCount, source, destination);
    }
    else
    {
        hanoi(n - 1, source, destination, middle);
        move(n - 1, source, destination);
        hanoi(n - 1, middle, source, destination);
    }
}

int main()
{
    hanoi(diskCount, "A", "B", "C");
    return 0;
}