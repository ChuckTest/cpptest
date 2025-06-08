#include <iostream>
using namespace std;
/*
3、一个N位自然数，若这个数每一位的N次幂之和等于这个数，那么这个数成为水仙花数，求10000以内所有的水仙花数，
例如153是3位数，1的3次幂+5的3次幂+3的3次幂=153，所以153是水仙花数
*/

int pow(int x, int n)
{
    int total = 1;
    while (n > 0)
    {
        total = total * x;
        n--;
    }
    return total;
}

bool isNarcissistic(int num)
{
    int temp = num;
    int sum = 0;
    int digitsCount = 0;

    //
    while (temp > 0)
    {
        temp /= 10;
        digitsCount++;
    }

    temp = num;
    while (temp > 0)
    {
        int digit = temp % 10;
        sum += pow(digit, digitsCount);
        temp /= 10;
    }

    return sum == num;
}

int main()
{
    int threshold = 10000;
    for (int i = 0; i < threshold; i++)
    {
        if (isNarcissistic(i))
        {
            cout << i << " ";
        }
    }
    cout << endl;
    system("pause");
    return 0;
}