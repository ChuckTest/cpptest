#include <windows.h>
#include <iostream>
#include <cmath>
using namespace std;

class Point
{
public:
	Point(int xx = 0, int yy = 0)
	{
		x = xx;
		y = yy;
		cout << "调用Point的构造函数, x=" << x << endl;
	}
	Point(Point &p);
	int getX() { return x; }
	int getY() { return y; }

private:
	int x, y;
};

Point::Point(Point &p)
{
	x = p.x;
	y = p.y;
	cout << "调用Point的复制构造函数, x=" << x << endl;
}

class Line
{
public:
	Line(Point xp1, Point xp2);
	Line(Line &l);
	double getLen() { return len; }

private:
	Point p1, p2; // 这个顺序决定了构造函数调用的顺序
	double len;
};

Line::Line(Point xp1, Point xp2) : p1(xp1), p2(xp2)
{
	cout << "调用Line的构造函数" << endl;
	double x = static_cast<double>(p1.getX() - p2.getX());
	double y = static_cast<double>(p1.getY() - p2.getY());
	len = sqrt(x * x + y * y);
}

Line::Line(Line &l) : p1(l.p1), p2(l.p2)
{
	cout << "调用Line的复制构造函数" << endl;
	len = l.len;
}

int main()
{
	SetConsoleOutputCP(65001);  // 控制台输出 UTF-8
	Point myp1(1, 1), myp2(4, 5);
	Line line(myp1, myp2);
	Line line2(line);
	cout << "line的长度是:";
	cout << line.getLen() << endl;
	cout << "line2的长度是:";
	cout << line2.getLen() << endl;
	return 0;
}
