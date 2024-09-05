#include "header.h"

/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// [268. 丢失的数字 - 力扣（LeetCode）](https://leetcode.cn/problems/missing-number/solutions/1085105/diu-shi-de-shu-zi-by-leetcode-solution-naow/) 方法一：排序
// @lc code=start
class Solution {
  public:
    int missingNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                return i;
            }
        }
        return n;
    }
};

// @lc code=end
