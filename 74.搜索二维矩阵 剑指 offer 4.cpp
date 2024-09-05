#include "header.h"

/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */
// 剑指 offer 1
// @lc code=start
// 参考 LeetCode 官方题解 1, 两次二分查找, 左闭右开
class Solution {
  public:
    // https://lxblog.com/qianwen/share?shareId=025cdcb5-12b2-4093-901e-601fd523024d
    // 这段代码中使用了C++的auto关键字和lambda表达式来定义一个比较函数用于upper_bound算法。upper_bound是C++标准库中的一个算法，它返回一个迭代器指向第一个大于给定值的元素的位置，或者如果所有元素都不大于给定值，则返回end迭代器。
    // 在这个特定的例子中，matrix是一个包含多个整数向量的容器（可能是vector<vector<int>>），target是一个整数值，auto row将存储upper_bound函数的结果，即满足条件的迭代器。
    // 这里的[](const int b, const vector<int> &a) { return b < a[0]; }是一个lambda表达式，它定义了一个匿名函数，该函数接受两个参数：一个整数b和一个整数向量的引用a。这个lambda表达式的作用是比较整数b和向量a的第一个元素a[0]。如果b小于a[0]，则返回true；否则返回false。
    // upper_bound在这里的用法是为了找到matrix中第一个其第一列的值大于target的行。具体来说，upper_bound会遍历从matrix.begin()到matrix.end()的范围内的每一行，并且使用提供的lambda表达式作为比较函数来判断target和当前行的第一列值之间的关系。一旦找到第一个比target大的行，upper_bound就会停止搜索并返回对应的迭代器。
    bool searchMatrix(vector<vector<int>> matrix, int target) {
        auto row = upper_bound(matrix.begin(), matrix.end(), target, [](const int b, const vector<int> &a) {
            return b < a[0];
        });
        // https://lxblog.com/qianwen/share?shareId=5b2ee09a-6155-4445-8d6a-cd3bc2ed7292
        // upper_bound函数在这里用于寻找目标值target在矩阵中的上界位置。也就是说，它返回的是矩阵中第一个其首元素大于target的行的迭代器。如果没有这样的行存在，那么upper_bound会返回matrix.end()。
        if (row == matrix.begin()) {
            return false;
        }
        --row;
        return binary_search(row->begin(), row->end(), target);
    }
};

// @lc code=end
