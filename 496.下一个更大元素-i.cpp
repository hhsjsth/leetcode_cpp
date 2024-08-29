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
            while (!s.empty() && nums2[j] > s.top()) {
                s.pop();
            }

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
