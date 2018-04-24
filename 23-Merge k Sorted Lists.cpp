Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// My solution (Divide and Conquer)
// Time complexity : O(Nlogk) where k is the number of linked lists.
// Space complexity : O(1)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr;

        while(n>1)
        {
            int interval = (n+1)/2;            
            for(int i=0; i<n/2; i++)
                mergeTwoLists(lists[i], lists[i+interval]);
            
            n = interval;
        }
        
        return list[0];
    }
    
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

 
// My solution: (按顺序两两合并法)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr;
        
        ListNode* pNew = lists[0];
        for(int i=1; i<lists.size(); i++)
            pNew = (pNew, lists[i]);
        
        return pNew;
    }
    
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