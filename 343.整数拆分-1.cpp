#include "header.h"

/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */
// 参考评论区, 以完全背包问题去理解, 但是我并没有彻底理解, 只理解了最直观的官方方法 1
// @lc code=start
class Solution {
  public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 1);
        for (int i = 1; i <= n - 1; i++) {
            for (int j = i; j <= n; j++) {
                dp[j] = max(dp[j], dp[j - i] * i);
            }
        }
        return dp.back();
    }
};
// @lc code=end
