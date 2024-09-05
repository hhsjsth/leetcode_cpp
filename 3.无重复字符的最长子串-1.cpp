/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// https://labuladong.online/algo/essential-technique/sliding-window-framework/#%E5%9B%9B%E3%80%81%E6%9C%80%E9%95%BF%E6%97%A0%E9%87%8D%E5%A4%8D%E5%AD%90%E4%B8%B2
// @lc code=start
class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int l = 0, r = 0;
        int ans = 0;

        while (r < s.length()) {
            char c = s[r];
            r++;

            window[c]++;

            // 存在重复字符时应该收缩窗口
            while (window[c] > 1) {
                char d = s[l];
                l++;
                window[d]--;
            }

            ans = max(ans, r - l);
        }
        return ans;
    }
};
// @lc code=end
