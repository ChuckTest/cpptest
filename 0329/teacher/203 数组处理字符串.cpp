#include <iostream>
using namespace std;
 
// 查找第一个只出现一次的字符
char firstNotRepeatingChar(char str[]) {
    // 假设字符集为 ASCII，共 256 个字符
    int count[256] = {0};

    // 计算字符串长度
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    // 第一次遍历字符串，统计每个字符的出现次数
    for (int i = 0; i < len; ++i) {
        count[str[i]]++;
    }

    // 第二次遍历字符串，找到第一个只出现一次的字符
    for (int i = 0; i < len; ++i) {
        if (count[str[i]] == 1) {
            return str[i];
        }
    }

    return '\0';
}

int main() {
    char str[] = "abadacdeeffi";
    char result = firstNotRepeatingChar(str);
    if (result != '\0') {
        cout << "第一个只出现一次的字符是: " << result << endl;
    } else {
        cout << "没有只出现一次的字符。" << endl;
    }
    return 0;
}    
