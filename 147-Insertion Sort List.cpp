Sort a linked list using insertion sort.


A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list
 

Algorithm of Insertion Sort:

    Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
    At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
    It repeats until no input elements remain.


Example 1:

Input: 4->2->1->3
Output: 1->2->3->4

Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// My solution:
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head)
            return NULL;
        
        ListNode* dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode* pCur = head;
        while(pCur->next)
        {
            ListNode* pNext = pCur->next;
            ListNode* pHead = dummy->next;
            if(pHead->val > pNext->val)
            {
                pCur->next = pNext->next;
                dummy->next = pNext;
                pNext->next = pHead;
            }
            else if(pCur->val > pNext->val)
            {
                while(pHead->next && pHead->next!=pNext && pHead->next->val <= pNext->val)
                    pHead = pHead->next;
                
                pCur->next = pNext->next;
                pNext->next = pHead->next;
                pHead->next = pNext;
            }
            else
                pCur = pCur->next;
        }
        
        return dummy->next;
    }
};

// 另一种写法：
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        while (head) {
            ListNode *t = head->next;
            cur = dummy;
            while (cur->next && cur->next->val <= head->val) {
                cur = cur->next;
            }
            head->next = cur->next;
            cur->next = head;
            head = t;
        }
        return dummy->next;
    }
};