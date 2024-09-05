#include "header.h"

/*
 * @lc app=leetcode.cn id=442 lang=cpp
 *
 * [442] 数组中重复的数据
 */

// @lc code=start
// LeetCode 官方方法 2 需要修改数组内容, 不修改数组内容看 287.寻找重复数
class Solution {
  public:
    vector<int> findDuplicates(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            int x = abs(nums[i]);
            if (nums[x - 1] > 0) {
                nums[x - 1] = !nums[x - 1];
            } else {
                ans.push_back(x);
            }
        }
        return ans;
    }
};

// @lc code=end
