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

    void CreateListR()
    {
        int data;
        cout << "请输入数据(输入小于等于0结束):" << endl;
        cin >> data;

        Node *s;
        while (data > 0)
        {
            s = new Node(data, NULL);
            tail->next = s;
            tail = s;
            cout << "请再次输入数据(输入小于等于0结束):" << endl;
            cin >> data;
        }
    }

    void PrintList()
    {
        Node *current = head->next;
        while (current != NULL)
        {
            cout << current->data;
            current = current->next;
            if (current != NULL)
            {
                cout << "->";
            }
        }
        cout << endl;
    }
};

int main()
{
    // 设置控制台输出 UTF-8 编码
    SetConsoleOutputCP(65001);
    cout << "单链表实验" << endl;

    LinkList list;
    list.CreateListR();
    list.PrintList();

    system("pause");
    return 0;
}