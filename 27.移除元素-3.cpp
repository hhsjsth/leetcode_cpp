#include "header.h"

/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素 方法三 继续优化的向中靠拢的双指针
 */

// @lc code=start
class Solution {
  public:
    int removeElement(vector<int> &nums, int val) {
        int left = 0;
        int right = nums.size();
        /*
         * 为了减少赋值次数, 将赋值的 if 分支放到最后, 将移动指针的 if 分支放到前面
         * 并且前两个分支可以交换
         */
        while (left < right) {
            if (nums[right - 1] == val) {
                right--;
            } else if (nums[left] != val) {
                left++;
            } else {
                nums[left] = nums[right - 1];
                right--;
                left++;
            }
        }
        /* 根据以上说到的左闭右开, 返回 left 即可 */
        return left;
    }
};
// @lc code=end
