#include "header.h"

/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// [260. 只出现一次的数字 III - 力扣（LeetCode）](https://leetcode.cn/problems/single-number-iii/solutions/587516/zhi-chu-xian-yi-ci-de-shu-zi-iii-by-leet-4i8e/) 方法一：哈希表
// @lc code=start
class Solution {
  public:
    vector<int> singleNumber(vector<int> &nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            ++freq[num];
        }
        vector<int> ans;
        for (const auto &[num, occ] : freq) {
            if (occ == 1) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};

// @lc code=end
