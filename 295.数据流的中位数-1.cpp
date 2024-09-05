#include "header.h"

/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// [295. 数据流的中位数 - 力扣（LeetCode）](https://leetcode.cn/problems/find-median-from-data-stream/solutions/961062/shu-ju-liu-de-zhong-wei-shu-by-leetcode-ktkst/): 方法二：有序集合 + 双指针
// @lc code=start
class MedianFinder {
    multiset<int> nums;
    multiset<int>::iterator left, right;

  public:
    MedianFinder() : left(nums.end()), right(nums.end()) {}

    void addNum(int num) {
        const size_t n = nums.size();

        nums.insert(num);
        if (!n) {
            left = right = nums.begin();
        } else if (n & 1) {
            if (num < *left) {
                left--;
            } else {
                right++;
            }
        } else {
            if (num > *left && num < *right) {
                left++;
                right--;
            } else if (num >= *right) {
                left++;
            } else {
                // 这种情况即为 num <= *left
                right--;
                // 因为 multiset<int> 的默认 Compare 类型为 class Compare = std::less<Key>, 但插入元素和遍历到的元素对比相同时会返回 false (严格弱序要求“相等”必须返回), 因此插入的元素会继续向右移动, 遇到第一个比插入元素大的位置才会插入到左侧
                // 因此如果 num == *left, 则 num 会插入到 multiset<int> 中原来 *left 指向的元素的右侧, 因此还需要额外移动 left 指针
                left = right;
            }
        }
    }

    double findMedian() {
        return (*left + *right) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
