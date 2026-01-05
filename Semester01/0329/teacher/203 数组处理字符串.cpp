#include <iostream>
using namespace std;

// Find the first character that appears only once
char firstNotRepeatingChar(char str[])
{
    // Assume the character set is ASCII with 256 characters
    int count[256] = {0};

    // Calculate the length of the string
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }

    // First pass through the string to count the occurrences of each character
    for (int i = 0; i < len; ++i)
    {
        count[str[i]]++;
    }

    // Second pass through the string to find the first character that appears only once
    for (int i = 0; i < len; ++i)
    {
        if (count[str[i]] == 1)
        {
            return str[i];
        }
    }

    return '\0';
}

int main()
{
    char str[] = "abadacdeeffi";
    char result = firstNotRepeatingChar(str);
    if (result != '\0') {
        cout << "The first character that appears only once is: " << result << endl;
    } else {
        cout << "There is no character that appears only once." << endl;
    }
    return 0;
}
