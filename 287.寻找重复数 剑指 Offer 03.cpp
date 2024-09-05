#include "header.h"

/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
// 剑指 offer 2 提供的方法, 自己编码, 不需要修改数组内容, 见 https://github.com/zhedahht/CodingInterviewChinese2 FindDuplicationNoEdit.cpp
// 看了 LeetCode 官方方法 1 后, 发现是类似的.
class Solution {
  public:
    // 计算数组中大小在 [l, h] 范围内的元素的数量
    int countInRange(int l, int h, vector<int> &nums) {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] >= l & nums[i] <= h) {
                ++sum;
            }
        }

        return sum;
    }

    int findDuplicate(vector<int> &nums) {
        int n = nums.size();
        // 根据题意, 若数组的大小为 n, 则数字范围在 [1, n - 1] 以内
        int l = 1, h = n - 1;
        vector<int> ans;
        while (l < h) {
            int m = ((h - l) >> 1) + l;

            // 如果数组元素中在 [l, m] 范围内的元素数量大于 l 到 m 的范围长度
            // 比如数组元素中包括 1, 3, 2, 1, 那么在 [1, 3] 中的元素有 4 个, 大于 3, 这个范围内存在重复的数字 1, 因此继续缩小使用二分法缩小查找范围
            if (countInRange(l, m, nums) > m - l + 1) {
                // 继续在这个范围内查找, 因此下一个查找区间为 [l, m], 因此赋值 h = m,
                h = m;
            } else {
                // 否则在上半部分的范围内查找, 因此下一个查找区间为 [m + 1, h], 因此赋值 l = m + 1
                l = m + 1;
            }
        }

        return l;
    };
};
// @lc code=end
