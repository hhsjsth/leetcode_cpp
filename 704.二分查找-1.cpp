#include "header.h"

/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 * 方法二: 左闭右开写法
 */

// @lc code=start
class Solution {
  public:
    int search(vector<int> &nums, int target) {
        // 左闭右开, 说明左边选得到, 右边选不到
        int l = 0;
        int h = nums.size();
        // 左闭右开和左开右闭不一样了, 所以可以使用移位, 关于为什么左开右闭不能移位, 可以查看文件历史
        int m = l + h >> 1;

        // 左闭右开, 说明只要 l == h - 1 或者 l == h 立刻退出循环
        while (l < h - 1) {
            // 如果中间元素小于 target, 说明 target 在中间元素的右边
            // 此时 m 下标的元素可以忽略了, 但是 m + 1 下标的元素不能忽略
            // 由于是左闭右开, 因此 l 更新为 m + 1, 这样区间 [l, h) 就能将 m + 1 下标的元素包含进去
            if (nums[m] < target) {
                l = m + 1;
            }
            // 如果中间元素大于 target, 说明 target 在中间元素的左边
            // 此时 m 下标的元素可以忽略了, 但是 m - 1 下标的元素不能忽略
            // 由于是左开右闭, 因此 h 更新为 m, 这样区间 [l, h) 才能将 m - 1 下标的元素包含进去
            else if (nums[m] > target) {
                h = m;
            } else if (nums[m] == target) {
                return m;
            }
            m = l + h >> 1;
        }

        /* 存在两种情况 */
        /* 一种是 l == h - 1, 此时说明二分法夹逼得到的元素为 l 即 h - 1, 根据这个元素判断是否二分查找成功 */
        /* 一种是 l == h, 说明跳出循环的前一步的 m = l - 1(跳出循环的前一步是 l = m + 1), 因此 m 是夹逼得到的最后元素并且查找失败, 由于是左闭右开且 l == h, 说明区间已经为 0, 查找失败 nums[h - 1] == nums[m] != target */
        /* 以上两种情况均可以使用 h - 1 判断最终结果 */
        /* 并且使用 h - 1 还能够解决 l == h == nums.size() 的极端情况, 此时 h - 1 为 nums.size() - 1, 不会出现数组越界*/
        return nums[h - 1] == target ? (h - 1) : -1;
    }
};
// @lc code=end
