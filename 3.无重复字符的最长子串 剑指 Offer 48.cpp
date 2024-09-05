#include "header.h"

/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        // 哈希集合，记录每个字符是否出现过
        // 根据通义千问, occ 这个名字可能是从 "occurrence"（出现）这个词简化而来
        unordered_set<char> occ;
        int n = s.size();
        // 右指针，初始值为 0，左闭右开，还没有开始移动
        int rk = 0, ans = 0;
        // 枚举左指针的位置
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                // 左指针向右移动一格，移除一个字符
                occ.erase(s[i - 1]);
            }
            while (rk < n && !occ.count(s[rk])) {
                // 不断地移动右指针
                occ.insert(s[rk]);
                ++rk;
            }
            // 第 i 到 rk 个字符是一个极长的无重复字符子串
            ans = max(ans, rk - i);
        }
        return ans;
    }
};
// @lc code=end
