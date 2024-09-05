class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        // 存储结果
        vector<vector<int>> res;
        // 先按照每个区间的首个元素排序
        sort(intervals.begin(), intervals.end(),
             [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });

        // 不用双指针的做法。直接存储第一个区间, 更加优雅简洁。
        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            // 合并区间
            if (res.back()[1] >= intervals[i][0])
            {
                res.back()[1] = max(intervals[i][1], res.back()[1]);
            }
            // 直接插入一个新区间作为新的 res.back()
            else
            {
                res.push_back(intervals[i]);
            }
        };
        return res;
    }
}; // @lc code=end
