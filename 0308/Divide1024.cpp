#include <iostream>
using namespace std;
//个位数为8且能被1024整除的五位数共有多少？
int main()
{
    int count = 0;
    for (int i = 10000; i < 100000; i++)
    {
        if (i % 1024 == 0 && i % 10 == 8)
        {
            count++;
            cout << i << endl;
        }
    }
    cout << "共有" << count << "个" << endl;
    return 0;
}