#include "header.h"

/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */
// 见 343.整数拆分-2.md 结尾
// @lc code=start
class Solution {
  public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            if (i <= 6) {
                dp[i] = max(max(2 * dp[i - 2], 3 * dp[i - 3]), (i / 2) * (i - i / 2));
            } else {
                dp[i] = max(2 * dp[i - 2], 3 * dp[i - 3]);
            }
        }
        return dp[n];
    }
};
// @lc code=end
