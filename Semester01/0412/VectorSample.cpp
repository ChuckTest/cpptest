#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 创建一个整数 vector，初始为空
    vector<int> numbers;

    // 使用 push_back 向 vector 末尾添加元素
    numbers.push_back(10);  // vector 现在为 {10}
    numbers.push_back(20);  // vector 现在为 {10, 20}
    numbers.push_back(30);  // vector 现在为 {10, 20, 30}

    // 输出当前 vector 的内容
    cout << "当前 vector 中的元素：";
    for (size_t i = 0; i < numbers.size(); ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    // 使用 pop_back 移除最后一个元素
    numbers.pop_back();  // 移除 30，vector 现在为 {10, 20}

    // 再次输出 vector 的内容
    cout << "调用 pop_back 后 vector 中的元素：";
    for (size_t i = 0; i < numbers.size(); ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
