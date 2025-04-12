#include <iostream>
#include <string>
#include <algorithm> // 用于 reverse 函数

using namespace std;

// 定义转换类 Converter，提供二进制和十进制之间转换的静态方法
class Converter {
public:
    // 将二进制字符串转换为十进制整数
    // 若字符串中存在非 '0' 或 '1' 的字符，则返回 -1 表示错误
    static int binaryToDecimal(const string& binaryStr) {
        int result = 0;
        for (size_t i = 0; i < binaryStr.size(); ++i) {
            char ch = binaryStr[i];
            if (ch != '0' && ch != '1') {
                return -1; // 非法字符，返回错误标志
            }
            // 乘以2相当于左移一位，再加上当前数字的值
            result = result * 2 + (ch - '0');
        }
        return result;
    }

    // 将十进制整数转换为二进制字符串
    // 处理整数为零的特殊情况
    static string decimalToBinary(int decimal) {
        if (decimal == 0) {
            return "0";
        }
        string binaryStr = "";
        // 注意：这里假定输入是非负整数
        while (decimal > 0) {
            // 取余得到当前最低位
            int remainder = decimal % 2;
            // 将余数转换为字符后添加到结果字符串末尾
            binaryStr.push_back('0' + remainder);
            // 除以2，准备下一位
            decimal /= 2;
        }
        // 由于得到的二进制是反向的，所以需要反转
        reverse(binaryStr.begin(), binaryStr.end());
        return binaryStr;
    }
};

int main() {
    int choice = 0;
    cout << "请选择转换方式：" << endl;
    cout << "1. 二进制转换为十进制" << endl;
    cout << "2. 十进制转换为二进制" << endl;
    cout << "请输入你的选择 (1 或 2): ";
    cin >> choice;
    
    if (choice == 1) {
        // 二进制转十进制
        cout << "请输入二进制数（仅包含0和1）: ";
        string binaryInput;
        cin >> binaryInput;
        int decimalResult = Converter::binaryToDecimal(binaryInput);
        if (decimalResult == -1) {
            cout << "输入的二进制字符串包含非法字符！" << endl;
        } else {
            cout << "转换后的十进制整数为: " << decimalResult << endl;
        }
    } else if (choice == 2) {
        // 十进制转二进制
        cout << "请输入十进制整数（非负）: ";
        int decimalInput;
        cin >> decimalInput;
        if (decimalInput < 0) {
            cout << "请输入非负整数！" << endl;
        } else {
            string binaryResult = Converter::decimalToBinary(decimalInput);
            cout << "转换后的二进制字符串为: " << binaryResult << endl;
        }
    } else {
        cout << "无效的选择！" << endl;
    }

    return 0;
}
