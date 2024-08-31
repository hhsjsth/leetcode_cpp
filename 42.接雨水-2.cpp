/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
// 单调栈逆向遍历, 参考 42.接雨水-1.cpp
// @lc code=start
class Solution {
  public:
    int trap(vector<int> &height) {
        int ans = 0;
        int n = height.size();
        stack<int> stk;
        for (int i = n - 1; i >= 0; i--) {
            // 易错, 注意是大于号 > 不是大于等于号, 因为等高的话不能够接雨水
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int curBottom = height[stk.top()];
                stk.pop();

                // 易错, 记得检查当前栈是否空, 即之前有没有更高的高度
                if (stk.empty()) {
                    break;
                }

                // 累加横向水量
                ans += (min(height[i], height[stk.top()]) - curBottom) * (stk.top() - i - 1);
            }

            stk.push(i);
        }
        return ans;
    }
};
// @lc code=end
