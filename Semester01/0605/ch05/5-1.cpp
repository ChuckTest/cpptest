#include <iostream>
using namespace std;
int i; // 文件作用域
int main()
{
    i = 5;
    {
        int i; // 块作用域
        i = 7;
        cout << "i=" << i << endl; // 输出7
    }
    cout << "i=" << i << endl; // 输出5
    return 0;
}
