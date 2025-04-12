#include <iostream>
using namespace std;
class Rectangle
{
private:
    double x1, y1;
    double x2, y2;

public:
   
    Rectangle(double tempx1, double tempy1, double tempx2, double tempy2) : x1(tempx1), y1(tempy1), x2(tempx2), y2(tempy2)
    {
    }

    /*
    Rectangle(double tempx1, double tempy1, double tempx2, double tempy2){
        x1=tempx1;
        y1=tempy1;
        x2=tempx2;
        y2=tempy2;
    }
    */

    double GetPerimeter()
    {
        return 2 * (x2 - x1) + 2 * (y2 - y1);
    }

    double GetArea()
    {
        return (x2 - x1) * (y2 - y1);
    }
};

int main()
{
    Rectangle a(-1, -2, 4, 5);
    cout << "Perimeter is "<<a.GetPerimeter()<<endl;
    cout << "Area is " <<a.GetArea()<<endl;
    return 0;
}