#include<iostream>
using namespace std;
class complex	//����������
{
public:	//�ⲿ�ӿ�
	complex(double r=0.0,double i=0.0){real=r;imag=i;} //���캯��
	complex operator + (complex c2); //+����Ϊ��Ա����
	complex operator - (complex c2); //-����Ϊ��Ա����
	void display();	//�������
private:	//˽�����ݳ�Ա
	double real;	//����ʵ��
	double imag;	//�����鲿
};	
complex complex::operator +(complex c2) //���غ���ʵ��
{
	complex c;
	c.real=c2.real+real;
	c.imag=c2.imag+imag;
	return complex(c.real,c.imag);
}
complex complex::operator -(complex c2)  //���غ���ʵ��
{
	complex c;
	c.real=real-c2.real;
	c.imag=imag-c2.imag;
	return complex(c.real,c.imag);
}
void complex::display()
{   cout<<"("<<real<<","<<imag<<")"<<endl; }

void main()     //������
{	complex c1(5,4),c2(2,10),c3;  //����������Ķ���
	cout<<"c1="; c1.display();
	cout<<"c2="; c2.display();
	c3=c1-c2;	//ʹ�������������ɸ�������
	cout<<"c3=c1-c2=";
	c3.display();
	//c3=c1+c2;	//ʹ�������������ɸ����ӷ�
	c3=c1+complex(2,10);
	cout<<"c3=c1+c2=";
	c3.display();
}
