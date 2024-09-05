#include "header.h"

/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */
// LeetCode 方法 2
// 参考 105.从前序与中序遍历序列构造二叉树-1.cpp, 用一个栈 stack 来维护「遍历到当前节点之前的所有还没有考虑过左儿子的祖先节点」. 也就是说, 只有在栈中的节点才可能连接一个新的左儿子. 同时, 我们用一个指针 index 指向中序遍历的某个位置, 初始值为 n - 1, 其中 n 为数组的长度.
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (postorder.size() == 0) {
            return nullptr;
        }
        auto root = new TreeNode(postorder[postorder.size() - 1]);
        auto s = stack<TreeNode *>();
        s.push(root);
        int inorderIndex = inorder.size() - 1;
        for (int i = int(postorder.size()) - 2; i >= 0; i--) {
            int postorderVal = postorder[i];
            auto node = s.top();
            if (node->val != inorder[inorderIndex]) {
                node->right = new TreeNode(postorderVal);
                s.push(node->right);
            } else {
                while (!s.empty() && s.top()->val == inorder[inorderIndex]) {
                    node = s.top();
                    s.pop();
                    inorderIndex--;
                }
                node->left = new TreeNode(postorderVal);
                s.push(node->left);
            }
        }
        return root;
    }
};

// @lc code=end
