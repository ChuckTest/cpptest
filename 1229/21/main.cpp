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

    void AddNode(int value)
    {
        if(value<=0) return;
        Node *newNode = new Node(value);
        if(head->next == NULL)
        {
            head->next = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
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

void showMenu()
{
    // 显示菜单
    cout << "\n链表操作菜单：\n";
    cout << "1. 从键盘输入若干整数并构造链表\n";
    cout << "2. 查找指定结点\n";
    cout << "3. 删除指定结点\n";
    cout << "4. 删除重复结点\n";
    cout << "5. 打印链表\n";
    cout << "0. 退出\n";
    cout << "请输入选择(0-5): ";
}

int main()
{
    // 设置控制台输出 UTF-8 编码
    SetConsoleOutputCP(65001);

    int choice;
    LinkList list;
    while (true)
    {
        showMenu();
        switch (choice)
        {
        case 1:
        {
            int value;
            cout << "请输入整数，输入小于等于0的值结束输入：" << endl;
            while (true)
            {
                cin >> value;
                if (value <= 0)
                    break;
                list.addNode(value);
            }
            cout << "链表创建完成！" << endl;
            list.PrintList();
            break;
        }
        case 2:
        {
            int value;
            cout << "请输入要查找的结点值：";
            cin >> value;
            int index = list.FindNode(value);
            if (index != -1)
            {
                cout << "找到了该结点，它是第 " << index << " 个结点。" << endl;
            }
            else
            {
                cout << "找不到此结点。" << endl;
            }
            break;
        }
        case 3:
        {
            int value;
            cout << "请输入要删除的结点值：";
            cin >> value;
            if (list.DeleteNode(value))
            {
                cout << "已经删除结点：" << value << endl;
            }
            else
            {
                cout << "链表中没有此结点，无法删除。" << endl;
            }
            list.PrintList();
            break;
        }
        case 4:
        {
            list.RemoveDuplicates();
            cout << "删除重复结点后的链表：";
            list.PrintList();
            break;
        }
        case 5:
        {
            list.PrintList();
            break;
        }
        case 6:
            cout << "退出程序。" << endl;
            return 0;
        default:
            cout << "无效选择，请重新输入！" << endl;
        }
    }
    return 0;
}