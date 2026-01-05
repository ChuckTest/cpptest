#include <iostream>
using namespace std;

int main()
{
    const int N = 4;
    int j;  // Declare `j` once outside the loops
    
    for (int i = 1; i <= N; i++)
    {
        for (j = 1; j <= 30; j++) // No longer declares `j` in the loop header
            cout << ' ';
        for (j = 1; j <= 8 - 2 * i; j++)
            cout << ' ';
        for (j = 1; j <= 2 * i - 1; j++)
            cout << '*';
        cout << endl;
    }

    for (int i = 1; i <= N - 1; i++)
    {
        for (j = 1; j <= 30; j++)
            cout << ' ';
        for (j = 1; j <= 7 - 2 * i; j++)
            cout << '*';
        cout << endl;
    }

    return 0;
}
