//https://bloomfield.online/posts/order-of-parameter-evaluation-in-cpp/
#include <iostream>

void doStuff(int a, int b) { }

int getA()
{
    std::cout << "A";
    return 1;
}

int getB()
{
    std::cout << "B";
    return 2;
}

int main()
{
    doStuff( getA(), getB() );
}

//The C++17 standard defines the order of evaluation under certain circumstances. 
//However, it will not affect the example above.