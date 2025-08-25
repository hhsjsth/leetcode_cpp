#include "header.h"

/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// 滑动窗口 https://labuladong.online/algo/essential-technique/sliding-window-framework/
// @lc code=start
class Solution {
  public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        int sLength = s.length();
        int tLength = t.length();

        for (char c : t) {
            need[c]++;
        }

        int l = 0, r = 0;

        // 记录window中的字符满足need条件的字符个数
        int valid = 0;

        // 记录最小覆盖子串的起始索引及长度
        int start = 0, len = INT_MAX;

        // 左闭右开
        while (r < sLength) {
            // 移入窗口的字符
            char c = s[r];
            // 扩大窗口
            r++;

            // 只维护和 need 有关的字符, 其他不记录, 因此使用 if (need.count(c))
            if (need.count(c)) {
                window[c]++;

                // 需理解
                // 当窗口内的该字符数量刚好等于 need 的数量时, valid 才会加一
                // 如果超过了, 则不计数, 因此判断条件是 window[c] == need[c]
                if (window[c] == need[c]) {
                    valid++;
                }
            }

            // 如果此时的s子串符合条件, 则左侧窗口需要收缩
            // 然而应该是 valid == need.size() 而不是 valid == tLength
            while (valid == need.size()) {
                if (len > r - l) {
                    start = l;
                    len = r - l;
                }

                // 记录移出窗口的字符
                c = s[l];
                // 缩小窗口
                l++;

                if (need.count(c)) {
                    // 易错, 需要先 valid--, 再 window[c]--
                    if (window[c] == need[c]) {
                        valid--;
                    }
                    window[c]--;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
// @lc code=end
