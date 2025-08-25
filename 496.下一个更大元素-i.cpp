#include "header.h"

/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
// 使用单调栈, 见 https://labuladong.online/algo/data-structure/monotonic-stack/
class Solution {
  public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans(n1);
        stack<int> s;
        unordered_map<int, int> u;

        for (int j = n2 - 1; j >= 0; j--) {

            // 需理解
            // 由于题目说到 "nums1 和 nums2 中所有整数 互不相同"
            // 因此使用 >= 或者 > 都行
            // 具体见 739.每日温度.cpp 解释
            while (!s.empty() && nums2[j] >= s.top()) {
                s.pop();
            }

            // 需理解和注意
            // 这个是从后往前遍历(j = n2 - 1), 那么这个地方处理的是就是当前遍历的元素 nums[j];
            // 而如果是从后往前遍历, 则需要处理的反而是栈顶元素或者说是, 即将要 pop 出来的元素, 见 496.下一个更大元素-i-1.cpp 和 496.下一个更大元素-i-2.cpp
            // 这个对比带来了灵感, 对单调栈的理解就更深刻, 也就是不管如何, 单调栈对当前遍历的元素以及即将 pop 出来的元素都可以处理, 甚至可以同时处理. 理解了这点, 就可以优化 84.柱状图中最大的矩形-2.cpp 的单调栈优化方法
            // 甚至可以再具体一点
            // 从左到右遍历, 栈底到栈顶规定元素是从大到小, 那么遍历到的元素可以根据栈顶元素一次次 pop 找到左边第 1 个比自己大的元素或者到栈空了则确定没有比自己大的元素, 而一次次 pop 出来的元素的右边的第 1 个比自己大的元素则是我们当前遍历到的元素. 由于每个元素都会被遍历, 那么每个元素都能够找到左边第 1 个比自己大的元素, 由于每个元素在遍历的过程中又都会被栈, 那么也都能够找到右边比自己大的元素.
            // 其他的情况比如从右到左遍历, 或者栈底到栈顶是从小到大, 都可依次类推. 不过只要规定了栈是从大到小, 那么就元素只能找到两边第一个比自己大的元素, 不能即找到第一个比自己大的元素, 也找到比自己小的元素. 反之亦然.
            if (s.empty()) {
                u[nums2[j]] = -1;
            } else {
                u[nums2[j]] = s.top();
            }
            s.push(nums2[j]);
        }

        for (int i = 0; i < n1; i++) {
            ans[i] = u[nums1[i]];
        }

        return ans;
    }
};
// @lc code=end
