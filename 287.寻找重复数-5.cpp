#include "header.h"

/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
// 本来以为重复的数字值重复一次, 所以通过遍历异或运算即可求得结果, 但是实际上, 重复的数字不一定只重复一次
// 因此, 该方法无法解决, 但是这个思路倒是很新奇
class Solution {
  public:
    int findDuplicate(vector<int> &nums) {
        int n = nums.size();

        int xorRes = 0;

        for (int i = 1; i <= n - 1; ++i) {
            xorRes = xorRes ^ i;
        }

        for (int i = 0; i < n; ++i) {
            xorRes = xorRes ^ nums[i];
        }

        return xorRes;
    }
};

// @lc code=end
