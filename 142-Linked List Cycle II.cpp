Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space? 


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 仍然用快慢指针来做。
// 假设头指针到环入口的结点数位a, 快慢指针在环中的相遇点为Z, 环入口点走到Z的距离为b, Z走到入口点的距离为c
// 则根据快指针走的步数等于慢指针步数的2倍，有：a+b+c+b = 2(a+b)，可得a=c.
// 因此，首先记录快慢指针在环中相遇的位置，然后令一个指针从链表头开始走，此时两个指针每次都走一步，直到它们相遇的位置即为环的入口。
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) 
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) 
                break;
        }
        if (!fast || !fast->next) 
            return NULL;
        slow = head;
        while (slow != fast) 
        {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};