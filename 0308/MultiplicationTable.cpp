#include <iostream>
#include <string> 
#include <iomanip>
using namespace std;
// 输出乘法口诀表
int main()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            string str = to_string(j) + "x" + to_string(i) + "=" + to_string(i * j);
            cout << left << setw(7) << str;
            // cout << j << "x" << i << "=" << i * j<<"  ";
        }
        cout << endl;
    }
    return 0;
}