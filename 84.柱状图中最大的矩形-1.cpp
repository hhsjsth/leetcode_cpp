#include "header.h"

/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// 单调栈方法看官方题解, 有一个未优化的单调栈解法, 然后再讲优化后的单调栈解法
// https://leetcode.cn/problems/largest-rectangle-in-histogram/solutions/266844/zhu-zhuang-tu-zhong-zui-da-de-ju-xing-by-leetcode-/
// 代码随想录直接写出的优化后的单调栈解法
// https://programmercarl.com/0084.%E6%9F%B1%E7%8A%B6%E5%9B%BE%E4%B8%AD%E6%9C%80%E5%A4%A7%E7%9A%84%E7%9F%A9%E5%BD%A2.html
// 根据代码随想录的说法, 这个比接雨水难, 因为接雨水只要记录两边比自己高的高度值, 而这个为了计算矩形的底长, 需要记录两边比自己低的**索引**, 而既然是索引, 那么直接使用单调栈方法, 因为单调栈可以记录索引, 对比高度时直接使用索引去数组中相应元素即可对比高度
// 以下是 LeetCode 的未优化的单调栈解法
// @lc code=start
class Solution {
  public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        // 记录索引
        vector<int> left(n), right(n);

        stack<int> mono_stack;
        for (int i = 0; i < n; ++i) {
            // 需理解
            // 是 >= 而不是 >, 因为要在栈中找到比当前元素小的元素, 因此等于的时候, 要将栈顶元素踢掉, 继续寻找
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                mono_stack.pop();
            }
            // 需理解
            // 不存在则索引为 -1, 非常方便用于后续计算矩形的底长
            left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
            mono_stack.push(i);
        }

        mono_stack = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                mono_stack.pop();
            }
            // 需理解
            // 不存在则索引为 n, 非常方便用于后续计算矩形的底长
            right[i] = (mono_stack.empty() ? n : mono_stack.top());
            mono_stack.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
};
// @lc code=end
