/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// 单调栈从后往前遍历, 还有从前往后遍历的方法, 与本方法大同小异, 可见 496.下一个更大元素-i-1.cpp 和 496.下一个更大元素-i-2.cpp
// @lc code=start
class Solution {
  public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        int n = nums.size();
        vector<int> res(n);
        stack<int> s;
        // 数组长度加倍模拟环形数组
        for (int i = 2 * n - 1; i >= 0; i--) {
            // 索引 i 要求模，其他的和模板一样
            while (!s.empty() && s.top() <= nums[i % n]) {
                s.pop();
            }
            res[i % n] = s.empty() ? -1 : s.top();
            s.push(nums[i % n]);
        }
        return res;
    }
};
// @lc code=end
