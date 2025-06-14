#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "请输入数字的个数: ";
    cin >> n;

    // 创建数组存储输入的数字
    int arr[100];  // 假设最多输入100个数字
    cout << "请输入" << n << "个数字: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 计算总和
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // 计算平均值
    double average = (double)(sum) / n;

    // 统计高于平均值的元素个数
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > average) {
            count++;
        }
    }

    // 输出结果
    cout << "平均值: " << average << endl;
    cout << "高于平均值的元素个数: " << count << endl;

    return 0;
}    
