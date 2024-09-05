#include "header.h"

/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */
// 参考 LeetCode 题解 2 和 https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solutions/15244/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--22/
// 采用迭代
// @lc code=start
/*
        3
       / \
      9  20
     /  /  \
    8  15   7
   / \
  5  10
 /
4

preorder = [3, 9, 8, 5, 4, 10, 20, 15, 7]
inorder = [4, 5, 8, 10, 9, 3, 15, 20, 7]

先初始化一个指针指向 inorder 的 4
然后遍历 preorder, 首先将 3 作为根节点, 到了 9 的时候, 不知道这个 9 是左子树还是右子树, 所以需要再加上中序遍历的数组来确定. 根据先序遍历 preorder = [4, 5, 8, 10, 9, 3, 15, 20, 7], 则说明根节点 4 的左子树是空的, 则 4 应该在中序遍历的最开头, 这与中序遍历 inorder = [4, 5, 8, 10, 9, 3, 15, 20, 7] 矛盾. 因此 9 为 3 的左节点.

于是我们一次建树如下
        3
       /
      9
     /
    8
   /
  5
 /
4

此时, 前序遍历到的节点和当前中序指向的节点都为 4, 说明前序的下一个节点 10 只能是某个节点的右节点了, 否则假设 10 仍然是 4 的左节点, 则 4 也不可能是中序遍历的首个元素.

那么问题来了, 是 [3, 9, 8, 5, 4] 中的哪个节点?

假设是 3 的右节点, 则中序遍历为 [4, 5, 8, 9, 3, 10],
假设是 9 的右节点, 则中序遍历为 [4, 5, 8, 9, 10]
其他情况以此类推...

从上帝视角看明显 10 是 8 的右节点, 中序遍历为 [4, 5, 8, 10], 前面的 [4, 5, 8] 刚好和前序遍历的 [3, 9, 8, 5, 4] 的后半部分 [8, 5, 4] 倒过来, 因此我们可以使用栈来存储已经建立好左子树的节点, 然后中序遍历 [4, 5, 8] 向后移动指针遍历, 栈存储了 [3, 9, 8, 5, 4] 也不断 pop 出来, 也是 [4, 5, 8], 此时各自遍历到的下一个元素 9 和 10 不一样. 再回想一下, 我们要找的是谁的父节点: 是 10 的父节点, 因此此时我们可以拿 8 作为 10 的父节点建树

于是我们遇到以上这个时间节点时, 遍历到的节点是 10
此时栈为 [3, 9, 8, 5, 4], 剩下的未建立的树的前序遍历为 [10, 20, 15, 7], 也可以发现栈 [3, 9, 8, 5, 4] 的元素是暂时没有建立右节点的节点或者确定是否拥有右节点的节点, 这也是我们前面假设哪一个节点为 10 的父节点的范围, 这也是我们对栈的定义: 存储暂时没有建立右节点的节点或者确定是否拥有右节点的元素
而已经遍历的中序遍历为 [], 剩下为遍历的中序遍历为 [4, 5, 8, 10, 9, 3, 15, 20, 7], 栈顶元素和剩余中序遍历的首个元素一致, 这也是我们开始寻找 10 是那个元素的右节点的时间点.
可以发现 4 这个值有 push 到栈中

接下来根据上面说的栈 pop 的同时中序遍历同时移动指针

        3
       /
      9
     /
    8
   / \
  5  10
 /
4

此时栈为 [3, 9, 10], 是剔除掉 [4, 5, 8] 之后的前序遍历顺序, 剩下的未建立的树的前序遍历为[20, 15, 7]
而已经遍历的中序遍历为 [4, 5, 8] (也是栈增进 pop 出来的内容, pop 出来就说明这些节点已经找到右节点或者确定没有右节点), 剩下为遍历的中序遍历为 [10, 9, 3, 15, 20, 7]
10 这个值有 push 到栈中, 因为 10 也是我们暂时没有建立右节点的节点或者确定是否拥有右节点的节点

而又遇到了栈顶元素和剩余中序遍历元素的首个元素的时间点, 于是我们继续进行栈的 pop 和中序遍历的指针移动.
最终确定 20 为 3 的右节点.

以此类推..........
LeetCode 官方归纳如下:

- 我们用一个栈和一个指针辅助进行二叉树的构造。初始时栈中存放了根节点（前序遍历的第一个节点），指针指向中序遍历的第一个节点；
- 我们依次枚举前序遍历中除了第一个节点以外的每个节点。如果 index 恰好指向栈顶节点，那么我们不断地弹出栈顶节点并向右移动 index，并将当前节点作为最后一个弹出的节点的右儿子；如果 index 和栈顶节点不同，我们将当前节点作为栈顶节点的左儿子；
- 无论是哪一种情况，我们最后都将当前的节点入栈。

*/
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (!preorder.size()) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[0]);
        stack<TreeNode *> stk;
        stk.push(root);
        int inorderIndex = 0;
        for (int i = 1; i < preorder.size(); ++i) {
            int preorderVal = preorder[i];
            TreeNode *node = stk.top();
            if (node->val != inorder[inorderIndex]) {
                node->left = new TreeNode(preorderVal);
                stk.push(node->left);
            } else {
                while (!stk.empty() && stk.top()->val == inorder[inorderIndex]) {
                    node = stk.top();
                    stk.pop();
                    ++inorderIndex;
                }
                node->right = new TreeNode(preorderVal);
                stk.push(node->right);
            }
        }
        return root;
    }
};
// @lc code=end
