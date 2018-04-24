Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// Reference solution (one pass solution)
// 使用两个指针pre和cur, cur先走n步，如果此时指向的是空指针，表示要删除的是头结点，
// 返回head->next. 否则，让cur和pre同时走，直到cur走到最后一个结点，
// 此时pre指向的是待删除结点的前一个结点。

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr)
            return nullptr;
        
        ListNode* pre = head;
        ListNode* cur = head;
        for(int i=0; i<n; i++)
            cur = cur->next;
        
        if(cur==nullptr)
            return head->next;
        else
        {
            while(cur->next)
            {
                cur = cur->next;
                pre = pre->next;
            }
            
            pre->next = pre->next->next;
            return head;
        }
    }
};
 
// My solution. (using two passes)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr)
            return nullptr;
        ListNode* pNode = head;
        int length = 1;
        while(pNode->next)
        {
            length++;
            pNode = pNode->next;
        }
        
        if(length==n)  // when the 'head' is the target
        {
            if(length==1)
                return nullptr;
            else
            {
                pNode = head->next;
                delete head;
                head = nullptr;
                return pNode;
            }
        }
        
        pNode = head;
        int steps = length-n;
        for(int i=0; i<steps-1; i++)
            pNode = pNode->next;
        
        ListNode* pToBeDeleted = pNode->next;
        pNode->next = pToBeDeleted->next;
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
        
        return head;
    }
};

// Testing cases. 注意单节点的情况，删除的是最后一个节点的情况。
//[1]
//1

// Input: [1,2]
// 2
// Expected: [2]