#include <iostream>
using namespace std;
const float PI = 3.14159;
const float FencePrice = 35;
const float ConcretePrice = 20;

//������Circle �������ݺͷ���
class Circle
{
  private:
    float   radius;
       
  public:
    Circle(float r);  //���캯������ʼ���뾶
        
    float Circumference(); //Բ�ܳ�
    float Area();  //Բ���
};
// ���ʵ��
// ���캯����ʼ�����ݳ�Աradius
Circle::Circle(float r)
{
	radius=r;
}

// ����Բ���ܳ�
float Circle::Circumference() 
{
    return 2 * PI * radius;
}
        
// ����Բ����� 
float Circle::Area() 
{
    return PI * radius * radius;
}
void main ()
{
  float radius;
  float FenceCost, ConcreteCost; 
  
  // ��ʾ�û�����뾶
  cout<<"Enter the radius of the pool: ";
  cin>>radius;

  // ���� Circle ����
  Circle Pool(radius);
  Circle PoolRim(radius + 3);       
// ����դ����۲����
    FenceCost = PoolRim.Circumference() * FencePrice;
    cout << "Fencing Cost is ��" << FenceCost << endl;
    
    //  ���������۲����
    ConcreteCost = (PoolRim.Area() - Pool.Area())*ConcretePrice;
    cout << "Concrete Cost is ��" << ConcreteCost << endl;
}
