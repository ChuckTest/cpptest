#include <windows.h>
#include <iostream>
using namespace std;

int main()
{
    SetConsoleOutputCP(65001); // 控制台输出 UTF-8
    char *p = "Hello";
    cout << *p << endl;
    cout << *(p + 1) << endl;
    cout << p << endl;
    cout << static_cast<void *>(p) << endl;

    char array[] = "Hello";
    cout << array << endl;
    cout << *(array + 1) << endl;

    cout << "数组首地址（array）: " << static_cast<void *>(array) << endl;
    // 打印每个字符的地址和内容
    for (int i = 0; i < sizeof(array); ++i)
    {
        cout << "array[" << i << "] = '" << array[i] << "'"
             << " 地址: " << static_cast<void *>(&array[i]) << endl;
    }
    return 0;
}
