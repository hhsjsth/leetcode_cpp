#include "header.h"

/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */
// LeetCode 官方有非常多的方法, 而且越来越复杂, 这里写个第二个最简单的哈希法
// @lc code=start
class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        unordered_map<int, int> count;
        for (auto i : nums) {
            count[i]++;
            if (count[i] > nums.size() / 2) {
                return i;
            }
        }
        return 0;
    }
};
// @lc code=end
