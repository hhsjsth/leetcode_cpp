#include "header.h"

/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */
// 剑指 offer 1
// @lc code=start
// 参考 LeetCode 官方题解 2 的 C 语言解法写的 C++ 解法, 两次二分查找, 左闭右开
class Solution {
  private:
    int binarySearchMatrixFirstColumn(vector<vector<int>> &matrix, int target) {
        int l = 0, h = matrix.size();
        while (l < h) {
            int mid = (h - l) / 2 + l;
            if (target < matrix[mid][0]) {
                h = mid;
            } else {
                l = mid + 1;
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
        if (row == 0) {
            return false;
        }

        row--;
        return binarySearchRow(matrix[row], target);
    }
};

// @lc code=end
