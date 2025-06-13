#include <iostream>
using namespace std;
class Clock // 时钟类声明
{
public: // 外部接口
	Clock(int NewH = 0, int NewM = 0, int NewS = 0)
	{
		Hour = NewH;
		Minute = NewM;
		Second = NewS;
	};
	void ShowTime();
	Clock operator++();	   // 前置单目运算符重载
	Clock operator++(int); // 后置单目运算符重载
private:				   // 私有数据成员
	int Hour, Minute, Second;
};
Clock Clock::operator++() // 前置单目运算符重载函数
{
	Second++;
	if (Second >= 60)
	{
		Second = Second - 60;
		Minute++;
		if (Minute >= 60)
		{
			Minute = Minute - 60;
			Hour++;
			Hour = Hour % 24;
		}
	}
	return *this;
}
// 后置单目运算符重载
Clock Clock::operator++(int)
{ // 注意形参表中的整型参数
	Clock old = *this;
	++(*this);
	return old;
}
void Clock::ShowTime()
{
	cout << "Now Time is " << Hour << ":" << Minute << ":" << Second << endl;
}

int main()
{
	Clock myClock(23, 59, 59);
	cout << "First time output:";
	myClock.ShowTime();
	cout << "Show myClock++:";
	(myClock++).ShowTime();
	cout << "Show ++myClock:";
	(++myClock).ShowTime();
}
