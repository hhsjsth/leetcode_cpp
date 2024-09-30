#include "header.h"

/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 */
// 比 LeetCode 官方优雅, 不需要看官方题解
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
        ListNode *dummy = new ListNode(0, head);
        ListNode *pre = dummy;
        ListNode *post = head;

        while (pre->next && post->next) {
            // 遇到重复的时候后指针持续向右找到不重复的元素
            // 注意 post->next 需要判空, 否则 pre->next->val = post->next->val; 会出现空指针访问
            // 需理解 post->next 为空, 说明找到了链表末尾, 跳出循环继续到下面做收尾工作
            while (post->next && pre->next->val == post->next->val) {
                post = post->next;
            }

            // 如果不是重复元素, 说明 pre->next == post, 两个指针同时向后移动一个元素, 继续下一个循环
            if (pre->next == post) {
                pre = pre->next;
                post = pre->next;
                continue;
            }

            // 没有进入上面的 if 然后 continue, 说明发现了重复元素
            // 向右移动到不重复的那个元素, 成为哨兵, 后面循环判断 pre->next != post
            post = post->next;

            while (pre->next != post) {
                ListNode *tmp = pre->next;
                pre->next = tmp->next;
                delete tmp;
            }
        }
        return dummy->next;
    }
};
// @lc code=end
