#include "header.h"

/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */
// 剑指 offer 1
// @lc code=start
// 参考 LeetCode 官方题解 2 的 C 语言解法写的 C++ 解法, 两次二分查找, 红蓝区间
class Solution {
  private:
    int binarySearchMatrixFirstColumn(vector<vector<int>> &matrix, int target) {
        // 想要查找类似于 C++ 的 upper_bound 和 lower_bound, 直接用红蓝区间
        int l = -1, h = matrix.size();
        while (l < h - 1) {
            int mid = (h - l) / 2 + l;
            if (target < matrix[mid][0]) {
                h = mid;
            } else {
                l = mid;
            }
        }

        return l;
    }

    bool binarySearchRow(vector<int> &row, int target) {
        int l = 0, h = row.size();
        while (l < h) {
            int mid = (h - l) / 2 + l;
            if (target < row[mid]) {
                h = mid;
            } else if (target > row[mid]) {
                l = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }

  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int row = binarySearchMatrixFirstColumn(matrix, target);
        if (row == -1) {
            return false;
        }

        return binarySearchRow(matrix[row], target);
    }
};

// @lc code=end
