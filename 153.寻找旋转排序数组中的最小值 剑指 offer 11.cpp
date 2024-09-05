#include "header.h"

/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */
// 二分法
// 参考 LeetCode 官方方法, 自己写出来
// @lc code=start
class Solution {
  public:
    int findMin(vector<int> &nums) {
        int l = 0, h = nums.size() - 1;
        while (l < h) {
            // 因为在这个循环内 h - l 可能等于 1, 所以 (h - l) / 2 可能等于 0, 会出现 (h - l) / 2 = 0 导致的 m 一直卡在 l 的死循环
            int m = (h - l + 1) / 2 + l;
            if (nums[m] > nums[h]) {
                l = m + 1;
            } else if (nums[m] < nums[m - 1]) {
                // 找到元素, 则直接返回
                return nums[m];
            } else {
                h = m - 1;
            }
        }
        // 区间缩为 1 则得到答案.
        return nums[h];
    }
};
// @lc code=end
