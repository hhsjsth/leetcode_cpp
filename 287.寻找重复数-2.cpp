#include "header.h"

/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
// 稍微修改一下 LeetCode 官方方法 1 的 287.寻找重复数-1.cpp, 代码更简洁
// 左闭右开
class Solution {
  public:
    int findDuplicate(vector<int> &nums) {
        int n = nums.size();
        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                cnt += nums[i] <= mid;
            }
            if (cnt <= mid) {
                // 更新区间为 [mid + 1, r)
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};

// @lc code=end
