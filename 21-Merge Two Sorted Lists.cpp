/* 
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// 合并两个有序链表
// 循环 ; 递归

// Reference solution:
// #1
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1), *cur = dummy;
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
        cur->next = l1 ? l1 : l2;
        return dummy->next;
    }
};

// #2 递归解法 - 非常简洁
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val) 
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } 
        else 
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

// #3
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode *head = l1->val < l2->val ? l1 : l2;
        ListNode *nonhead = l1->val < l2->val ? l2 : l1;
        head->next = mergeTwoLists(head->next, nonhead);
        return head;
    }
};
 
// My solution:
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr)
            return l2;
        else if(l2==nullptr)
            return l1;
        
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* pNew = nullptr;
        ListNode* pNewHead = nullptr;
        if(p1->val < p2->val)
        {
            pNew = pNewHead = p1;
            p1 = p1->next;
        }
        else
        {
            pNew = pNewHead = p2;
            p2 = p2->next;
        }

        while(p1 && p2)
        {
            if(p1->val < p2->val)
            {
                pNew->next = p1;
                pNew = p1;
                p1 = p1->next;
            }
            else
            {
                pNew->next = p2;
                pNew = p2;
                p2 = p2->next;
            }
        }
        
        while(p1)
        {
            pNew->next = p1;
            pNew = p1;
            p1 = p1->next;
        }
        
        while(p2)
        {
            pNew->next = p2;
            pNew = p2;
            p2 = p2->next;
        }
        
        return pNewHead;
    }
};