#include <iostream>
using namespace std;
class B1	//��������B1
{ public:	//�ⲿ�ӿ�
	int nV;
	void fun()  {cout<<"Member of B1"<<endl;}
};
class B2	//��������B2
{ public:	//�ⲿ�ӿ�
	int nV;
	void fun(){cout<<"Member of B2"<<endl;}
};
class D1: public B1, public B2	 
{ public:
	int nV;	//ͬ�����ݳ�Ա
	void fun(){cout<<"Member of D1"<<endl;}	//ͬ��������Ա
};
void main()
{	D1 d1;
	d1.nV=1;  //������.��Ա����ʶ, ����D1���Ա
	d1.fun();	         
	
	d1.B1::nV=2;	//������ֱ����ʶ, ���ʻ���B1��Ա
	d1.B1::fun();	
	
	d1.B2::nV=3;	//������ֱ����ʶ, ���ʻ���B2��Ա
	d1.B2::fun();	
}
