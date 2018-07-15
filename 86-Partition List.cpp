/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 
 */

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
    }
};


// 划分链表
// Two Pointers

// Reference solution:
// #1
// 思路：
// 根据题意，把所有小于给定值的节点都移到前面，大于该值的节点顺序不变.
// 关键是找到链表中第一个大于等于x的结点，将它前面的一个结点作为前驱结点pPrev，
// 之后的操作就是在pPrev/pNode/pNext之间根据结点值与x的大小关系修改连接关系.
// 为了方便处理结点插入到头结点的情况，可使用一个虚拟头结点dummy，令dummy->next = head.

// 不使用dummy结点的解法：
// 需特别注意插入到头结点的情况 (头结点元素值大于等于x，且后面有小于x的节点存在)
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL)
            return head;

        ListNode* pNode = head;
        ListNode* pPrev = NULL;
        
        if(pNode->val < x)
        {
            while(pNode->next && pNode->next->val < x)
                pNode = pNode->next;
            pPrev = pNode;
        }
        else
            pPrev = NULL;
        
        while(pNode->next)
        {
            ListNode* pNext = pNode->next;
            if(pNext->val >= x)
                pNode = pNode->next;
            else
            {
                if(!pPrev)
                {
                    pNode->next = pNext->next;
                    pNext->next = head;
                    pPrev = head = pNext;
                }
                else
                {
                    pNode->next = pNext->next;
                    pNext->next = pPrev->next;
                    pPrev->next = pNext;
                    pPrev = pNext;
                }
            }
        }
        return head;
    }
};

// 使用dummy结点的写法：
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL)
            return head;
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pNode = dummy;
        ListNode* pPrev = dummy;
        
        while(pNode->next && pNode->next->val < x)  // 找到值大于等于x的结点
            pNode = pNode->next;
        pPrev = pNode;
        
        while(pNode->next)
        {
            ListNode* pNext = pNode->next;
            if(pNext->val >= x)  // 如果大于等于x，接着走
                pNode = pNode->next;
            else                // 反之，将其插入pPrev之后
            {
                pNode->next = pNext->next;
                pNext->next = pPrev->next;
                pPrev->next = pNext;
                pPrev = pNext;
            }
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};

// 以1->4->3->2->5->2, x = 3为例
// 这种解法链表变化顺序为：
// 1 -> 4 -> 3 -> 2 -> 5 -> 2 
// 1 -> 2 -> 4 -> 3 -> 5 -> 2 
// 1 -> 2 -> 2 -> 4 -> 3 -> 5


// #2
// 另一种解法是将所有小于给定值的节点取出组成一个新的链表，此时原链表中剩余的节点的值都大于或等于给定值，只要将原链表直接接在新链表后即可
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (!head) 
            return head;
        ListNode *dummy = new ListNode(-1);
        ListNode *newDummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy, *p = newDummy;
        while (cur->next) {
            if (cur->next->val < x) {
                p->next = cur->next;
                p = p->next;
                cur->next = cur->next->next;
                p->next = NULL;
            } else {
                cur = cur->next;
            }
        }
        p->next = dummy->next;
        return newDummy->next;
    }
};
