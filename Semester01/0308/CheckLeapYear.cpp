#include <iostream>
using namespace std;
//反复根据输入的年份判断是平年还是闰年，直至输入0，结束运行
int main()
{
    while (true)
    {
        int year;
        cout << "Please input a year:" << endl;
        cin >> year;
        if (year == 0)
        {
            break;
        }
        if ((year % 4 == 0 && year % 100 != 0) ||( year % 400 == 0))
        {
            cout << year << " is a leap year." << endl;
        }
        else
        {
            cout << year << " is not a leap year." << endl;
        }
    }

    return 0;
}