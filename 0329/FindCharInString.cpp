#include <iostream>
using namespace std;

char FindCharInString(string str)
{
    int size = str.size();
    char result;
    int start = 0;
    int count = 0;
    bool flag = true;
    for (int i = 0; i < size; i++)
    {
        flag = true;
        result = str[i];
        for (int j = 0; j < size; j++)
        {
            if (result == str[j] && i != j)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            break;
        }
    }
    return result;
}

int main()
{
    string str = "abadacdeeffi";
    char result = FindCharInString(str);
    cout << result << endl;
    return 0;
}
