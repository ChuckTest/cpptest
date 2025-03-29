#include <iostream>
using namespace std;
//编写一个求x的n次方的函数
double power(double x, int n)
{
    double result = 1.0;
    while (n > 0)
    {
        result = result * x;
        n--;
    }
    return result;
}

int main()
{
    double x = 5;
    int n = 2;
    double result = power(x, n);
    cout << "5 to the power 2 is " << result << endl;
    return 0;
}