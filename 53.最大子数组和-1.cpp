#include "header.h"

/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// [53. 最大子数组和 - 力扣（LeetCode）](https://leetcode.cn/problems/maximum-subarray/submissions/318317146/): 动态规划
// @lc code=start
class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
        int pre = 0, maxAns = nums[0];
        for (const auto &x : nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};
// @lc code=end
