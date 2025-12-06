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
    cout << "你想查询第几个节点？" << endl;
    int i;
    cin >> i;
    cout << "******查询结果******" << endl;
    cout << list.GetElement(i);
    cout << endl;
    system("pause");
    return 0;
}