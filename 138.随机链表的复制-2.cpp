#include "header.h"

/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */
// 官方方法 2
// 虽然官方方法 2 说 "读者们也可以自行尝试在计算拷贝节点的随机指针的同时计算其后继指针，这样只需要遍历两次。"
// 但是实操不行, 可以看下面的注释
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
        if (head == nullptr) {
            return nullptr;
        }

        // 不用哈希, 直接使用原链表的 next 指针使得新建节点一一对应
        for (Node *node = head; node != nullptr; node = node->next->next) {
            Node *nodeNew = new Node(node->val);
            nodeNew->next = node->next;
            node->next = nodeNew;
        }

        for (Node *node = head; node != nullptr; node = node->next->next) {
            Node *nodeNew = node->next;

            nodeNew->random = (node->random != nullptr) ? node->random->next : nullptr;
            // 这里下面如果注释取消, 则上面不能使用 node->random->next
            // 因为 node 可能是后面循环的 random, 其 next 指针被修改则上面通过 node->random->next 的 ->next 就不一定能够对应到新建的节点了
            // node->next = node->next->next;
            // nodeNew->next = (nodeNew->next != nullptr) ? nodeNew->next->next : nullptr;
        }

        Node *headNew = head->next;
        for (Node *node = head; node != nullptr; node = node->next) {
            Node *nodeNew = node->next;
            node->next = node->next->next;
            nodeNew->next = (nodeNew->next != nullptr) ? nodeNew->next->next : nullptr;
        }

        return headNew;
    }
};

// @lc code=end
