/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 * 方法四: 左闭右闭写法
 */

// @lc code=start
class Solution {
  public:
    int search(vector<int> &nums, int target) {
        int l = 0;
        int h = nums.size() - 1;
        // 左开右开为红蓝区间, 极限情况为红蓝区间碰撞后查找失败跳出循环, 不可能出现 h - l 为负数的情况, 因此移位不会出现负数, 不会导致数组越界
        // 下面这种写法可以防止整数越界
        int m = l + (h - l >> 1);

        while (l <= h) {
            if (nums[m] < target) {
                l = m + 1;
            } else if (nums[m] > target) {
                h = m - 1;
            } else if (nums[m] == target) {
                return m;
            }
            m = l + (h - l >> 1);
        }

        return -1;
    }
};
// @lc code=end
