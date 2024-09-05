#include "header.h"

/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// 卡丹算法, 非常简单且简洁, 本质就是贪心算法, 还是挺妙的.
// @lc code=start
class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
        int sum = 0;
        int result = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum > result) {
                result = sum;
            }
            if (sum < 0) {
                sum = 0;
            }
        }
        return result;
    }
};
// @lc code=end
