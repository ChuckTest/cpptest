#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "请输入数组大小: ";
    cin >> n;

    int arr[100];  // 假设数组最大为100
    cout << "请输入" << n << "个整数: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 使用指针遍历数组
    int* ptr = arr;  // 指向数组首元素的指针

    cout << "\n数组元素的地址和值:" << endl;
    for (int i = 0; i < n; i++) {
        // 输出当前指针指向的地址和值
        cout << "地址: " << ptr << ", 值: " << *ptr << endl;
        // 指针递增，指向下一个元素
        ptr++;
    }

    return 0;
}    
