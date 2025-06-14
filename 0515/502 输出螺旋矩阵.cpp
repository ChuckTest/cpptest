#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "���������Ĵ�СN: ";
    cin >> n;

    // ��������ʼ��N��N�ľ���
    int matrix[100][100] = {0};
    int value = 1;  // ��ʼ���ֵ

    // ����߽�
    int top = 0, bottom = n - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        // ��������䶥����
        for (int i = left; i <= right; i++) {
            matrix[top][i] = value++;
        }
        top++;

        // ���ϵ�������Ҳ���
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = value++;
        }
        right--;

        // ���ҵ������ײ���
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = value++;
            }
            bottom--;
        }

        // ���µ�����������
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = value++;
            }
            left++;
        }
    }

    // �������
    cout << "���ɵ���������Ϊ:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout.width(4);  // ���ÿ��Ϊ4���Ҷ���
            cout << matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}    
