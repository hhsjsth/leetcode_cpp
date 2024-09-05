#include "header.h"

/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */
// 官方方法 3, 官方写了严格的数学证明, 但是自己理解了更简单的解释
/*
大于等于 4 的元素总可以拆分成 2 * (x - 2) = 2x - 4 >= f
而且 6 = 3 + 3 = 2 + 2 + 2, 但是 3 * 3 > 2 * 2 * 2, 所以如果超过 2 次以上使用 2 时（即大于等于 3 次时）（该数大于等于 6 时），就应该使用 3 来拆
所以拆成尽量多的 3, 以及不超过 2 的 2
*/
// @lc code=start
class Solution {
  public:
    int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }
        int res = 1;
        while (n > 4) {
            res *= 3;
            n -= 3;
        }
        res *= n;
        return res;
    }
};
// @lc code=end
