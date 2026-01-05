#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BST
{
};

// 解析输入字符串为整数数组
vector<int> parseInput(const string &input)
{
    vector<int> nums;
    int num = 0;
    bool isNumber = false;

    for (char ch : input)
    {
        if (isspace(ch))
        {
            // 如果遇到空格，表示当前数字结束
            if (isNumber)
            {
                nums.push_back(num); // 添加当前累积的数字到向量
                num = 0;             // 重置当前数字
                isNumber = false;    // 标记当前不是数字
            }
        }
        else if (isdigit(ch))
        {
            // 如果是数字，累积当前数字
            num = num * 10 + (ch - '0'); // 将当前数字累积（十进制）
            isNumber = true;
        }
    }

    // 最后一个数字处理，若有数字
    if (isNumber)
    {
        nums.push_back(num);
    }

    return nums;
}

int main()
{
    // 设置控制台输出 UTF-8 编码
    SetConsoleOutputCP(65001);

    BST tree;
    while (true)
    {
        cout << "\n【主菜单】\n"
             << "1. 插入数据\n"
             << "2. 删除数据\n"
             << "3. 前序遍历\n"
             << "4. 中序遍历\n"
             << "5. 后序遍历\n"
             << "6. 查询节点\n"
             << "0. 退出系统\n"
             << "请选择操作: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "请输入要插入的数字（空格分隔）: ";
            string input;
            getline(cin, input);
            vector<int> nums = parseInput(input);
            for (int num : nums)
                tree.insert(num);
            cout << "&#9989; 插入完成！\n";
            break;
        }
        case 2:
        {
            cout << "请输入要删除的数字: ";
            int val;
            cin >> val;
            tree.remove(val);
            cout << "&#128465;️ 删除完成！\n";
            break;
        }
        case 3:
        {
            vector<int> res = tree.preorder();
            cout << "&#128316; 前序遍历结果: ";
            for (int num : res)
                cout << num << " ";
            cout << "\n";
            break;
        }
        case 4:
        {
            vector<int> res = tree.inorder();
            cout << "&#8596;️ 中序遍历结果: ";
            for (int num : res)
                cout << num << " ";
            cout << "\n";
            break;
        }
        case 5:
        {
            vector<int> res = tree.postorder();
            cout << "&#11015;️ 后序遍历结果: ";
            for (int num : res)
                cout << num << " ";
            cout << "\n";
            break;
        }
        case 6:
        {
            cout << "请输入要查询的数字: ";
            int val;
            cin >> val;
            if (tree.contains(val))
                cout << "&#127881; 找到节点 " << val << " !\n";
            else
                cout << "&#10060; 未找到节点 " << val << " !\n";
            break;
        }
        case 0:
            tree.clear(); // 释放内存
            cout << "&#128075; 感谢使用！\n";
            return 0;
        default:
            cout << "&#9888;️ 无效指令！\n";
        }
    }

    system("pause");
    return 0;
}