#include <iostream>
#include <cmath>
using namespace std;
class Point	//Point类声明
{ public:	//外部接口
	Point(int xx=0, int yy=0) {X=xx;Y=yy;}
	int GetX() {return X;}
	int GetY() {return Y;}
	friend double Distance(Point &a, Point &b); 
  private:	//私有数据成员
	int X,Y;
};
double Distance( Point& a, Point& b)
{
      double dx=a.X-b.X;
      double dy=a.Y-b.Y;
      return sqrt(dx*dx+dy*dy);
}
int main()
{  Point p1(3.0, 5.0), p2(4.0, 6.0);
    double d=Distance(p1, p2);
    cout<<"The distance is "<<d<<endl;
    return 0;
}
