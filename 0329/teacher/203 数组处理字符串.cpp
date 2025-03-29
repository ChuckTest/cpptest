#include <iostream>
using namespace std;
 
// ���ҵ�һ��ֻ����һ�ε��ַ�
char firstNotRepeatingChar(char str[]) {
    // �����ַ���Ϊ ASCII���� 256 ���ַ�
    int count[256] = {0};

    // �����ַ�������
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    // ��һ�α����ַ�����ͳ��ÿ���ַ��ĳ��ִ���
    for (int i = 0; i < len; ++i) {
        count[str[i]]++;
    }

    // �ڶ��α����ַ������ҵ���һ��ֻ����һ�ε��ַ�
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
        cout << "��һ��ֻ����һ�ε��ַ���: " << result << endl;
    } else {
        cout << "û��ֻ����һ�ε��ַ���" << endl;
    }
    return 0;
}    
