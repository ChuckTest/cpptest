#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "���������ֵĸ���: ";
    cin >> n;

    // ��������洢���������
    int arr[100];  // �����������100������
    cout << "������" << n << "������: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // �����ܺ�
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // ����ƽ��ֵ
    double average = (double)(sum) / n;

    // ͳ�Ƹ���ƽ��ֵ��Ԫ�ظ���
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > average) {
            count++;
        }
    }

    // ������
    cout << "ƽ��ֵ: " << average << endl;
    cout << "����ƽ��ֵ��Ԫ�ظ���: " << count << endl;

    return 0;
}    
