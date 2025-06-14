#include <iostream>
using namespace std;

int main()
{
    char *p = "Hello";
    cout << *p << endl;
    cout << *(p + 1) << endl;
    cout << p <<endl;

    char array[] = "Hello";
    cout << array << endl;
    cout << *(array + 1);

    return 0;
}
