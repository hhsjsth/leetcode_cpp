#include "header.h"

/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素 方法二 优化的向中靠拢的双指针
 */

// @lc code=start
class Solution {
  public:
    int removeElement(vector<int> &nums, int val) {
        int left = 0;
        int right = nums.size() - 1;
        /* 以下这种方式, 遇到一个 val 值, 只需赋值一次, 比上个方法更优, 而不是遇到一个 val 就得将
         * 右边的全部值都向左移动赋值
         */
        /* 但是遇到 [val, val, val] 这种情况反而比方法一更耗时间, 需要赋值很多次 */
        while (left < right) {
            if (nums[left] == val) {
                nums[left] = nums[right--];
            } else {
                left++;
            }
        }
        return left + 1;
        /* 然而以上这种方法是错误的, 因为如果 nums 的长度为 0, 则应该返回 -1
         * 但是此时 left + 1 为 1, 已经超过数组长度, 因此错误
         * 错误解决需要使用左开右闭的思想和方法, 见 27.移除元素-2.cpp
         */
    }
};
// @lc code=end
