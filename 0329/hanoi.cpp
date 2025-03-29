#include <iostream>
using namespace std;

void move(string source, string destination)
{
    cout << "move from " << source << " to " << destination;
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
    hanoi(1, "A", "B", "C");
    return 0;
}