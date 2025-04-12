#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

class Converter
{
private:
    stack<int> tempStack;

public:
    void DecimalToBinary(int number)
    {
        int temp = number;
        int remainder = 0;
        while (temp != 0)
        {
            remainder = temp % 2;
            tempStack.push(remainder);
            temp = temp / 2;
        }
        //tempStack.push(0);
        while (!tempStack.empty())
        {
            cout << tempStack.top();
            tempStack.pop();
        }
    }

    void BinaryToDecimal(string str)
    {
        int length = str.size();
        int number = 0;
        int count = 0;
        for (int i = length - 1; i >= 0; i--)
        {
            if (str[i] == '1')
            {
                number += pow(2, count);
            }
            count++;
        }
        cout << str << " map to decimal " << number << endl;
    }
};

int main()
{
    Converter con;
    con.BinaryToDecimal("11010101");
    con.DecimalToBinary(15);
    return 0;
}