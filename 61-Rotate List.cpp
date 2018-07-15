/*
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL

Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
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


// 旋转链表

 
// 思路：
// 若k大于链表长度n，则取k=k%n;
// 在原链表上走n-k-1步，这时的结点作为最后一个结点，而它下一个节点作为头结点;

// 特殊情况的考虑：
// 当n==k或n==1时，相当于不旋转，直接返回.
// 当head==nullptr或k==0时，直接返回head.
 
// My solution:
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || k<=0)
            return head;
        int n=0;
        ListNode* pNode=head;
        while(pNode)  // 计算链表长度n
        {
            n++;
            pNode = pNode->next;
        }
        
        if(k==n || n==1)
            return head;
        else if(k>n)
            k = k%n;
        
        if(k==0)
            return head;
        
        pNode = head;
        for(int i=0; i<n-k-1; i++)
            pNode=pNode->next;
        ListNode* pNext = pNode->next;
        ListNode* newHead = pNext;
        while(pNext->next)
            pNext=pNext->next;
        pNext->next = head;
        pNode->next = nullptr;
        
        return newHead;
    }
};
