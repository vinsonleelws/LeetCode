Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 法一：基于递归的实现，每次根据结点下标扫描链表
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;
        
        int len=0;
        ListNode* pNode = head;
        while(pNode->next)
        {
            len++;
            pNode = pNode->next;
        }
        
        return sortedListToBSTRecursive(head, 0, len);
    }
    
    TreeNode* sortedListToBSTRecursive(ListNode* head, int start, int end) {
        if(start>end)
            return NULL;
        
        int mid = (start+end)>>1;
        ListNode* midnode = head;
        for(int i=0; i<mid; i++)
            midnode = midnode->next;
        TreeNode* root = new TreeNode(midnode->val);
        root->left = sortedListToBSTRecursive(head, start, mid-1);
        root->right = sortedListToBSTRecursive(head, mid+1, end);
        return root;
    }
};
// 由于可能存在多次对链表从头到尾的扫描，导致时间效率不高。


// 法二：使用快慢指针
// 快指针fast一次走两步，慢指针slow一次走一步; last指针记录slow的前一个结点
// 当fast指针走到尾时，slow指针恰好走到中间结点，根节点的值由slow指向的结点值产生。
// 接下来递归调用生成左右子树：
// 1) 当slow!=head，说明有左子树，递归调用生成左子树：root->left = sortedListToBST(head);
// 2) 递归调用生成右子树：root->right = sortedListToBST(fast);
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head) 
            return NULL;
        if (!head->next) 
            return new TreeNode(head->val);
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *last = slow;
        while (fast->next && fast->next->next) {
            last = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        last->next = NULL;
        TreeNode *root = new TreeNode(slow->val);
        if (head != slow) 
            root->left = sortedListToBST(head);
        root->right = sortedListToBST(fast);
        return root;
    }
};