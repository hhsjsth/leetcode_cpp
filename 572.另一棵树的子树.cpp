#include "header.h"

/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
 */
// 一篇文章带你吃透对称性递归(思路分析+解题模板+案例解读)
// https://leetcode.cn/problems/shu-de-zi-jie-gou-lcof/solutions/791039/yi-pian-wen-zhang-dai-ni-chi-tou-dui-che-uhgs/
// 当前这道题其实比较简单, https://leetcode.cn/problems/shu-de-zi-jie-gou-lcof/solutions/791039/yi-pian-wen-zhang-dai-ni-chi-tou-dui-che-uhgs/ 中的最后一道就比较难, 而且最后的题才是真正对应剑指 offer 26 SubstructureInTree.cpp 的题目
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  public:
    bool isSameTree(TreeNode *a, TreeNode *b) {
        if (!a && !b) {
            return true;
        }
        // 需注意, 别忘了 a && b 的条件
        return a && b && a->val == b->val && isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
    }
    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        if (!root || !subRoot) {
            return false;
        }

        if (isSameTree(root, subRoot)) {
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
// @lc code=end
