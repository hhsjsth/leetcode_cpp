#include "header.h"

/*
 * @lc app=leetcode.cn id=442 lang=cpp
 *
 * [442] 数组中重复的数据
 */

// @lc code=start
// LeetCode 官方方法 1 需要修改数组内容, 不修改数组内容看 287.寻找重复数
class Solution {
  public:
    vector<int> findDuplicates(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (nums[i] - 1 != i) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};

// @lc code=end
