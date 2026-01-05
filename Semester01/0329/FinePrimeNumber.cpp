#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int i = 1;
    while (true)
    {
        i++;
        // cout << i << endl;
        if (i > 1000)
        {
            break;
        }
        int count = 0;
        double sqrtDoubleNumber = sqrt(i);
        int sqrtIntegerNumber = ceil(sqrtDoubleNumber);
        bool isPrime = true;
        for (int j = 1; j <= sqrtIntegerNumber; j++)
        {
            if (i % j == 0 && j != 1 && j != i)
            {
                isPrime = false;
            }
        }
        if (isPrime)
        {
            cout << i << " is a prime number" << endl;
        }
    }
    return 0;
}