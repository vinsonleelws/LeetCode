Given a linked list, swap every two adjacent nodes and return its head.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.

Note:

    Your algorithm should use only constant extra space.
    You may not modify the values in the list's nodes, only nodes itself may be changed.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// My solution
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head)
            return nullptr;
        
        ListNode* newHead = nullptr;
        ListNode* pPrev = nullptr;
        if(head->next)
        {
            newHead = head->next;
            ListNode* pNext = head->next;
            head->next = pNext->next;
            pNext->next = head;
            pPrev = head;
            if(head->next)
                head = head->next;
        }
        else
            return head;
        
        while(head->next)
        {
            ListNode* pNext = head->next;
            pPrev->next = pNext;
            head->next = pNext->next;
            pNext->next = head;
            pPrev = head;
            if(head->next)
                head = head->next;
        }
        
        return newHead;
    }
};

// Reference solution.
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode **pp = &head;
        ListNode *a = nullptr;
        ListNode *b = nullptr;
        while((a = *pp) && (b = a->next))
        {
            a->next = b->next;
            b->next = a;
            *pp = b;
            pp = &(a->next);
        }
        return head;
    }
};

// Testing cases.
// Input: [2,5,3,4,6,2,2]
// Expected: [5,2,4,3,2,6,2]