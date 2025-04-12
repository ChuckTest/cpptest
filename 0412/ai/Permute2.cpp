#include <iostream>
#include <vector>
using namespace std;
//by ChatGPT
class Solution {
public:
    // 主函数：返回给定数组所有可能的全排列
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;            // 用于存放最终的排列结果
        vector<int> path;                      // 当前排列（解）路径
        vector<bool> used(nums.size(), false); // 标记数组：记录每个元素是否已在当前排列中使用

        // 开始递归回溯
        backtrack(nums, path, used, result);
        return result;
    }

private:
    // 递归回溯函数
    void backtrack(const vector<int>& nums, vector<int>& path, vector<bool>& used, vector<vector<int>>& result) {
        // 终止条件：当路径中的元素数量等于原数组大小时，形成了一个完整的排列
        if (path.size() == nums.size()) {
            result.push_back(path); // 将当前排列加入结果
            return;
        }

        // 遍历所有数字，选取未使用的数字加入当前排列
        for (size_t i = 0; i < nums.size(); ++i) {
            if (used[i]) {   // 如果当前数字已经被使用，则跳过
                continue;
            }
            // 做选择：标记当前数字为已使用，并添加到路径中
            used[i] = true;
            path.push_back(nums[i]);

            // 继续递归，选取下一个数字
            backtrack(nums, path, used, result);

            // 撤销选择：回溯时恢复现场，以便尝试其他组合
            path.pop_back();
            used[i] = false;
        }
    }
};

int main() {
    // 示例输入
    vector<int> nums = {1, 2, 3};

    // 创建 Solution 对象调用 permute 生成全排列
    Solution solution;
    vector<vector<int>> permutations = solution.permute(nums);

    // 输出所有排列
    cout << "所有全排列为：" << endl;
    for (size_t i = 0; i < permutations.size(); ++i) {
        for (size_t j = 0; j < permutations[i].size(); ++j) {
            cout << permutations[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
