#include "header.h"

/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// [137. 只出现一次的数字 II - 力扣（LeetCode）](https://leetcode.cn/problems/single-number-ii/solutions/746993/zhi-chu-xian-yi-ci-de-shu-zi-ii-by-leetc-23t6/) 方法一：哈希表
// @lc code=start
class Solution {
  public:
    int singleNumber(vector<int> &nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            ++freq[num];
        }
        int ans = 0;
        for (auto [num, occ] : freq) {
            if (occ == 1) {
                ans = num;
                break;
            }
        }
        return ans;
    }
};

// @lc code=end
