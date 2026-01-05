#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    const char *str = "C++\0Program";
    int length = strlen(str);
    cout << "Length of the string: " << length << endl;

    char buffer[] = "C++\0Program";
    int bufferLength = strlen(buffer);
    cout << "sizeof(buffer): " << sizeof(buffer) << endl;
    return 0;
}