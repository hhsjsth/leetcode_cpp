#include "header.h"

/*
 * @lc app=leetcode.cn id=1823 lang=cpp
 *
 * [1823] 找出游戏的获胜者
 */

// [1823. 找出游戏的获胜者 - 力扣（LeetCode）](https://leetcode.cn/problems/find-the-winner-of-the-circular-game/solutions/1463524/zhao-chu-you-xi-de-huo-sheng-zhe-by-leet-w2jd/) 方法一：模拟 + 队列
// @lc code=start
class Solution {
  public:
    int findTheWinner(int n, int k) {
        queue<int> qu;
        for (int i = 1; i <= n; i++) {
            qu.emplace(i);
        }
        while (qu.size() > 1) {
            for (int i = 1; i < k; i++) {
                qu.emplace(qu.front());
                qu.pop();
            }
            qu.pop();
        }
        return qu.front();
    }
};

// @lc code=end
