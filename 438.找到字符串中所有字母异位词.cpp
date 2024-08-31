/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */
// 滑动窗口 https://labuladong.online/algo/essential-technique/sliding-window-framework/#%E4%B8%89%E3%80%81%E6%89%BE%E6%89%80%E6%9C%89%E5%AD%97%E6%AF%8D%E5%BC%82%E4%BD%8D%E8%AF%8D
// @lc code=start
class Solution {
  public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need, window;

        for (char c : p) {
            need[c]++;
        }

        int l = 0, r = 0;
        int valid = 0;
        vector<int> ans;
        while (r < s.length()) {
            // 移入窗口
            char c = s[r];
            r++;

            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }

            // 收缩窗口
            while (r - l == p.length()) {
                if (valid == need.size()) {
                    ans.push_back(l);
                }

                char d = s[l];
                l++;

                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
