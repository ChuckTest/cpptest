#include <iostream>
using namespace std;
int diskNumber=0;
int diskCount = 2;
int steps = 0;

void move(string source, string destination)
{
    steps++;
    cout << "steps" << steps << ": move " << diskNumber << " from " << source << " to " << destination << endl;
}

void hanoi(int n, string source, string middle, string destination)
{
    cout<<"n="<<n<<", source="<<source<<", middle="<<middle<<", destination="<<destination<<endl;
    if (n == 1)
    {
        move(source, destination);
    }
    else
    {
        diskNumber++;
        hanoi(n - 1, source, destination, middle);
        diskNumber++;
        move(source, destination);
        diskNumber--;
        hanoi(n - 1, middle, source, destination);
    }
}

int main()
{
    hanoi(diskCount, "A", "B", "C");
    return 0;
}