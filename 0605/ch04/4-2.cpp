#include "iostream"
using namespace std;
class Point
{
   public:
       Point(int xx=0,int yy=0){X=xx; Y=yy;}
       Point(Point&  p);
       int GetX() {return X;}
       int GetY() {return Y;}
	   void SetX(int x) {X=x;}
	   void SetY(int y) {Y=y;}
   private:
       int  X,Y;
};

Point::Point (Point&  p)
{
      X=p.X;
      Y=p.Y;
      cout<<"复制构造函数被调用"<<endl;
}

void main(){
	Point myP(12,12);
	cout<<"第一个点（"<<myP.GetX()<<", "<<myP.GetY()<<"）"<<endl;
	Point myP1(myP);
	cout<<"第二个点（"<<myP1.GetX()<<", "<<myP1.GetY()<<"）"<<endl;
	myP1.SetX(100);
	myP1.SetY(100);
	cout<<"重新赋值后，第二个点（"<<myP1.GetX()<<", "<<myP1.GetY()<<"）"<<endl;
}