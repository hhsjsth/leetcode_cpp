/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */
// LeetCode 官方有非常多的方法, 而且越来越复杂, 这里写个最简单的哈希法
// @lc code=start
class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        unordered_map<int, int> count;
        for (auto i : nums) {
            count[i]++;
        }
        for (auto i : count) {
            if (i.second > nums.size() / 2) {
                return i.first;
            }
        }
        return 0;
    }
};
// @lc code=end
