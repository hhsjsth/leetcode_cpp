#include "header.h"

/*
 * @lc app=leetcode.cn id=1823 lang=cpp
 *
 * [1823] 找出游戏的获胜者
 */

// [1823. 找出游戏的获胜者 - 力扣（LeetCode）](https://leetcode.cn/problems/find-the-winner-of-the-circular-game/solutions/1463524/zhao-chu-you-xi-de-huo-sheng-zhe-by-leet-w2jd/) 方法二：数学 + 递归
// @lc code=start
class Solution {
  public:
    int findTheWinner(int n, int k) {
        if (n == 1) {
            return 1;
        }
        return (k + findTheWinner(n - 1, k) - 1) % n + 1;
    }
};

// @lc code=end
