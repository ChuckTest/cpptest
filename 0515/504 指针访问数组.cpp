#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "�����������С: ";
    cin >> n;

    int arr[100];  // �����������Ϊ100
    cout << "������" << n << "������: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // ʹ��ָ���������
    int* ptr = arr;  // ָ��������Ԫ�ص�ָ��

    cout << "\n����Ԫ�صĵ�ַ��ֵ:" << endl;
    for (int i = 0; i < n; i++) {
        // �����ǰָ��ָ��ĵ�ַ��ֵ
        cout << "��ַ: " << ptr << ", ֵ: " << *ptr << endl;
        // ָ�������ָ����һ��Ԫ��
        ptr++;
    }

    return 0;
}    
