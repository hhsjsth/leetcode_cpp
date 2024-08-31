/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// 单调栈从后往前遍历, 还有从前往后遍历的方法, 与本方法大同小异, 可见 496.下一个更大元素-i-1.cpp 和 496.下一个更大元素-i-2.cpp
// @lc code=start
class Solution {
  public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            // 易错, 需理解
            // 496.下一个更大元素-i.cpp 由于是不重复的元素, 所以是大于号即可
            // 然而这题没有提到元素使不重复的, 也就是说元素可能重复, 则需要大于等于号
            // 假如第 5 个和第 6 个一样高, 都比第 4 个高, 那么第 4 个的下一个高的日期就是第 5,
            // 因此遍历到第 5 的时候, 需要将第 6 踢掉, 即 pop 掉
            while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                st.pop();
            }
            ans[i] = st.empty() ? 0 : st.top() - i;
            st.push(i);
        }
        return ans;
    }
};
// @lc code=end
