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
        if (value <= 0)
            return;
        Node *newNode = new Node(value);
        if (head->next == NULL)
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

    int FindNode(int value)
    {
        Node *current = head->next;
        int index = 0;
        bool hasFound = false;
        while (current != NULL)
        {
            index++;
            if (current->data == value)
            {
                hasFound = true;
                break;
            }
            else
            {
                current = current->next;
            }
        }
        if (!hasFound)
        {
            index = 0;
        }
        return index;
    }

    bool DeleteNode(int value)
    {
        Node *previous = head;
        Node *current = head->next;
        while (current != NULL)
        {
            if (current->data == value)
            {
                previous->next = current->next;
                delete current;
                if (current == tail)
                {
                    tail = previous;
                }
                return true;
            }
            previous = current;
            current = current->next;
        }
        return false;
    }

    int RemoveDuplicates()
    {
        Node *start = head->next;
        while (start != NULL)
        {
            Node *prev = start;
            Node *temp = prev->next;
            Node *nextStart = temp;
            while (temp != NULL)
            {
                if (start->data == temp->data)
                {
                    if (nextStart == temp)
                    {
                        nextStart = temp->next;
                    }
                    if (temp->next == NULL)
                    {
                        tail = prev;
                    }
                    prev->next = temp->next;
                    delete temp;
                    temp = prev->next;
                }
                else
                {
                    prev = temp;
                    temp = prev->next;
                }
            }
            start = nextStart;
        }
        return 0;
    }

    void RverseList()
    {
        // head->1->2->3-NULL
        Node *prev = NULL;
        Node *current = head->next; // 1
        Node *next = NULL;

        Node *newTail = current;

        while (current != NULL)
        {
            next = current->next; // 保存下一个结点 2
            current->next = prev; // 反转当前结点的指针 1->NULL。第二次处理的时候，prev相当于原来的第一个结点
            prev = current;       // prev指向当前结点 1，在处理下一个结点的时候，会用到1
            current = next;       // 下一个待处理的结点 2
        }
        head->next = prev; // 头结点指向新的第一个结点
        tail = newTail;
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
        current = head->next;
        while (current != NULL)
        {
            cout << current;
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
    cout << "5. 反转链表\n";
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
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int value;
            cout << "请输入整数，输入小于等于0的值结束输入：";
            while (true)
            {
                cin >> value;
                if (value <= 0)
                    break;
                list.AddNode(value);
                cout << "请继续输入整数，输入小于等于0的值结束输入：";
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
            if (index > 0)
            {
                cout << "找到了该结点，它是第 " << index << " 个结点。" << endl;
            }
            else
            {
                cout << "找不到此结点。" << endl;
            }
            list.PrintList();
            break;
        }
        case 3:
        {
            int value;
            cout << "请输入要删除的结点值：";
            cin >> value;
            bool deleted = list.DeleteNode(value);
            if (deleted)
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
            list.RverseList();
            cout << "反转后的链表：";
            list.PrintList();
            break;
        }
        case 0:
            cout << "退出程序。" << endl;
            break;
        default:
            cout << "无效选择，请重新输入！" << endl;
        }
    }
    return 0;
}