/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// https://labuladong.online/algo/essential-technique/dynamic-programming-framework/
// @lc code=start
class Solution {
  public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);

        dp[0] = 0;

        for (int i = 1; i < amount + 1; i++) {
            for (int coin : coins) {
                if (i < coin) {
                    continue;
                }
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
// @lc code=end
