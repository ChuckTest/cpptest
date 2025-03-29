#include <iostream>
using namespace std;

char FindCharInString(string str)
{
    int size = str.size();
    char result = '\0';
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
                result = '\0';
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
    // string str = "abadacdeeffi";
    string str = "aabbcc";
    char result = FindCharInString(str);
    if (result != '\0')
    {
        cout << result << endl;
    }
    else
    {
        cout << "Can not find" << endl;
    }
    return 0;
}
