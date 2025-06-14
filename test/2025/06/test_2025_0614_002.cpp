#include <iostream>
using namespace std;
class A
{
public:
    A(int i);     // 构造函数声明
    void print(); // 成员函数声明
    const int &r; // 常引用成员（公有）

private:
    const int a;        // 常数据成员（私有）
    static const int b; // 静态常数据成员（私有）
};

const int A::b = 10;        // 在类外定义并初始化静态常数据成员
A::A(int i) : a(i), r(a) {} // 构造函数实现，使用初始化列表给常数据成员和常引用成员赋值
void A::print()
{
    cout << a << ": " << b << ": " << r << endl;
}
int main()
{
    /*建立对象a1和a2，并以100和0作为初值，分别调用构造函数，通过构造函数的初始化列表给对象的常数据成员赋初值*/
    A a1(100), a2(0);
    a1.print();
    a2.print();
    return 0;
}