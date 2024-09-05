#include "header.h"

/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
// 看了 LeetCode 官方方法 1 后, 和 287.寻找重复数 剑指 offer 1.cpp 是类似的.
// 好好看 LeetCode 官方方法 1 即可
class Solution {
  public:
    int findDuplicate(vector<int> &nums) {
        int n = nums.size();
        // 根据题意, 若数组的大小为 n, 则数字范围在 [1, n - 1] 以内
        int l = 1, r = n - 1, ans = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                cnt += nums[i] <= mid;
            }
            if (cnt <= mid) {
                l = mid + 1;
            } else {
                r = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
};

// @lc code=end
