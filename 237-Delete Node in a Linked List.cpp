Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function. 


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 这道题让我们删除链表的一个节点，与平常不一样的是没有给我们链表的起点，只给我们了一个要删的节点。
// 这道题的处理方法是先把当前节点的值用下一个节点的值覆盖，如此进行直到最后一个节点，最后将倒数第二个节点的next置空即可。
// My solution:
// 把当前节点的值用下一个节点的值覆盖，如此进行直到最后一个节点，最后将倒数第二个节点的next置空。
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* pre = node;
        while(node->next)
        {
            node->val = node->next->val;
            pre = node;
            node = node->next;
        }
        pre->next = NULL;
    }
};

// 还有一种更有时间效率的方法：
// 先用下一节点的值覆盖当前节点的值，然后把除了下一节点的后续所有节点链接在当前结点后面~
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode *tmp = node->next;
        node->next = tmp->next;
        delete tmp;
    }
};