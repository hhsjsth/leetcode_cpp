#include "header.h"

/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */
// 官方有两个优化方法, 挺难理解的, 没有写
// @lc code=start
class Solution {
  public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        for (int i = 2; i <= n; i++) {
            int curMax = 0;
            for (int j = 1; j < i; j++) {
                // 易错
                // 需理解
                // 记得将 j * (i - j) 也要作为候选, 因为因为 dp[x] 表示 x 拆分为至少 2 个以上的正整数的乘积, 这个乘积 dp[x] 和 x 没有直接的关系, 可能比 x 小
                // 同时, 也不需要将 dp[j] * dp[i - j] 作为候选, 因为 j 是从 1 开始的, 属于拆分的第一部分, 这部分从最小开始遍历, 如果使用 dp[j], 则说明 j 需要进行拆分, 但是实际上 j 已经是从 1 开始的, 所以不需要拆分, 所以不需要 dp[j], 所以不需要 dp[j] * dp[i - j]
                curMax = max(curMax, max(j * (i - j), j * dp[i - j]));
            }
            dp[i] = curMax;
        }
        return dp[n];
    }
};
// @lc code=end
