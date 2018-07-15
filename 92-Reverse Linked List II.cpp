/*Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
    }
};

// Reverse Linked List II-反转链表II（from position m to n）

// My solution:
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy;
        ListNode *pre; 
        for (int i = 1; i <= m - 1; ++i) 
            cur = cur->next;
        pre = cur;
        cur = cur->next;
        ListNode* curNext = cur->next;
        ListNode* last = cur;
        for (int i = m; i <= n-1; ++i)
        {
            ListNode* curNextNext = curNext->next;
            curNext->next = cur;
            cur = curNext;
            curNext = curNextNext;
        }
        pre->next = cur;
        last->next = curNext;

        return dummy->next;
    }
};

// Reference solution:
// Runtime beats 100% of cpp submissions.
// 使用dummy结点方便处理修改头结点的情况，简化逻辑：
// pre指向第一个待反转结点的前一个结点, front记录上一个cur, last表示反转后的最后一个结点（也即第一个待反转结点）
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy;
        ListNode *pre, *front, *last; 
        for (int i = 1; i <= m - 1; ++i) 
            cur = cur->next;
        pre = cur;
        last = cur->next;
        for (int i = m; i <= n; ++i)
        {
            cur = pre->next;
            pre->next = cur->next;
            cur->next = front;
            front = cur;
        }
        cur = pre->next;
        pre->next = front;
        last->next = cur;
        return dummy->next;
    }
};
// 转换过程：
// 从第二个for循环开始：
// i=2: 1->3->4->5->NULL  cur/front -> 2->NULL
// i=3: 1->4->5->NULL  cur/front -> 3->2->NULL
// i=4: 1->5->NULL  cur/front -> 4->3->2->NULL
// last:2
// 1->4->3->2->5->NULL

// My solution:
// 特殊情况的考虑：
// (1) 当n<=0 或 m==n 或 head==NULL的时候直接返回；
// (2) 当m==1和m==0时，需更换头结点；而在m==0时，表示反转n+1个结点，因此在一般操作上多一个结点入栈。
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL || m==n || n<=0)
            return head;
        
        ListNode* start = NULL;
        ListNode* end = NULL;
        ListNode* pNode = head;
        stack<ListNode*> pStack;
        int i=1;
        
        if(m==1 || m==0)    // 处理从头结点开始的情况
            pStack.push(head);
        
        while(pNode->next && i<m-1)
        {
            pNode = pNode->next;
            i++;
        }
        start = pNode;
        while(pNode->next && i<=n-1)
        {
            pNode = pNode->next;
            pStack.push(pNode);
            i++;
        }
        
        if(m==0 && pNode->next) // 处理从头结点开始的情况
        {
            pNode = pNode->next;
            pStack.push(pNode);
        }
        
        if(pNode->next)
            end = pNode->next;
        else
            end = NULL;
        
        if((m==1 || m==0) && pStack.size())  // 处理从头结点开始的情况
        {
            pNode = pStack.top();
            pStack.pop();
            pNode->next = head;
            head = start = pNode;
        }
        
        while(pStack.size())
        {
            pNode = pStack.top();
            pStack.pop();
            start->next = pNode;
            start = pNode;
        }
        start->next = end;
        
        return head;
    }
};
