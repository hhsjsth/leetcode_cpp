#include "header.h"

/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */
/*
不看官方题解, 看 https://leetcode.cn/problems/regular-expression-matching/solutions/2361807/10-zheng-ze-biao-da-shi-pi-pei-dong-tai-m5z1i/

状态定义: 设动态规划矩阵 dp ， dp[i][j] 代表字符串 s 的前 i 个字符和 p 的前 j 个字符能否匹配。

转移方程: 需要注意，由于 dp[0][0] 代表的是空字符的状态, **因此 dp[i][j] 对应的添加字符是 s[i - 1] 和 p[j - 1]**
- 当 p[j - 1] = '*' 时, dp[i][j] 在当以下任一情况为 true 时等于 true
  - dp[i][j - 2]: 即将字符组合 `p[j - 2]*` 这两个合在一起的字符看作出现 0 次时 (比如说把 ba* 看错 b, 其中的 a* 看为 0 次)，能否匹配.
  - dp[i - 1][j] 且 s[i - 1] = p[j - 2]: dp[i - 1][j] 表示 s[i - 2] 和 p[j - 1] 匹配, 而此时 p[j - 1] = '*', 现在为了求 dp[i][j] 需要看 s[i - 1] 和 p[j - 1], 而判断 s[i - 1] = p[j - 2] 即让字符 p[j - 2] 因为 '*'(p[j - 1]) 多出现 1 次时, 看能否匹配
  - dp[i - 1][j] 且 p[j - 2] = '.': 此时因为 p[j - 1] = '*', 因此可以让 p[j - 2] = '.' 再出现一次, 这样就能够和 s[i - 1] 匹配
- 当 p[j - 1] != '*' 时, dp[i][j] 在当以下任一情况为 true 时等于 true:
  - dp[i - 1][j - 1] 且 s[i - 1] = p[j - 1]
  - dp[i - 1][j - 1] 且 p[j - 1] = '.'

初始化: 需要先初始化 dp 矩阵首行, 以避免状态转移时索引越界
- dp[0][0] = true: 代表两个空字符串能够匹配
- dp[0][j] = dp[0][j - 2] 且 p[j - 1] = '*': 首行 s 为空字符串，因此当 p 的偶数位为 * 时才能够匹配 (即让 p 的奇数位出现 0 次，保持 p 是空字符串)。因此，循环遍历字符串 p, 步长为 2 (即只看偶数位)。

*/

// @lc code=start
// 代码参考的是官方, 不完全一样
class Solution {
  public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();

        auto matchChar = [&](int i, int j) {
            if (i == 0) {
                return false;
            }
            return s[i - 1] == p[j - 1] || p[j - 1] == '.';
        };

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, false));
        // 初始化
        dp[0][0] = true;

        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    // 采用 |= 的或运算, 否则 if else 以及 if else 里面里面也有 if else 的嵌套写法容易遗漏, 虽然下面这个写法应该也没问题, 但是遇到更复杂的话就容易出错或者遗漏
                    // if (s[i - 1] == p[j - 2] || p[j - 2] == '.') {
                    //     dp[i][j] = dp[i][j - 1];
                    // } else {
                    //     dp[i][j] = dp[i][j - 2];
                    // }
                    dp[i][j] |= dp[i][j - 2];
                    // if (s[i - 1] == p[j - 2] || p[j - 2] == '.') {
                    if (matchChar(i, j - 1)) {
                        dp[i][j] |= dp[i - 1][j];
                    }
                } else {
                    // 没有判断 i > 0, 太坑了
                    // if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                    //     dp[i][j] |= dp[i - 1][j - 1];
                    // }
                    // 改成 C++ lambda 表达式更优雅, 见 https://en.cppreference.com/w/cpp/language/lambda
                    if (matchChar(i, j)) {
                        dp[i][j] |= dp[i - 1][j - 1];
                    }
                }
            }
        }

        return dp[m][n];
    }
};
// @lc code=end
