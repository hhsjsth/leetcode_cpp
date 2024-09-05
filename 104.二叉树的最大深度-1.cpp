#include "header.h"

/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode *root) {
        if (!root)
            return 0;
        queue<TreeNode *> que;
        que.emplace(root);
        TreeNode *cur;
        int ans = 0;
        while (!que.empty()) {
            int n = que.size();
            while (n--) {
                cur = que.front();
                que.pop();
                if (cur->left)
                    que.emplace(cur->left);
                if (cur->right)
                    que.emplace(cur->right);
            }
            ++ans;
        }
        return ans;
    }
};
// @lc code=end
