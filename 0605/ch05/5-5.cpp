#include <iostream>
using namespace std;
class Point	//Point������
{public:	//�ⲿ�ӿ�
	Point(int xx=0, int yy=0) {X=xx;Y=yy;countP++;}	
	Point(Point &p);	//�������캯��
	int GetX() {return X;}
	int GetY() {return Y;}
	static void GetC()
        {cout<<" Object id="<<countP<<endl;}	
private:	//˽�����ݳ�Ա
	int X,Y;
	static int countP;
};
Point::Point(Point &p)
{	X=p.X;
	Y=p.Y;
	countP++;
}
int Point::countP=0;	
void main()	//������ʵ��
{	Point A(4,5);	//��������A
	cout<<"Point A,"<<A.GetX()<<","<<A.GetY();
	A.GetC();	//�������ţ�����������
	Point B(A);	//��������B
	cout<<"Point B,"<<B.GetX()<<","<<B.GetY();
	Point::GetC();	//�������ţ���������
}
