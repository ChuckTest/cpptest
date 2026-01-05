#include <iostream>
using namespace std;
// 交换两个元素的函数
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 递归生成全排列
void permute(int nums[], int start, int end) {
    if (start == end) {
        for (int i = 0; i <= end; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    } else {
        for (int i = start; i <= end; i++) {
            swap(nums[start], nums[i]);
            permute(nums, start + 1, end);
            swap(nums[start], nums[i]); // 回溯
        }
    }
}

int main() {
    int nums[] = {1,2,3};
    int n = sizeof(nums) / sizeof(nums[0]);
    permute(nums, 0, n - 1);
    return 0;
}
