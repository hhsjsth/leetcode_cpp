#include "header.h"

/*
 * @lc app=leetcode.cn id=442 lang=cpp
 *
 * [442] 数组中重复的数据
 */

// @lc code=start
// 剑指 offer 2 提供的方法, 不需要修改数组内容, 见 https://github.com/zhedahht/CodingInterviewChinese2 FindDuplicationNoEdit.cpp
class Solution {
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

  public:
    vector<int> findDuplicates(vector<int> &nums) {
        int n = nums.size();
        // 所有的整数都在范围 [1,n] 内
        int l = 1, h = n;
        vector<int> ans;
        while (l < h) {
            int m = (h - l) >> 1 + l;

            // 如果数组元素中在 [l, m] 范围内的元素大于 l 到 m 的范围
            // 比如数组元素中包括 1, 3, 2, 1, 那么在 [1, 3] 中的元素有 4 个, 大于 3, 这个范围内存在重复的数字, 因此继续缩小使用二分法缩小查找范围
            if (countInRange(l, m, nums) >= m - l + 1) {
            }

            // 写到这里发现题目要的是所有出现两次的整数, 因此使用这个二分法无法解决

            // 看 LeetCode 官方提供的前两个方法就行了, 或者看 287.寻找重复数 剑指 offer 1.cpp
        }
        return ans;
    }
};

// @lc code=end
