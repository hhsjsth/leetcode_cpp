#include "header.h"

/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */
// 二分法
// 参考 LeetCode 官方解法, 优化了 153.寻找旋转排序数组中的最小值 剑指 offer 6.cpp
// @lc code=start
class Solution {
  public:
    int findMin(vector<int> &nums) {
        int l = 0, h = nums.size() - 1;
        while (l < h) {
            int m = (h - l) / 2 + l;
            if (nums[m] > nums[h]) {
                // 如果 nums[m] > nums[h], 说明答案一定在 m 右边(不包括 m 自己), 只需要将区间左边界 l 更新为 m + 1 即可.
                l = m + 1;
            } else {
                // 否则, 答案一定在 m 的左边(包括 m 自己), 只需要将右边界 h 更新为 m 即可
                // 并且 m = (h - l) / 2 + l, 存在一个临界情况为 h = l - 1, 此时 m = l, h 更新为 m 也能够避免 h 原地不动卡住导致无限循环的可能.
                h = m;
            }
        }
        // 区间缩为 1 则得到答案.
        return nums[l];
    }
};
// @lc code=end
