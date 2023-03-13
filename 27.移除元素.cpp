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
        /* 采用左闭右开的思想方法, 当 left 遇到 right 的时候, 由于 right 是开的
         * 此时 left == right, nums[left] 刚好由于是处于开的临界点因此不包含在最终结果的区间中.
         * 但是 left 这个值刚好就能够成为元素个数
         */
        int right = nums.size();
        /* 以下这种方式, 遇到一个 val 值, 只需赋值一次, 比上个方法更优, 而不是遇到一个 val 就得将
         * 右边的全部值都向左移动赋值
         */
        /* 但是遇到 [val, val, val] 这种情况反而比方法一更耗时间, 需要赋值很多次 */
        while (left < right) {
            if (nums[left] == val) {
                nums[left] = nums[right - 1];
                right--;
            } else {
                left++;
            }
        }
        /* 根据以上说到的左闭右开, 返回 left 即可 */
        return left;
    }
};
// @lc code=end
