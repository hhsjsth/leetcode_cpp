#include "header.h"

/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// 方法看官方题解, 一步步从暴力到优化解释的比代码随想录好, 但是少了优化双指针的方法, 不从暴力解开始理解的话很难懂
// https://leetcode.cn/problems/largest-rectangle-in-histogram/solutions/266844/zhu-zhuang-tu-zhong-zui-da-de-ju-xing-by-leetcode-/
// 代码看代码随想录
// https://programmercarl.com/0084.%E6%9F%B1%E7%8A%B6%E5%9B%BE%E4%B8%AD%E6%9C%80%E5%A4%A7%E7%9A%84%E7%9F%A9%E5%BD%A2.html
// 根据代码随想录的说法, 这个比接雨水难, 因为接雨水只要记录两边比自己高的高度值, 而这个为了计算矩形的底, 需要记录两边比自己低的**索引**
// @lc code=start
class Solution {
  public:
    int largestRectangleArea(vector<int> &heights) {
        vector<int> leftLessIndex(heights.size());
        vector<int> rightLessIndex(heights.size());
        int size = heights.size();

        // 记录每个柱子 左边第一个小于该柱子的下标
        // 注意这里初始化，防止下面while死循环
        leftLessIndex[0] = -1;
        for (int i = 1; i < size; i++) {
            int t = i - 1;
            // 这里不是用if，而是不断向左寻找的过程
            while (t >= 0 && heights[t] >= heights[i])
                t = leftLessIndex[t];
            leftLessIndex[i] = t;
        }

        // 记录每个柱子 右边第一个小于该柱子的下标
        // 注意这里初始化，防止下面while死循环
        rightLessIndex[size - 1] = size;
        for (int i = size - 2; i >= 0; i--) {
            int t = i + 1;
            // 这里不是用if，而是不断向右寻找的过程
            while (t < size && heights[t] >= heights[i])
                t = rightLessIndex[t];
            rightLessIndex[i] = t;
        }

        // 求和
        int result = 0;
        for (int i = 0; i < size; i++) {
            int sum = heights[i] * (rightLessIndex[i] - leftLessIndex[i] - 1);
            result = max(sum, result);
        }
        return result;
    }
};
// @lc code=end
