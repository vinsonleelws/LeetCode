/*
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4

Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
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
    ListNode* sortList(ListNode* head) {
        
    }
};

// 链表排序 (O(nlogn))  [M]
// Merge Sort

// 这里题目限定了时间必须为O(nlgn)，符合要求只有快速排序，归并排序，堆排序。而根据单链表的特点，最适于用归并排序。
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) 
            return head;
        ListNode *slow = head, *fast = head, *pre = head;
        while (fast && fast->next)  // 用快慢指针找到中间结点
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL; // 断开为两条链表
        return merge(sortList(head), sortList(slow));
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while (l1 && l2) 
        {
            if (l1->val < l2->val) 
            {
                cur->next = l1;
                l1 = l1->next;
            } 
            else 
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1) 
            cur->next = l1;
        if (l2) 
            cur->next = l2;
        return dummy->next;
    }
};

// 另一种更简洁的写法：在merge函数中也使用了递归，这样使代码更加简洁
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *slow = head, *fast = head, *pre = head;
        while (fast && fast->next) 
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        return merge(sortList(head), sortList(slow));
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1) 
            return l2;
        if (!l2) 
            return l1;
        if (l1->val < l2->val) 
        {
            l1->next = merge(l1->next, l2);
            return l1;
        } 
        else 
        {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
};