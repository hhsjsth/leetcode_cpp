#include "header.h"

/*
 * @lc app=leetcode.cn id=65 lang=cpp
 *
 * [65] 有效数字
 */
// 评论区答案
// @lc code=start
class Solution {
  public:
    bool isNumber(string s) {
        if (s.empty()) {
            return false;
        }
        bool seenNum = false;
        bool seenE = false;
        bool seenDot = false;

        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
            case '.':
                if (seenE || seenDot) {
                    return false;
                }
                seenDot = true;
                break;
            case 'e':
            case 'E':
                if (seenE || !seenNum) {
                    return false;
                }
                seenE = true;
                seenNum = false;
                break;
            case '+':
            case '-':
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
                seenNum = false;
                break;
            default:
                if (!isdigit(s[i])) {
                    return false;
                }
                seenNum = true;
            }
        }
        return seenNum;
    }
};
// @lc code=end
