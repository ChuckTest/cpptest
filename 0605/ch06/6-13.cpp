﻿#include <iostream>
using namespace std;
class Point	//Point类声明
{
public:	//外部接口
	Point(int xx=0, int yy=0) {X=xx;Y=yy;countP++;}//构造函数
	Point(Point &p);	//拷贝构造函数
	int GetX() {return X;}
	int GetY() {return Y;}
	static int countP;	//静态数据成员引用性说明
private:	//私有数据成员
	int X,Y;
};
Point::Point(Point &p)
{	X=p.X;  Y=p.Y;  countP++;  }

int Point::countP=0;	//静态数据成员定义性说明
void main()	//主函数
{   //声明一个int型指针，指向类的静态成员
	int *count=&Point::countP; 
	Point A(4,5);	//声明对象A
	cout<<"Point A,"<<A.GetX()<<","<<A.GetY();
    //直接通过指针访问静态数据成员
	cout<<" Object id="<<*count<<endl;	
	Point B(A);	//声明对象B
	cout<<"Point B,"<<B.GetX()
           <<","<<B.GetY();
	cout<<" Object id="<<A.countP<<endl; 	
}
