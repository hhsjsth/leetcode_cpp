/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 * 方法二: 左闭右开写法二
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

        // 左闭右开, 说明只要 l == h 立刻退出循环
        while (l < h) {
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

        // 夹逼到最后只剩下左闭右开的区间已经没有元素
        return -1;
    }
};
// @lc code=end
