#include <iostream>
using namespace std;
//输出28826的全部正约数，并打印出它的最大和最小的两位数正约数。
int main()
{
    const int number = 28826;
    int min = 0;
    int max = 0;
    for (int i = 1; i <= number; i++)
    {
        if (number % i == 0)
        {
            cout << i << " ";
            if (i >= 10 && min == 0)
            {
                min = i;
            }
            if (i < 100)
            {
                max = i;
            }
        }
    }
    cout << endl << "最小两位正约数: " << min << endl;
    cout << "最大两位正约数: " << max << endl;
    return 0;
}