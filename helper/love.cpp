#include <iostream>
using namespace std;
int main()
{
    int n = 8;
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            for (int k = 0; k < n; k++)
            {
                cout << " ";
            }
            cout << "❤" << endl;
        }
        else if (i == n)
        {
            for (int j = n+1; j > 0; j--)
            {
                cout << "❤ ";
            }
        }
        else
        {
            for (int k = 0; k < n-i; k++)
            {
                cout << " ";
            }
            //cout << n-i;
            cout << "❤";
            for (int k = 0; k < 2*i-1; k++)
            {
                cout << " ";
            }
            //cout << i;
            cout << "❤" << endl;
        }
    }
    return 0;
}