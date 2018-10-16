/*Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3

begin to intersect at node c1.

Notes:

    If the two linked lists have no intersection at all, return null.
    The linked lists must retain their original structure after the function returns.
    You may assume there are no cycles anywhere in the entire linked structure.
    Your code should preferably run in O(n) time and use only O(1) memory.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    }
};


// 两个链表的交叉点  [E]
// 遍历求链表长度，较长的先走差值步数，然后再一起走


// 思路：分别遍历两个链表，得到分别对应的长度。然后求长度的差值，把较长的那个链表向后移动这个差值的个数，然后一一比较即可
// （如果两个链长度相同的话，那么对应的一个个比下去就能找到）

// My solution:
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return NULL;

        int n1 = 1, n2 = 1;
        ListNode * p1 = headA, *p2 = headB;
        while (p1->next)
        {
            p1 = p1->next;
            n1++;
        }
        while (p2->next)
        {
            p2 = p2->next;
            n2++;
        }

        p1 = headA, p2 = headB;
        if (n1 > n2)
        {
            for (int i = 0; i < n1 - n2; i++)
                p1 = p1->next;
        }
        else
        {
            for (int i = 0; i < n2 - n1; i++)
                p2 = p2->next;
        }

        while (p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }

        return p1;
    }
};

// 另一种解法：
// 这道题还有一种特别巧妙的方法，虽然题目中强调了链表中不存在环，但是我们可以用环的思想来做：我们让两条链表同时从各自的开头开始往后遍历，当其中一条遍历到末尾时，
// 我们跳到另一个条链表的开头继续遍历。两个指针最终会相等，而且只有两种情况，一种情况是在交点处相遇，另一种情况是在各自的末尾的空节点处相等。
// 这是因为两个指针走过的路程相同，是两个链表的长度之和，所以一定会相等。
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode *a = headA, *b = headB;
        while (a != b)
        {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};