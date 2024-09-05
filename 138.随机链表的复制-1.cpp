#include "header.h"

/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */
// 根据官方方法 1 改的利用哈希的两次迭代的方法
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
  public:
    Node *copyRandomList(Node *head) {
        unordered_map<Node *, Node *> nodeMap;
        Node *pos = head;

        while (pos) {
            nodeMap[pos] = new Node(pos->val);
            pos = pos->next;
        }

        pos = head;
        while (pos) {
            nodeMap[pos]->next = nodeMap[pos->next];
            nodeMap[pos]->random = nodeMap[pos->random];
            pos = pos->next;
        }

        return nodeMap[head];
    }
};

// @lc code=end
