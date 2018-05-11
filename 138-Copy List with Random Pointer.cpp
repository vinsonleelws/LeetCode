A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list. 

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
// 法一：
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)
            return NULL;
        
       RandomListNode* pNode = head;
       while(pNode)
       {
           RandomListNode* pNext = pNode->next;
           pNode->next = new RandomListNode(pNode->label);
           pNode->next->next = pNext;
           pNode = pNext;
       }
       
       pNode = head;
       while(pNode)
       {
           RandomListNode* pNext = pNode->next;
           if(pNode->random)
               pNext->random = pNode->random->next;
           pNode = pNext->next;
       }
       
       RandomListNode* newHead = head->next;
       RandomListNode* newNode = newHead;
       pNode = head;
       while(pNode)
       {
           if(newNode->next)
           {
                pNode->next = newNode->next;
                newNode->next = newNode->next->next;
                newNode = newNode->next;
           }
           else
               pNode->next = NULL;
         pNode = pNode->next;
       }
       
       return newHead;
    }
};


// 法二：使用哈希表的解法，但会引入额外空间
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        RandomListNode *res = new RandomListNode(head->label);
        RandomListNode *node = res;
        RandomListNode *cur = head->next;
        map<RandomListNode*, RandomListNode*> m;
        m[head] = res;
        while (cur) {
            RandomListNode *tmp = new RandomListNode(cur->label);
            node->next = tmp;
            m[cur] = tmp;
            node = node->next;
            cur = cur->next;
        }
        node = res;
        cur = head;
        while (node) {
            node->random = m[cur->random];
            node = node->next;
            cur = cur->next;
        }
        return res;
    }
};