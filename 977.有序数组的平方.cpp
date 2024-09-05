/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
  public:
    vector<int> sortedSquares(vector<int> &nums) {
        // 还是左闭右开
        int l = 0, r = nums.size();
        vector<int> res(r);
        int pos = r - 1;
        while (l < r) {
            if (nums[l] * nums[l] > nums[r - 1] * nums[r - 1]) {
                res[pos--] = nums[l] * nums[l];
                l++;
            } else {
                res[pos--] = nums[r - 1] * nums[r - 1];
                r--;
            }
        }
        return res;
    }
};
// @lc code=end
