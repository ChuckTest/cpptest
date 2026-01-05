#include <iostream>
using namespace std;
class B1 // 基类B1，构造函数有参数
{
public:
	B1(int i) { cout << "constructing B1 " << i << endl; }
};
class B2 // 基类B2，构造函数有参数
{
public:
	B2(int j) { cout << "constructing B2 " << j << endl; }
};
class B3 // 基类B3，构造函数无参数
{
public:
	B3() { cout << "constructing B3 *" << endl; }
};
class C : public B2, public B1, public B3
//基类构造：按继承声明顺序 class C : public B2, public B1, public B3
{
public: // 派生类的公有成员
	C(int a, int b, int c, int d) : B1(a), memberB2(d), memberB1(c), B2(b) {}

private: // 派生类的私有对象成员 
//成员对象构造：按成员声明顺序
	B1 memberB1;
	B2 memberB2;
	B3 memberB3;
};
int main()
{
	//基类构造函数先执行，顺序按它们在继承列表中出现的顺序（不是初始化列表中写的顺序）。
	//成员变量构造函数随后执行，顺序按它们在类中声明的顺序（不是初始化列表的顺序）。
	C obj(1, 2, 3, 4);
	return 0;
}
/*
constructing B2 2
constructing B1 1
constructing B3 *
constructing B1 3
constructing B2 4
constructing B3 *
*/