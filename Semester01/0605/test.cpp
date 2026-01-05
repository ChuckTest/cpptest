#include <iostream>
using namespace std;
class A
{
public:
    virtual void f()
    {
        cout << 1;
    }
    void g()
    {
        cout << 2;
    }
};

class B : public A
{
public:
    virtual void f()
    {
        cout << 3;
    }
    void g()
    {
        cout << 4;
    }
};

void show(A &a)
{
    a.f();
    a.g();
}

void show2(A a){
    a.f();
    a.g();
}

int main()
{
    B b;
    show(b);
    cout<<endl;
    show2(b);
    cout<<endl;
    system("pause");
    return 0;
}