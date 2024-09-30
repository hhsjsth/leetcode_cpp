#include "header.h"

/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
// 纯自己写, 不参考 leetcode 官方题解
// 但是官方的教程更加简洁
// @lc code=start
class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        // 是一种左闭右开的思想
        // 借用前端的 padding 概念进行变量命名
        int padding = 1;
        int i = 0;
        int j = 0;
        int m = matrix.size(), n = matrix[0].size();
        // 答案计数器
        int count = 0;
        // 圈数
        int loop = min(m, n) / 2;
        vector<int> res(m * n);
        while (loop--) {
            for (; j < n - padding; ++j) {
                res[count++] = matrix[i][j];
            }
            for (; i < m - padding; ++i) {
                res[count++] = matrix[i][j];
            }
            for (; j > padding - 1; --j) {
                res[count++] = matrix[i][j];
            }
            for (; i > padding - 1; --i) {
                res[count++] = matrix[i][j];
            }
            // 由于前面进行了 --j 和 --i, 所以进行下一圈的时候要将 i 和 j 恢复
            ++i;
            ++j;
            ++padding;
        }

        // 根据长或宽是否为奇数进行补全
        if (m < n && m % 2 == 1) {
            // 需注意, n - padding + 1 是因为前面的 while 循环导致了需要将 padding 复位
            for (; j < n - padding + 1; ++j) {
                res[count++] = matrix[i][j];
            }
        } else if (n < m && n % 2 == 1) {
            for (; i < m - padding + 1; ++i) {
                res[count++] = matrix[i][j];
            }
        } else if (m == n && m % 2 == 1) {
            res[count++] = matrix[i][j];
        }
        return res;
    }
};
// @lc code=end
