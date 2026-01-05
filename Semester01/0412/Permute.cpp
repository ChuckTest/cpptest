#include <iostream>
using namespace std;
void Combine(int temp[])
{
    int size = sizeof(temp);
    if (size == 0)
    {
        return;
    }
    if (size == 1)
    {
        cout << temp[0];
    }
}

int main()
{
    int nums[5] = {1, 2, 3, 4, 5};
    int length = sizeof(nums);
    Combine(nums);
}
