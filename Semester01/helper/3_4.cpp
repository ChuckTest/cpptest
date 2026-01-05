#include <iostream>
using namespace std;

int main()
{
    bool symm(long n); // 声明一个检查对称性的函数
    long m;

    for (m = 11; m < 1000; m++) 
        if (symm(m) && symm(m * m) && symm(m * m * m))
            cout << "m=" << m << " m*m=" << m * m
                 << " m*m*m=" << m * m * m << endl;
    return 0;
}

bool symm(long n)
{
    long i, m;
    i = n;
    m = 0;
    while (i)
    {
        m = m * 10 + i % 10; // 反转数字
        i = i / 10;
    }
    return (n == m); // 判断是否对称
}
