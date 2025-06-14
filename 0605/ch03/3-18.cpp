#include <iostream>
using namespace std;

// 用递归法计算从n个人中选择k个人的排列组合数
/*
我们任选一个人（设为 A），然后有两种情况：

情况一：不选 A
→ 从剩下的 n-1 个人中选出 k 个
→ 有 C(n-1, k) 种选法

情况二：选了 A
→ 从剩下的 n-1 个人中再选出 k-1 个
→ 有 C(n-1, k-1) 种选法
*/
int comm(int n, int k)
{
    if (k == 0 || k == n)
        return 1; // 组合数的边界条件
    if (k > n)
        return 0;                                                       // 如果k大于n，返回0
    cout << n - 1 << "," << k - 1 << "  " << n - 1 << "," << k << endl; // 输出递归调用的参数
    return comm(n - 1, k - 1) + comm(n - 1, k);                         // 递归计算组合数
}

int main()
{
    int n = 2, k = 2;
    cout << "C(" << n << "," << k << ") = " << comm(n, k) << endl; // 输出组合数
    return 0;
}