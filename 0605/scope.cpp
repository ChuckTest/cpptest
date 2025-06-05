#include <iostream>
using namespace std;
int i = 2;
int main(void)
{
    static int a;
    int b = 5;
    int c = 2;
    void other(void);
    cout << "MAIN Sub" << endl;
    cout << " i: " << i << " a: " << a << " b: " << b << " c: " << c << endl;
    c = c + 1;
    other();
    cout << "MAIN Sub" << endl;
    cout << " i: " << i << " a: " << a << " b: " << b << " c: " << c << endl;
    i = i + 2;
    other();
    return 0;
}
void other(void)
{
    static int a = 0;
    static int b;
    int c = 6;
    a = a + 1;
    i = 3 * i;
    c = c + 5;
    cout << "OTHER Sub" << endl;
    cout << " i: " << i << " a: " << a << " b: " << b << " c: " << c << endl;
    b = a + 1;
}
