#include <iostream>
using namespace std;

void FindNumber_V1();
void FindNumber_V2();
void FindNumber_V3();

int main()
{
    FindNumber_V1();
    FindNumber_V2();
    FindNumber_V3();
    return 0;
}

void FindNumber_V1()
{
    const int max = 1000;
    int i = 1;
    int sum = 0;
    while (i <= max)
    {
        if (i % 7 == 0)
        {
            sum += i;
        }
        i++;
    }
    cout << sum << endl;
}

void FindNumber_V2()
{
    const int max = 1000;
    int i = 1;
    int sum = 0;
    do
    {
        if (i % 7 == 0)
        {
            sum += i;
        }
        i++;
    } while (i <= max);
    cout << sum << endl;
}

void FindNumber_V3()
{
    const int max = 1000;
    int sum = 0;
    for (int i = 1; i <= max; i++)
    {
        if (i % 7 == 0)
        {
            sum += i;
        }
    }
    cout << sum << endl;
}