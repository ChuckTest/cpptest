#include <iostream>
using namespace std;

void move(int n, string source, string destination)
{
    cout << "move from " << source << " to " << destination << endl;
}

void hanoi(int n, string source, string middle, string destination)
{
    if (n == 1)
    {
        move(n, source, destination);
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
    hanoi(3, "A", "B", "C");
    return 0;
}