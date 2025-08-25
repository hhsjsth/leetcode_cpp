#include "header.h"

/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

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
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode *> stk;
        vector<int> res;
        if (root == nullptr)
            return res;
        TreeNode *cur = root, *pre = nullptr;
        while (!stk.empty() || cur != nullptr) {
            while (cur) {
                stk.emplace(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            if (!cur->right || cur->right == pre) {
                // 最开始的情况是 cur->right 已经为空了, 这样就可以把 pre 色设置为 cur, 之后就可以利用 cur->right == pre 判断了,
                // 并且要将 cur 设置为 nullptr, 不然的话就又会重新遍历 cur->left 的节点, 设置为 nullptr 之后就能够直接读取栈顶
                res.emplace_back(cur->val);
                pre = cur;
                cur = nullptr;
            } else {
                stk.emplace(cur);
                cur = cur->right;
            }
        }
        return res;
    }
};
// @lc code=end
