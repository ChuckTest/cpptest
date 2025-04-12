#include <vector>
#include <vector>
//by Gemini 2.5 Pro
class Solution {
private:
    std::vector<std::vector<int>> result; // 存储所有排列结果
    std::vector<int> path;               // 存储当前正在构建的排列
    std::vector<bool> used;              // 标记 nums 中的元素是否已被当前 path 使用

    // 递归函数
    // nums: 原始输入数组 (只读)
    void backtrack(const std::vector<int>& nums) {
        // 3. 结束条件：当路径长度等于 nums 长度时，找到一个完整排列
        if (path.size() == nums.size()) {
            result.push_back(path); // 将当前路径的一个副本添加到结果集中
            return;                 // 返回上一层递归
        }

        // 遍历 nums 中的所有元素，尝试将其加入路径
        for (int i = 0; i < nums.size(); ++i) {
            // 2. 选择列表：只选择尚未被使用的元素
            if (!used[i]) {
                // --- 做选择 ---
                path.push_back(nums[i]); // 将 nums[i] 加入当前路径
                used[i] = true;          // 标记 nums[i] 为已使用

                // --- 进入下一层决策 ---
                backtrack(nums); // 递归调用，填充下一个位置

                // --- 撤销选择 (回溯) ---
                used[i] = false;         // 恢复标记，nums[i] 变为未使用状态
                path.pop_back();         // 将 nums[i] 从当前路径中移除
                                         // 这样才能在 for 循环的下一次迭代中尝试其他选择
            }
        }
    }

public:
    // 主函数，初始化并启动回溯
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        result.clear(); // 清空结果集（如果 Solution 对象被复用）
        path.clear();   // 清空路径
        used.assign(nums.size(), false); // 初始化 used 数组，大小与 nums 相同，全为 false

        backtrack(nums); // 开始递归过程

        return result; // 返回收集到的所有排列
    }
};