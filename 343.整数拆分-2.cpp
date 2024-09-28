#include "header.h"

/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */
// 类似于官方方法 2, 但是又不太一样. 不要看官方的写法和推理过程, 太复杂了, 自己总结如下 343.整数拆分-2.md
// @lc code=start
class Solution {
  public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            dp[i] = max(max(2 * dp[i - 2], 3 * dp[i - 3]), (i / 2) * (i - i / 2));
        }
        return dp[n];
    }
};
// @lc code=end
