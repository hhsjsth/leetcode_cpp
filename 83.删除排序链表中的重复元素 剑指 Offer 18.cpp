#include "header.h"

/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */
// 不用看官方了, 自己写的比官方优雅, 而且不需要 dummy 链表节点
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) {
            return NULL;
        }

        ListNode *pos = head;

        while (pos && pos->next) {
            while (pos->next && pos->val == pos->next->val) {
                ListNode *tmp = pos->next;
                pos->next = tmp->next;
                delete tmp;
            }
            if (pos->next)
                pos = pos->next;
        }

        return head;
    }
};
// @lc code=end
