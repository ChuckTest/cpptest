#include <iostream>
#include <cmath>
using namespace std;
class Point // 基类Point类的声明
{
public: // 公有函数成员
	void InitP(float xx = 0, float yy = 0)
	{
		X = xx;
		Y = yy;
	}
	void Move(float xOff, float yOff)
	{
		X += xOff;
		Y += yOff;
	}
	float GetX() { return X; }
	float GetY() { return Y; }

private: // 私有数据成员
	float X, Y;
};
class Rectangle : private Point // 派生类声明
{
public: // 新增外部接口
	void InitR(float x, float y, float w, float h)
	{
		InitP(x, y);
		W = w;
		H = h;
	} // 访问基类公有成员
	void Move(float xOff, float yOff) { Point::Move(xOff, yOff); }
	float GetX() { return Point::GetX(); }
	float GetY() { return Point::GetY(); }
	float GetH() { return H; }
	float GetW() { return W; }

private: // 新增私有数据
	float W, H;
};

int main()
{ // 通过派生类对象只能访问本类成员
	Rectangle rect;
	rect.InitR(2, 3, 20, 10);
	rect.Move(3, 2);
	cout << rect.GetX() << ',' << rect.GetY() << ','
		 << rect.GetH() << ',' << rect.GetW() << endl;
	return 0;
}
