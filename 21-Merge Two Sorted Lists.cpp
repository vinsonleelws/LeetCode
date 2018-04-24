Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

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