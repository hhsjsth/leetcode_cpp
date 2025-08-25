#include "header.h"

/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
// 使用单调栈, 这个是从前往后遍历数组, 之前的方法是从后往前遍历数组 496.下一个更大元素-i-1.cpp 的小小的优化
class Solution {
  public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans(n1, -1);
        stack<int> st;
        unordered_map<int, int> u;

        for (size_t i = 0; i < n2; i++) {
            while (!st.empty() && nums2[i] > st.top()) {
                u[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }

        for (size_t i = 0; i < n1; i++) {
            if (u.find(nums1[i]) != u.end()) {
                ans[i] = u[nums1[i]];
            }
        }

        return ans;
    }
};

// @lc code=end
