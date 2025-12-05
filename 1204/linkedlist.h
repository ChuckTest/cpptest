#include <cstdlib>
#include <iostream>
using namespace std;

typedef int DataType;
class Node
{
    friend class LinkList;

private:
    DataType data;
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

    int GetSize()
    {
    }

    DataType GetElement(int i) // 获取第i个节点,i从1开始
    {
        if (i <= 0)
        {
            return NULL;
        }
        if (head->next == NULL)
        {
            cout << "空表，无法返回元素";
            exit(0);
        }
        else
        {
            Node *p;
            int count = 0;
            p = head;
            while (p != NULL)
            {
                p = p->next;
                if (p != NULL)
                {
                    count++;
                }
                if (count == i)
                {
                    break;
                }
            }
            if (p == NULL)
            {
                cout << "第" << i << "个元素不存在，无法返回元素。";
                exit(0);
            }
            return p->data;
        }
    }

    Node *Search(DataType e)
    {
    }

    void CreateListR()
    {
        DataType data;
        cout << "请输入数据,0结束:" << endl;
        cin >> data;

        Node *s;
        while (data > 0)
        {
            s = new Node(data, NULL);
            tail->next = s;
            tail = s;
            cout << "请再次输入数据(输入0结束):" << endl;
            cin >> data;
        }
    }

    ~LinkList()
    {
    }
};