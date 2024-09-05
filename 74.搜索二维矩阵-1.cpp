#include "header.h"

/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */
// 剑指 offer 1
// @lc code=start
// 参考 LeetCode 官方题解 2, 二分法左闭右开
class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m * n;
        while (low < high) {
            int mid = (high - low) / 2 + low;
            int x = matrix[mid / n][mid % n];
            if (target > x) {
                low = mid + 1;
            } else if (target < x) {
                high = mid;
            } else {
                return true;
            }
        }
        return false;
    }
};

// @lc code=end
