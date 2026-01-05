#include <iostream>
using namespace std;

// 定义矩形类：表示平行于坐标轴的矩形
class Rectangle {
private:
    // 矩形的两个对角顶点坐标：左下角 (x1, y1) 和右上角 (x2, y2)
    double x1, y1;
    double x2, y2;
    
public:
    // 构造函数，初始化矩形的顶点
    // 假定输入满足：x1 < x2 且 y1 < y2
    Rectangle(double a, double b, double c, double d) {
        x1 = a;
        y1 = b;
        x2 = c;
        y2 = d;
    }
    
    // 获取矩形宽度，即 x 方向的长度
    double getWidth() const {
        return x2 - x1;
    }
    
    // 获取矩形高度，即 y 方向的长度
    double getHeight() const {
        return y2 - y1;
    }
    
    // 计算矩形的周长：2 * (宽度 + 高度)
    double perimeter() const {
        return 2 * (getWidth() + getHeight());
    }
    
    // 计算矩形的面积：宽度 * 高度
    double area() const {
        return getWidth() * getHeight();
    }
};

int main() {
    double a, b, c, d;
    
    // 提示用户输入左下顶点坐标
    cout << "请输入左下顶点坐标（x y）：";
    cin >> a >> b;
    
    // 提示用户输入右上顶点坐标
    cout << "请输入右上顶点坐标（x y）：";
    cin >> c >> d;
    
    // 对输入进行基本检验，确保构成的矩形合法
    if (a >= c || b >= d) {
        cout << "输入不合法，左下顶点的坐标必须小于右上顶点的坐标。" << endl;
        return 1;
    }
    
    // 创建矩形对象
    Rectangle rect(a, b, c, d);
    
    // 输出计算结果
    cout << "矩形的周长为：" << rect.perimeter() << endl;
    cout << "矩形的面积为：" << rect.area() << endl;
    
    return 0;
}
