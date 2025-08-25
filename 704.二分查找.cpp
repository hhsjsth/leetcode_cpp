#include "header.h"

/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 * 方法一: 左开右闭写法
 */

// @lc code=start
class Solution {
  public:
    int search(vector<int> &nums, int target) {
        // 左开右闭, 说明左边选不到, 右边选得到
        int l = -1;
        int h = nums.size() - 1;
        // 由于左开右闭可能会出现 l == -1 & h == 0 的情况, 此时使用 >> 作为移位是算术移位非逻辑移位, 因此会扩展负号位,
        // 导致结果为 -1, 造成数组越界
        int m = (l + h) / 2;

        // 左开右闭, 说明只要 l == h - 1 或者 l == h 立刻退出循环
        while (l < h - 1) {
            // 如果中间元素小于 target, 说明 target 在中间元素的右边
            // 此时 m 下标的元素可以忽略了, 但是 m + 1 下标的元素不能忽略
            // 由于是左开右闭, 因此 l 更新为 m, 这样区间 (l, h] 才能将 m + 1 下标的元素包含进去
            if (nums[m] < target) {
                l = m;
            }
            // 如果中间元素大于 target, 说明 target 在中间元素的左边
            // 此时 m 下标的元素可以忽略了, 但是 m - 1 下标的元素不能忽略
            // 由于是左开右闭, 因此 h 更新为 m - 1, 这样区间 (l, h] 也能将 m - 1 下标的元素包含进去
            else if (nums[m] > target) {
                h = m - 1;
            } else if (nums[m] == target) {
                return m;
            }
            m = (l + h) / 2;
        }

        // 存在两种情况
        // 一种是 l == h - 1, 此时说明二分法夹逼得到的元素为 h 即 l + 1, 根据这个元素判断是否二分查找成功
        // 一种是 l == h, 说明跳出循环的前一步的 m = h + 1(跳出循环的前一步是 h = m - 1),
        // 因此 m 是夹逼得到的最后元素并且查找失败, 由于是左开右闭且 l == h, 说明区间已经为 0, 查找失败 nums[l + 1] ==
        // nums[m] != target 以上两种情况选可以使用 l + 1 判断最终结果 并且使用 l + 1 还能够解决 l == h == -1
        // 的极端情况, 此时 l + 1 为 0, 不会出现数组越界
        return nums[l + 1] == target ? (l + 1) : -1;
    }
};
// @lc code=end
