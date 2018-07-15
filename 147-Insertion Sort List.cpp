/*Sort a linked list using insertion sort.


A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list
 

Algorithm of Insertion Sort:

    Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
    At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
    It repeats until no input elements remain.


Example 1:

Input: 4->2->1->3
Output: 1->2->3->4

Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
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
    ListNode* insertionSortList(ListNode* head) {
        
    }
};


// 链表插入排序


// Reference solution: O(n^2)
// 以dummy结点为头结点，新建一个链表，逐步往新链表中插入元素
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(INT_MIN), *cur = dummy;
        while (head) 
        {
            ListNode *t = head->next;
            cur = dummy;
            while (cur->next && cur->next->val <= head->val) // 找到第一个大于当前结点的结点，将该结点插入到当前结点前面
                cur = cur->next;
            head->next = cur->next;
            cur->next = head;
            head = t;
        }
        return dummy->next;
    }
};
// 过程：
// 1) 4->2->1->3
// 2) -1->4  2->1->3  (假设dummy值为-1)
// 3) -1->2->4  1->3
// 4) -1->1->2->4   3
// 5) -1->1->2->3->4

// My solution:
// 在原链表基础上修改
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head)
            return NULL;
        
        ListNode* dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode* pCur = head;
        while(pCur->next)
        {
            ListNode* pNext = pCur->next;
            ListNode* pHead = dummy->next;
            if(pHead->val > pNext->val) // 若结点值小于头结点的值，将其插入到头结点
            {
                pCur->next = pNext->next;
                dummy->next = pNext;
                pNext->next = pHead;
            }
            else if(pCur->val > pNext->val)
            {
                while(pHead->next && pHead->next!=pNext && pHead->next->val <= pNext->val)
                    pHead = pHead->next;
                
                pCur->next = pNext->next;
                pNext->next = pHead->next;
                pHead->next = pNext;
            }
            else
                pCur = pCur->next;
        }
        
        return dummy->next;
    }
};

