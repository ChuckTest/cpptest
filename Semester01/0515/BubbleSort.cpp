#include <iostream>
using namespace std;
int main()
{
    int a[] = {5, 9, 10, 1, 3, 7, 11, 2};
    int n = sizeof(a) / sizeof(a[0]);
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < n - 1 - j; i++)
        {
            if (a[i] > a[i + 1])
            {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}