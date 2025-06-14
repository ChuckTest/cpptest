```c++
#include<iostream>
using namespace std;
class A {
	public:
		A(int i);
		void print();
		const int& r;
	private:
		const int a;
		static const int b; // 静态常数据成员
}
coust int A::b = 10;
A::(int i):a(i), r(a) {}
void A::print() {
	cout << a << ": " << b << ": " << r << endl;
}
void main() {
	/*建立对象a1和a2，并以100和0作为初值，分别调用构造函数，通过构造函数的初始化列表给对象的常数据成员赋初值*/
	A a1(100), a2(0);
	a1.print();
	a2.print();
}
```