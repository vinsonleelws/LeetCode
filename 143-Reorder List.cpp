/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.

Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {

    }
};


// 链表重排序  [M]
// 找中间节点（快慢指针or遍历） + 翻转链表 + 隔元素插入结点

// 思路：
// 这道链表重排序问题可以拆分为以下三个小问题：
// 1. 找到链表的中点(使用快慢指针来，或走n/2步，n是总结点数)，并将链表从中点处断开，形成两个独立的链表。
// 2. 将第二个链翻转。
// 3. 将第二个链表的元素间隔地插入第一个链表中。

// My solution:
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head)
            return;

        int n = 1;
        ListNode* node = head;
        while (node->next)
        {
            n++;
            node = node->next;
        }

        if (n <= 2)
            return;
        
        ListNode* node1 = head;
        for (int i = 0; i < n / 2; i++)
            node1 = node1->next;

        ListNode* node2 = node1->next;  // 将链表分割为两部分
        node1->next = NULL;
        ListNode* cur = node2->next;
        ListNode* pre = node2;
        node2->next = NULL;
        while (cur) // 翻转后面的第二个链表
        {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        node1 = head;
        node2 = pre;
        while (node1 && node2)
        {
            ListNode* next1 = node1->next;
            ListNode* next2 = node2->next;
            node1->next = node2;
            node2->next = next1;
            node1 = next1;
            node2 = next2;
        }
        return;
    }
};

// 另一种写法：
class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head || !head->next || !head->next->next) return;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow->next;
        slow->next = NULL;
        ListNode *last = mid;
        ListNode *pre = NULL;
        while (last) {
            ListNode *next = last->next;
            last->next = pre;
            pre = last;
            last = next;
        }
        while (head && pre) {
            ListNode *next = head->next;
            head->next = pre;
            pre = pre->next;
            head->next->next = next;
            head = next;
        }
    }
};