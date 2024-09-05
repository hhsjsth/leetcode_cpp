#include "header.h"

/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第 N 位数字
 */

// [400. 第 N 位数字 - 力扣（LeetCode）](https://leetcode.cn/problems/nth-digit/solutions/1128000/di-n-wei-shu-zi-by-leetcode-solution-mdl2/) 方法二：直接计算
// @lc code=start
class Solution {
  public:
    int findNthDigit(int n) {
        int d = 1, count = 9;
        while (n > (long)d * count) {
            n -= d * count;
            d++;
            count *= 10;
        }
        int index = n - 1;
        int start = (int)pow(10, d - 1);
        int num = start + index / d;
        int digitIndex = index % d;
        int digit = (num / (int)(pow(10, d - digitIndex - 1))) % 10;
        return digit;
    }
};

// @lc code=end
