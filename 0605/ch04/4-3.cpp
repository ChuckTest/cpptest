#include <windows.h>
#include <iostream>
using namespace std;
const float PI = 3.14159;
const float FencePrice = 35;
const float ConcretePrice = 20;

// 声明类Circle 及其数据和方法
class Circle
{
private:
  float radius;

public:
  Circle(float r); // 构造函数，初始化半径

  float Circumference(); // 圆周长
  float Area();          // 圆面积
};
// 类的实现
// 构造函数初始化数据成员radius
Circle::Circle(float r)
{
  radius = r;
}

// 计算圆的周长
float Circle::Circumference()
{
  return 2 * PI * radius;
}

// 计算圆的面积
float Circle::Area()
{
  return PI * radius * radius;
}
int main()
{
  SetConsoleOutputCP(65001); // 控制台输出 UTF-8
  float radius;
  float FenceCost, ConcreteCost;

  // 提示用户输入半径
  cout << "Enter the radius of the pool: ";
  cin >> radius;

  // 声明 Circle 对象
  Circle Pool(radius);
  Circle PoolRim(radius + 3);
  // 计算栅栏造价并输出
  FenceCost = PoolRim.Circumference() * FencePrice;
  cout << "Fencing Cost is ￥" << FenceCost << endl;

  //  计算过道造价并输出
  ConcreteCost = (PoolRim.Area() - Pool.Area()) * ConcretePrice;
  cout << "Concrete Cost is ￥" << ConcreteCost << endl;
}
