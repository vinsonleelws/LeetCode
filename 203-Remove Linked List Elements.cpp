/*
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
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
    ListNode* removeElements(ListNode* head, int val) {
        
    }
};

// 移除链表元素（给定待删除节点的值）

// My solution:
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return NULL;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* node = dummy;
        while(node->next)
        {
            if(node->next->val == val)
            {
                if(node->next->next)  // 若待删除结点后面还有结点
                {
                    ListNode* pNext = node->next->next;
                    node->next = pNext;
                }
                else
                    node->next = NULL;
            }
            else
                node = node->next;
        }
        
        return dummy->next;
    }
};

// 此题也可用递归来做：
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) 
            return NULL;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};