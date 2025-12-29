#include <iostream>

#include <windows.h>
using namespace std;

int main()
{
    // 设置控制台输出 UTF-8 编码
    SetConsoleOutputCP(65001);
    cout << "自动驾驶路径规划" << endl;

    system("pause");
    return 0;
}