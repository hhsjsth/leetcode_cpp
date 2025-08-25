#include "header.h"

/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
// https://programmercarl.com/0042.%E6%8E%A5%E9%9B%A8%E6%B0%B4.html#%E5%8D%95%E8%B0%83%E6%A0%88%E8%A7%A3%E6%B3%95
// 单调栈正向遍历
// @lc code=start
class Solution {
  public:
    int trap(vector<int> &height) {
        int ans = 0;
        int n = height.size();
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            // 易错, 注意是大于号 > 不是大于等于号, 因为等高的话不能够接雨水
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int curBottom = stk.top();
                stk.pop();

                // 易错, 记得检查当前栈是否空, 即之前有没有更高的高度
                if (stk.empty()) {
                    break;
                }
                int curWidth = i - stk.top() - 1;
                int curHeight = min(height[i], height[stk.top()]) - height[curBottom];
                ans += (curWidth * curHeight);
            }
            stk.push(i);
        }
        return ans;
    }
};
// @lc code=end
