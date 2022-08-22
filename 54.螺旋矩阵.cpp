/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        // 纯自己写, 不参考 leetcode 官方题解
        // 是一种左闭右开的思想
        int offset = 1;
        int i = 0;
        int j = 0;
        int m = matrix.size(), n = matrix[0].size();
        int count = 0;
        int loop = min(m, n) / 2;
        vector<int> res(m * n);
        while (loop--) {
            for (; j < n - offset; ++j) {
                res[count++] = matrix[i][j];
            }
            for (; i < m - offset; ++i) {
                res[count++] = matrix[i][j];
            }
            for (; j > offset - 1; --j) {
                res[count++] = matrix[i][j];
            }
            for (; i > offset - 1; --i) {
                res[count++] = matrix[i][j];
            }
            ++i;
            ++j;
            ++offset;
        }
        if (m < n && m % 2 == 1) {
            for (; j < n - offset + 1; ++j) {
                res[count++] = matrix[i][j];
            }
        } else if (n < m && n % 2 == 1) {
            for (; i < m - offset + 1; ++i) {
                res[count++] = matrix[i][j];
            }
        } else if (m == n && m % 2 == 1) {
            res[count++] = matrix[i][j];
        }
        return res;
    }
};
// @lc code=end
