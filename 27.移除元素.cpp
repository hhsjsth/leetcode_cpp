#include "header.h"

/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
  public:
    int removeElement(vector<int> &nums, int val) {
        int n = nums.size();
        int left = 0;
        // 该方法需要遍历数组最多两遍, 一遍是 right 遍历完数组, 最多的情况是 left 也要遍历完数组.
        // 但是会遇到需要赋值的次数较多, 因为只要遇到一个值为 val, 则需要将右边全部的值全部向左移动.
        for (int right = 0; right < n; right++) {
            if (nums[right] != val) {
                nums[left++] = nums[right];
            }
        }
        return left;
    }
};
// @lc code=end
