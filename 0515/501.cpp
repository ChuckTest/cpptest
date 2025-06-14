#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "请输入要排序的数字个数: ";
    cin >> n;

    // 创建数组存储输入的数字
    int arr[100];  // 假设最多输入100个数字
    cout << "请输入" << n << "个数字: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 冒泡排序
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // 交换arr[j]和arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // 输出排序后的结果
    cout << "排序后的数字为: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}    
