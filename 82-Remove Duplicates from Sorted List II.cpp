/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5

Example 2:

Input: 1->1->1->2->3
Output: 2->3
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
    ListNode* deleteDuplicates(ListNode* head) {
        
    }
};

// 删除有序链表中的重复项II（删除全部）  [M]

 
// 思路：使用一个辅助指针来进行操作：
// 前驱指针prev初始化为NULL。每次判断当前有没连续的重复项，若有则改写连接关系直至当前结点的下一项不重复，
// 此时若prev==NULL，表明要删除的包括头结点，因此改写头结点为当前结点的下一结点；反之，若prev不为NULL，
// 则改写prev->next为当前结点的下一结点。
// 若当前结点无重复项，则将prev更新为当前结点，然后检查下一个结点。

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || !head->next)
            return head;
        
        ListNode* node = head;
        ListNode* prev = NULL;

        while(node)
        {
            if(node->next && node->val == node->next->val)
            {
                while(node->next && node->val == node->next->val)
                    node->next = node->next->next;
                
                if(prev == NULL)  // prev为NULL，表明要删除的包括头结点
                    head = node->next;
                else
                    prev->next = node->next;
            }
            else
                prev = node;
            
            node = node->next;
        }
        return head;
    }
};

// 更简洁的写法：
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) 
            return head;
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy;
        while (pre->next) 
        {
            ListNode *cur = pre->next;
            while (cur->next && cur->next->val == cur->val) 
                cur = cur->next;
            
            if (cur != pre->next) 
                pre->next = cur->next;
            else 
                pre = pre->next;
        }
        return dummy->next;
    }
};

// Corner cases:
// 1->1->2->2->3