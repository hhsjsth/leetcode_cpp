/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// 单调栈方法看官方题解, 有一个未优化的单调栈解法, 然后再讲优化后的单调栈解法
// https://leetcode.cn/problems/largest-rectangle-in-histogram/solutions/266844/zhu-zhuang-tu-zhong-zui-da-de-ju-xing-by-leetcode-/
// 代码随想录直接写出的优化后的单调栈解法
// https://programmercarl.com/0084.%E6%9F%B1%E7%8A%B6%E5%9B%BE%E4%B8%AD%E6%9C%80%E5%A4%A7%E7%9A%84%E7%9F%A9%E5%BD%A2.html
// 以下是 LeetCode 的优化的单调栈解法
// @lc code=start
class Solution {
  public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        vector<int> left(n), right(n, n);

        // 在编程或者算法设计中，“mono”通常指的是“monotonic”（单调的）。单调栈（Monotonic Stack）是一种特殊的栈结构，在这种结构中，元素通常是单调递增或单调递减的。也就是说，当你从栈底到栈顶遍历栈中的元素时，这些元素要么是一直增加（单调递增），要么是一直减少（单调递减）。
        stack<int> mono_stack;
        // 注意
        // 在使用单调栈时, 既可以对当前遍历元素做处理, 也可以对当前栈顶元素做处理
        // 这一点是对单调栈更深刻的理解, 可以结合 496.下一个更大元素-i.cpp 的注释看一看, 有非常详细的解释
        for (int i = 0; i < n; ++i) {
            // 需理解
            // 若某个元素在右边没有比他自己小的元素, 那么这个元素就永远不会在单调栈中被 pop 出来, 也就不会被赋予 right[mono_stack.top()] 值, 因此他的 right 值就保持为前面初始化的时候的 n, 即右边比自己小的值索引为 n, 与左边比自己小的值索引为 -1 互相对应.
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                right[mono_stack.top()] = i;
                mono_stack.pop();
            }
            left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
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
