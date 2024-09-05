#include "header.h"

/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
// 参考剑指 offer 38 StringPermutation.cpp
// @lc code=start
class Solution {
  private:
    vector<vector<int>> ans;
    void backtrace(vector<int> &nums, int idx) {
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i = idx; i < nums.size(); i++) {
            swap(nums[i], nums[idx]);
            backtrace(nums, idx + 1);
            swap(nums[i], nums[idx]);
        }
    }

  public:
    vector<vector<int>>
    permute(vector<int> &nums) {
        vector<int> used(nums.size(), false);
        backtrace(nums, 0);
        return ans;
    }
};
// @lc code=end
