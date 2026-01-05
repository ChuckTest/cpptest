// 魔术师发牌问题

#include <iostream>
#include <vector>
using namespace std;

typedef int DataType; // 数据类型定义
class Node
{
    friend class CircularLinkedList;

private:
    DataType data; // 数据域
    Node *next;    // 指针域
    Node *prev;    // 前驱指针域
    int index;
public:
    Node(Node *ptr = NULL, Node *pre = NULL)
    {
        next = ptr;
        prev = pre;
    }
    Node(int item, Node *ptr = NULL, Node *pre = NULL)
    {
        data = item;
        next = ptr;
        prev = pre;
    }
};

class CircularLinkedList
{
private:
    Node *head; // 头指针
    Node *tail; // 链表长度
public:
    CircularLinkedList()
    {
        head = new Node(); // 创建头节点
        head->next = head; // 正向循环指向自己
        head->prev = head; // 反向循环指向自己
        tail = head;
    }
    ~CircularLinkedList();
    void Clear();
    bool IsEmpty()
    {
        return (head->next == head) ? true : false;
    };
    int Length() const;
    DataType GetElem(int index);
    int Locate(int e, int result[]);
    void Insert(int index, DataType e);
    DataType Delete(int index);
    void PrintList() const;
    void MagicCard();
    void MagicCardWrong();
};

CircularLinkedList::~CircularLinkedList()
{
    Clear();
    delete head;
}

void CircularLinkedList::Clear()
{
    Node *p = head->next;
    Node *q;
    while (p != head)
    {
        q = p->next;
        delete p;
        p = q;
    }
    head->next = head; // 正向循环指向自己
    head->prev = head; // 反向循环指向自己
    tail = head;
}

int CircularLinkedList::Length() const
{
    int len = 0;
    Node *p = head->next;
    while (p != head)
    {
        len++;
        p = p->next;
    }
    return len;
}

DataType CircularLinkedList::GetElem(int index) // 按位查找
{
    if (index < 1 || index > Length())
    {
        cout << "查找位置不合法！" << endl;
        exit(0);
    }
    else
    {
        Node *p = head->next;
        int i = 1;
        while (i < index)
        {
            p = p->next;
            i++;
        }
        return p->data; // 返回查找到的元素
    }
};

int CircularLinkedList::Locate(int e, int result[]) // 按值查找，返回所有位置
{
    Node *p = head->next;
    int index = 1;
    int count = 0;
    while (p != head)
    {
        if (p->data == e)
        {
            result[count++] = index; // 记录位置
        }
        p = p->next;
        index++;
    }
    if (count == 0)
    {
        cout << "链表中没有该元素！" << endl;
    }
    return count; // 返回查找到的元素个数
};

void CircularLinkedList::Insert(int index, DataType e) // 按位插入
{
    if (index < 1 || index > Length() + 1)
    {
        cout << "插入位置不合法！" << endl;
        exit(0);
    }
    else
    {
        Node *p = head;
        int i = 1;
        while (i < index)
        {
            p = p->next;
            i++;
        } // 遍历，保存指针至index位置
        Node *s = new Node(e, p->next, p);
        s->index=index;
        p->next->prev = s; // 维护前驱指针
        p->next = s;       // 维护后继指针
    }
}

DataType CircularLinkedList::Delete(int index) // 按位删除
{
    if (index < 1 || index > Length())
    {
        cout << "删除位置不合法！" << endl;
        exit(0);
    }
    else
    {
        Node *p = head;
        int i = 1;
        while (i < index)
        {
            p = p->next;
            i++;
        }
        Node *q = p->next;
        DataType e = q->data;
        p->next = q->next;
        q->next->prev = p;
        delete q;
        return e; // 相似于插入，遍历至目标位置，先将前驱，后继指针与删除后应该对接的节点对接，而后将该节点删除，但此处应该为void函数，输出删除成功，无返回值
    }
}

void CircularLinkedList::PrintList() const
{
    Node *p = head->next;
    while (p != head)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void CircularLinkedList::MagicCard()
{
    const int N = 13;

    // 清空并初始化链表
    Clear();
    for (int i = 0; i < N; ++i)
    {
        Insert(i + 1, 0);
    }

    Node *cur = head->next; // 从第一个节点开始

    for (int card = 1; card <= N; card++)
    {
        // 跳过 (card-1) 个空位置
        int skip = card;

        // 找到第card个空位置
        while (true)
        {
            // 当前位置是空的
            if (cur->data == 0)
            {
                skip--;
                if (skip == 0) // 找到了第card个空位置
                {
                    cur->data = card;
                    break;
                }
            }
            // 移动到下一个节点，跳过头节点
            cur = cur->next;
            if (cur == head)
                cur = cur->next;
        }

        // 移动到下一个位置，为下一轮做准备
        cur = cur->next;
        if (cur == head)
            cur = cur->next;
    }
}

void CircularLinkedList::MagicCardWrong()//错误版
{
    const int N = 13; // 默认13张牌，A(1)到K(13)

    // 初始化：清空链表并创建N个空节点（data=0）
    Clear();
    for (int i = 0; i < N; ++i)
    {
        Insert(i + 1, 0); // 插入N个0
    }
    this->PrintList();
    Node *cur = head->next; // 从第一个节点开始

    for (int card = 1; card <= N; card++)
    {
        // 跳过 (card - 1) 个空位（data == 0）
        int skip = card - 1;
        if(card==8){
            card=card+1;
            card=card-1;
        }
        while (skip > 0)
        {
            cur = cur->next;
            if (cur == head)
                cur = cur->next; // 跳过头节点（头节点不存数据）
            if (cur->data == 0)
            {
                cout << "card = "<<card<<", skip index=" << cur->index << ",data="<<cur->data<<endl;
                --skip; // 只有空位才计数
            }
        }

        // 现在 cur 指向要放置的位置（必须是空的）
        // 但可能当前 cur 不是空？不会，因为我们只在空位计数，且总空位足够
        // 找到下一个空位（如果当前位置非空，则继续找）

        cur->data = card;
        cout << "confirm index=" << cur->index << ", card=" << card << endl;
        this->PrintList();
        // 移动到下一个位置，为下一轮做准备
        cur = cur->next;
        if (cur == head)
            cur = cur->next;
    }
}

int main()
{
    CircularLinkedList list;
    //list.MagicCard();
    //list.PrintList(); 
    list.MagicCardWrong();
    list.PrintList();
    system("pause");
    return 0;
}