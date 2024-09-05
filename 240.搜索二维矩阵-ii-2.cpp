#include "header.h"

/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// 参考 LeetCode 官方 2, 自己写使用 upper_bound
// @lc code=start
class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        for (const auto &row : matrix) {
            auto it = upper_bound(row.begin(), row.end(), target);
            if (it != row.begin() && *(it - 1) == target) {
                return true;
            }
        }
        return false;
    }
};

// @lc code=end
