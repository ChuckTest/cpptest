#include <iostream>
using namespace std;
class B0 // 基类B0声明
{
public:
	void display() { cout << "B0::display()" << endl; } // 公有成员函数
};
class B1 : public B0
{
public:
	void display() { cout << "B1::display()" << endl; }
};
class D1 : public B1
{
public:
	void display() { cout << "D1::display()" << endl; }
};
void fun(B0 *ptr)
{
	ptr->display(); //"对象指针->成员名"
}
int main() // 主函数
{
	B0 b0;	 // 声明B0类对象
	B1 b1;	 // 声明B1类对象
	D1 d1;	 // 声明D1类对象
	B0 *p;	 // 声明B0类指针
	p = &b0; // B0类指针指向B0类对象
	fun(p);
	p = &b1; // B0类指针指向B1类对象
	fun(p);
	p = &d1; // B0类指针指向D1类对象
	fun(p);
	return 0;
}
