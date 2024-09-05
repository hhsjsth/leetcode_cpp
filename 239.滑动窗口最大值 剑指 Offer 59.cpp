#include "header.h"

/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
// https://programmercarl.com/0239.%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E6%9C%80%E5%A4%A7%E5%80%BC.html
// @lc code=start
class Solution {
  private:
    class MyQueue {
      public:
        // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
        // 同时 pop 之前判断队列当前是否为空。
        void pop(int value) {
            if (!que.empty() && value == que.front()) {
                que.pop_front();
            }
        }

        // 如果 push 的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到 push 的数值小于等于队列入口元素的数值为止。
        // 这样就保持了队列里的数值是单调从大到小的了。
        void
        push(int value) {
            while (!que.empty() && value > que.back()) {
                que.pop_back();
            }
            que.push_back(value);
        }

        // 查询当前队列里的最大值 直接返回队列前端也就是 front 就可以了。
        int front() {
            return que.front();
        }

      private:
        // 使用 deque 双端队列来实现单调队列
        deque<int> que;
    };

  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> result;
        MyQueue que;

        // 先将前 k 的元素放进队列
        for (int i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        // result 记录前 k 的元素的最大值
        result.push_back(que.front());

        for (int i = k; i < nums.size(); i++) {
            // 以下这两句可以交换
            // 滑动窗口移除最前面元素
            que.pop(nums[i - k]);
            // 滑动窗口前加入最后面的元素
            que.push(nums[i]);
            // 记录对应的最大值
            result.push_back(que.front());
        }

        return result;
    }
};
// @lc code=end
