#include <iostream>
#include <cmath>
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
class Rectangle: public Point  //����������
{
public:	//�������к�����Ա
	void InitR(float x, float y, float w, float h)
	{InitP(x,y);W=w;H=h;}//���û��๫�г�Ա����
	float GetH() {return H;}
	float GetW() {return W;}
private:	//����˽�����ݳ�Ա
	float W,H;
};

int main()
{  Rectangle rect;
	rect.InitR(2,3,20,10);
    //ͨ�������������ʻ��๫�г�Ա
	rect.Move(3,2);  
	cout<<rect.GetX()<<','
	    <<rect.GetY()<<','
		<<rect.GetW()<<','
		<<rect.GetH()<<endl;
	//cout<<rect.X<<endl;
	return 0;
}
