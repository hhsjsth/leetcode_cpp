/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// https://labuladong.online/algo/essential-technique/sliding-window-framework/#%E4%BA%8C%E3%80%81%E5%AD%97%E7%AC%A6%E4%B8%B2%E6%8E%92%E5%88%97
// @lc code=start
class Solution {
  public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;

        for (char c : s1) {
            need[c]++;
        }

        int l = 0, r = 0;
        int valid = 0;

        while (r < s2.length()) {
            char c = s2[r];
            r++;

            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }

            // 需理解
            // 窗口左侧收缩的条件为窗口长度等于s1长度
            // 但窗口长度等于时也需要进入循环判断是否符合条件, 否则收缩左侧
            while (r - l == s1.length()) {
                if (valid == need.size()) {
                    return true;
                }

                char d = s2[l];
                l++;

                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }

        return false;
    }
};
// @lc code=end
