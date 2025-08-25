#include "header.h"

/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
// https://programmercarl.com/0042.%E6%8E%A5%E9%9B%A8%E6%B0%B4.html#%E5%8F%8C%E6%8C%87%E9%92%88%E4%BC%98%E5%8C%96
// 优化双指针
// @lc code=start
class Solution {
  public:
    int trap(vector<int> &height) {
        int n = height.size();
        // 记录某个元素包括自己的左边的最高值
        vector<int> leftMax(n);
        // 记录某个元素包括自己的右边的最高值
        vector<int> rightMax(n);
        leftMax[0] = height[0];
        for (int i = 1; i < n; ++i) {
            leftMax[i] = max(height[i], leftMax[i - 1]);
        }
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rightMax[i] = max(height[i], rightMax[i + 1]);
        }

        // 需理解
        // leftMax 和 rightMax 都包括了自己, 因此当自己是某一侧的最高值时
        // 即 min(leftMax[i], rightMax[i]) = height[i], 则无法接到雨水
        // 因此下面直接 ans += min(leftMax[i], rightMax[i]) - height[i]; 不需要添加 if 判断, 很优雅
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        return ans;
    }
};
// @lc code=end
