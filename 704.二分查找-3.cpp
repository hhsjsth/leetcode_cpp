/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 * 方法三: 左开右开写法
 */

// @lc code=start
class Solution {
  public:
    int search(vector<int> &nums, int target) {
        // 左开右开, 参考红蓝区间 https://www.bilibili.com/video/av841423368/
        int l = -1;
        int h = nums.size();
        // 左开右开为红蓝区间, 极限情况为红蓝区间碰撞后查找失败跳出循环, 不可能出现 h - l 为负数的情况, 因此移位不会出现负数, 不会导致数组越界
        // 下面这种写法可以防止越界
        int m = l + (h - l >> 1);

        while (l < h - 1) {
            if (nums[m] < target) {
                l = m;
            } else if (nums[m] > target) {
                h = m;
            } else if (nums[m] == target) {
                return m;
            }
            m = l + (h - l >> 1);
        }

        return -1;
    }
};
// @lc code=end
