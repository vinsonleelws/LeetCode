Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5

Example 2:

Input: 1->1->1->2->3
Output: 2->3

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// 思路：使用一个辅助的前驱指针来进行操作：
// 前驱指针pPrev初始化为NULL。每次判断当前有没连续的重复项，若有则改写连接关系直至当前结点的下一项不重复，
// 此时若pPrev==NULL，表明要删除的包括头结点，因此改写头结点为当前结点的下一结点；反之，若pPrev不为NULL，
// 则改写pPrev->next为当前结点的下一结点。
// 若当前结点无重复项，则将pPrev更新为当前结点，然后检查下一个结点。

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || !head->next)
            return head;
        
        ListNode* pNode = head;
        ListNode* pPrev = NULL;

        while(pNode)
        {
            if(pNode->next && pNode->val == pNode->next->val)
            {
                while(pNode->next && pNode->val == pNode->next->val)
                    pNode->next = pNode->next->next;
                
                if(pPrev == NULL)
                    head = pNode->next;
                else
                    pPrev->next = pNode->next;
            }
            else
                pPrev = pNode;
            
            pNode = pNode->next;
        }
        return head;
    }
};


// Corner cases:
// 1->1->2->2->3