#include <iostream>
using namespace std;

int main()
{
    int i = 0;
    while (true)
    {
        i++;
        if (i > 1000)
        {
            break;
        }
        int count = 0;
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
            {
                count++;
            }
            if (count > 2)
            {
                break;
            }
        }
        if (count == 2)
        {
            cout << i << endl;
        }
    }
    return 0;
}