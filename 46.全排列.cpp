#include "header.h"

/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
  private:
    vector<int> path;
    vector<vector<int>> ans;
    void backtrace(const vector<int> &nums, vector<int> &used) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                path.push_back(nums[i]);
                used[i] = true;
                backtrace(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }

  public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<int> used(nums.size(), false);
        backtrace(nums, used);
        return ans;
    }
};
// @lc code=end
