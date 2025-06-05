#include<iostream>
#include<cmath>
using namespace std;
class Point	//����Point�������
{public:	//���к�����Ա
	void InitP(float xx=0, float yy=0)
    {X=xx;Y=yy;}
	void Move(float xOff, float yOff)
    {X+=xOff;Y+=yOff;}
	float GetX() {return X;}
	float GetY() {return Y;}
private:	//˽�����ݳ�Ա
	float X,Y;
};
class Rectangle: private Point	//����������
{public:	//�����ⲿ�ӿ�
	void InitR(float x, float y, float w, float h)
	{InitP(x,y);W=w;H=h;}	//���ʻ��๫�г�Ա
	void Move(float xOff, float yOff) {Point::Move(xOff,yOff);}
	float GetX() {return Point::GetX();}
	float GetY() {return Point::GetY();}
	float GetH() {return H;}
	float GetW() {return W;}
private:	//����˽������
	float W,H;
};

int main()
{  //ͨ�����������ֻ�ܷ��ʱ����Ա
    Rectangle rect;
	rect.InitR(2,3,20,10);
	rect.Move(3,2);
	cout<<rect.GetX()<<',' <<rect.GetY()<<','
		<<rect.GetH()<<','<<rect.GetW()<<endl;
	return 0;
}
