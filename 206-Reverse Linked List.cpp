Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL

Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// #1 Iterative
// 基于迭代的实现：
// 直接基于原链表修改
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return head;
        
        ListNode* pNext = NULL;
        if(head->next)
        {
            pNext = head->next;
            head->next = NULL;
        }
        else
            return head;
        
        ListNode* pNextNext = pNext->next;
        pNext->next = head;
        ListNode* pCur = pNext;
        pNext = pNextNext;
        while(pNext)
        {
            ListNode* pNextNext = pNext->next;
            pNext->next = pCur;
            pCur = pNext;
            pNext = pNextNext;
        }
        
        return pCur;
    }
};

// 使用栈：
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return head;
        stack<ListNode*> pStack;
        ListNode* pNode = head;
        while(pNode)
        {
            pStack.push(pNode);
            pNode = pNode->next;
        }
        pNode = head = pStack.top();
        pStack.pop();
        while(pStack.size())
        {
            pNode->next = pStack.top();
            pNode = pStack.top();
            pStack.pop();
        }
        pNode->next = NULL;
        return head;
    }
};


// #2 Recursion
// 基于递归的实现：
// 思路：不断的进入递归函数，直到head指向最后一个节点，p指向之前一个节点，然后调换head和p的位置，再返回上一层递归函数，
// 再交换p和head的位置，每次交换后，head节点后面都是交换好的顺序，直到p为首节点，然后再交换，首节点就成了为节点，此时整个链表也完成了翻转，
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) 
            return head;
        ListNode *p = head;
        head = reverseList(p->next);
        p->next->next = p;
        p->next = NULL;
        return head;
    }
};

// 递归过程中p和head的变化：
// 以1->2->3->4->5为例：
//    p: 1 2 3 4
// head: _ _ _ 5
// 指针的变化：
//    p: 1<-2<-3<-4
                 / \ 
                  |
// head: 5  5  5  5
