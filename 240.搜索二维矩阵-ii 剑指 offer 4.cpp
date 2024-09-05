#include "header.h"

/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */
// 剑指 offer 1
// LeetCode 官方 1
// @lc code=start
class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        for (const auto &row : matrix) {
            if (row[0] > target) {
                continue;
            }
            for (int element : row) {
                if (element == target) {
                    return true;
                }
            }
        }
        return false;
    }
};

// @lc code=end
