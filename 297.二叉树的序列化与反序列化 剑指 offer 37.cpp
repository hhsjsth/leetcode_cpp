#include "header.h"

/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */
// LeetCode 官方方法 1
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
  public:
    // The prefix r in rserialize likely stands for “recursive.” In coding, prefixes like this are often used to indicate a function's purpose or behavior, and in this case, it's signaling that this function performs its task recursively.
    // It's a common convention in programming to use descriptive prefixes to make the code easier to understand at a glance. You might see similar naming conventions like pfunc for a function that processes something, or mCalculate for a method that handles calculations.
    void rserialize(TreeNode *root, string &str) {
        if (root == nullptr) {
            str += "None,";
        } else {
            str += to_string(root->val) + ",";
            rserialize(root->left, str);
            rserialize(root->right, str);
        }
    }

    string serialize(TreeNode *root) {
        string ret;
        rserialize(root, ret);
        return ret;
    }

    TreeNode *rdeserialize(list<string> &dataArray) {
        if (dataArray.front() == "None") {
            dataArray.erase(dataArray.begin());
            return nullptr;
        }

        TreeNode *root = new TreeNode(stoi(dataArray.front()));
        dataArray.erase(dataArray.begin());
        root->left = rdeserialize(dataArray);
        root->right = rdeserialize(dataArray);
        return root;
    }

    TreeNode *deserialize(string data) {
        list<string> dataArray;
        string str;
        for (auto &ch : data) {
            if (ch == ',') {
                dataArray.push_back(str);
                str.clear();
            } else {
                str.push_back(ch);
            }
        }
        if (!str.empty()) {
            dataArray.push_back(str);
            str.clear();
        }
        return rdeserialize(dataArray);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
