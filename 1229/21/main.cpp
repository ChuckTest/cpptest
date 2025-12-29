#include <iostream>

#include <windows.h>
using namespace std;

class Node
{
    friend class LinkList;

private:
    int data;
    Node *next;

public:
    Node(Node *ptr = NULL)
    {
        next = ptr;
    }
    Node(int item, Node *ptr = NULL)
    {
        data = item;
        next = ptr;
    }
};

class LinkList
{
private:
    Node *head = NULL;
    Node *tail = NULL;

public:
    LinkList()
    {
        head = new Node();
        head->next = NULL;
        tail = head;
    }
};

int main()
{
    // 设置控制台输出 UTF-8 编码
    SetConsoleOutputCP(65001);
    cout << "单链表实验" << endl;

    system("pause");
    return 0;
}