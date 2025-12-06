#include <iostream>

#include <windows.h>

#include "linkedlist.h"

int main()
{
    // 设置控制台输出 UTF-8 编码
    SetConsoleOutputCP(65001);
    cout << "hello world!" << endl;

    LinkList list;
    cout << list.GetSize() << endl;
    list.CreateListR();
    list.PrintList();
    system("pause");
    return 0;
}