/*Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

    Only constant extra memory is allowed.
    You may not alter the values in the list's nodes, only nodes itself may be changed.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
    }
};


// 每K个一组翻转链表

// 使用一个栈，每次压入K个结点（若不满足，则返回）进行翻转操作
// 用辅助变量last记住每次翻转后的最后一个结点，方便与下一次翻转的头结点连接起来
// 辅助变量node表示当前遍历到的结点
// 关于头结点的修改：头结点变为第K个结点（若存在）
// My solution:
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr)
            return nullptr;
        else if(k==1)
            return head;
        
        stack<ListNode*> pStack;
        ListNode* pNode = head;
        ListNode* pNewHead = head;
        ListNode* pLast = nullptr;
        while(pNode)
        {
            while(pStack.size()<k && pNode)
            {   
                pStack.push(pNode);
                pNode = pNode->next;
            }

            if(pStack.size()==k)
            {
                ListNode* pCur = pStack.top();
                pStack.pop();
                if(pLast)
                    pLast->next = pCur;
                if(pNewHead==head)
                    pNewHead = pCur;
                while(pStack.size())
                {
                    ListNode* pNext = pStack.top();
                    pStack.pop();
                    pCur->next = pNext;
                    pCur = pNext;
                }
                pCur->next = pNode;
                pLast = pCur;
            }
            else
                return pNewHead;
        }
        
        return pNewHead;
    }
    
};

// 另一种写法
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr)
            return nullptr;
        else if(k==1)
            return head;
        
        stack<ListNode*> pStack;
        ListNode* pNode = head;
        ListNode* pNewHead = head;
        ListNode* pLast = nullptr;
        while(pNode)
        {
            while(pStack.size()<k && pNode)
            {   
                pStack.push(pNode);
                pNode = pNode->next;
            }

            if(pStack.size()==k)
            {
                ListNode* pCur = pStack.top();
                pStack.pop();
                if(pLast)
                    pLast->next = pCur;
                if(pNewHead==head)
                    pNewHead = pCur;
                while(pStack.size())
                {
                    ListNode* pNext = pStack.top();
                    pStack.pop();
                    pCur->next = pNext;
                    pCur = pNext;
                    pCur->next = pNode;
                    pLast = pCur;
                }
            }
            else
                return pNewHead;
        }
        
        return pNewHead;
    }
    
};