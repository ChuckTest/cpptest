#include <iostream>
using namespace std;
//输出螺旋矩阵
int main() {
    int n;
    cout << "请输入矩阵的大小N: ";
    cin >> n;

    // 创建并初始化N×N的矩阵
    int matrix[100][100] = {0};
    int value = 1;  // 初始填充值

    // 定义边界
    int top = 0, bottom = n - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        // 从左到右填充顶部行
        for (int i = left; i <= right; i++) {
            matrix[top][i] = value++;
        }
        top++;

        // 从上到下填充右侧列
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = value++;
        }
        right--;

        // 从右到左填充底部行
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = value++;
            }
            bottom--;
        }

        // 从下到上填充左侧列
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = value++;
            }
            left++;
        }
    }

    // 输出矩阵
    cout << "生成的螺旋矩阵为:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout.width(4);  // 设置宽度为4，右对齐
            cout << matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}    
