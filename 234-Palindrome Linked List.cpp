/*
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false

Example 2:

Input: 1->2->2->1
Output: true

Follow up:
Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {

    }
};



// 回文链表  [E]
// 快慢指针 + 翻转


// O(n) time and O(1) space
// 快慢指针+反转后半段链表
// My solution:
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;

        ListNode* fast = head, *slow = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* node = slow->next;
        slow->next = NULL;
        ListNode* pre = NULL;
        while (node)
        {
            ListNode* next = node->next;
            node->next = pre;
            pre = node;
            node = next;
        }

        node = pre;
        while (node)
        {
            if (node->val != head->val)
                return false;
            node = node->next;
            head = head->next;
        }
        return true;
    }
};


// O(n) time and O(n) space
// Stack
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode *slow = head, *fast = head;
        stack<int> s;
        s.push(head->val);
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            s.push(slow->val);
        }
        if (!fast->next) s.pop();
        while (slow->next) {
            slow = slow->next;
            int tmp = s.top(); s.pop();
            if (tmp != slow->val) return false;
        }
        return true;
    }
};