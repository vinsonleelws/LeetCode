/* 
Given a linked list, swap every two adjacent nodes and return its head.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.

Note:

    Your algorithm should use only constant extra space.
    You may not modify the values in the list's nodes, only nodes itself may be changed. */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 成对交换两个结点


// Reference solution.
// #1
// 步骤：(每次pre结点指向前一个结点)
// 1-前一个结点指向后一个结点的后一个结点
// 2-后一个结点指向前一个结点
// 3-pre结点指向后一个结点
// 4-更新pre结点为后一个结点的后一个结点
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(-1), *pre = dummy;
        dummy->next = head;
        while (pre->next && pre->next->next) {
            ListNode *t = pre->next->next;
            pre->next->next = t->next;
            t->next = pre->next;
            pre->next = t;
            pre = t->next;
        }
        return dummy->next;
    }
};

// #2 递归写法
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *t = head->next;
        head->next = swapPairs(head->next->next);
        t->next = head;
        return t;
    }
};

// #3
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



// Testing cases.
// Input: [2,5,3,4,6,2,2]
// Expected: [5,2,4,3,2,6,2]