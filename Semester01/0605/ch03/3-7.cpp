#include <windows.h>
#include <iostream>
using namespace std;
int main(void)
{
   SetConsoleOutputCP(65001); // 控制台输出 UTF-8
   int a, b;
   int fun1(int x, int y);
   cin >> a >> b;
   cout << "a、b的平方和：" << fun1(a, b) << endl;
}
int fun1(int x, int y)
{
   int fun2(int m);
   return (fun2(x) + fun2(y));
}

int fun2(int m)
{
   return (m * m);
}
