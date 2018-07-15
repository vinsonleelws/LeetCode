//==================================================================
// LeetCode  
// add-two-numbers
// Author：wsli
//==================================================================

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807. 
*/

// 两个数字相加
// Math

#include <cstdio>
#include "Utilities\List.cpp"

// Definition for singly-linked list.
// struct ListNode {
    // int val;
	// ListNode *next;
	// ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *res = new ListNode(-1);
        ListNode *cur = res;
        int carry = 0;
        while (l1 || l2) 
        {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if (l1) 
                l1 = l1->next;
            if (l2) 
                l2 = l2->next;
        }
        if (carry) 
            cur->next = new ListNode(1);
        return res->next;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
       if(l1 == nullptr)
            return l2;
       else if(l2 == nullptr)
           return l1;
       
       ListNode* lsum = new ListNode();
       ListNode* lsumHead = lsum;
       int carry=0;
       ListNode* l1Node = l1;
       ListNode* l2Node = l2;
       int sum = 0;
       while(l1Node || l2Node)
       {
           if(l1Node && l2Node)
               sum = l1Node->m_nValue + l2Node->m_nValue + carry;
           else if(l1Node && !l2Node)
               sum = l1Node->m_nValue + carry;
           else
               sum = l2Node->m_nValue + carry;
           
           lsum->m_pNext = new ListNode();
           lsum = lsum->m_pNext;
           lsum->m_nValue = sum%10;
           carry = sum/10;
           
           if(l1Node)
               l1Node = l1Node->m_pNext;
           
           if(l2Node)
               l2Node = l2Node->m_pNext;
      }
      
      if(carry > 0)
      {
          lsum->m_pNext = new ListNode();
          lsum->m_pNext->m_nValue = carry;
      }

      return lsumHead->m_pNext;
    }
};

// For LeetCode
/* class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
       if(l1 == nullptr)
            return l2;
       else if(l2 == nullptr)
           return l1;
       
       ListNode* lsum = new ListNode(0);
       ListNode* lsumHead = lsum;
       int carry=0;
       ListNode* l1Node = l1;
       ListNode* l2Node = l2;
       int sum = 0;
       while(l1Node || l2Node)
       {
           if(l1Node && l2Node)
               sum = l1Node->val + l2Node->val + carry;
           else if(l1Node && !l2Node)
               sum = l1Node->val + carry;
           else
               sum = l2Node->val + carry;
           
           lsum->next = new ListNode(sum%10);
           lsum = lsum->next;
           carry = sum/10;
           
           if(l1Node)
               l1Node = l1Node->next;
           
           if(l2Node)
               l2Node = l2Node->next;
      }
      
      if(carry > 0)
          lsum->next = new ListNode(carry);

      return lsumHead->next;
    }
}; */

/* Reference Method
class Solution {
public:
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        //ListNode dummy(-1);
        ListNode dummy;
        int carry = 0;
        ListNode *prev = &dummy;
        for (ListNode *pa = l1, *pb = l2;
        pa != nullptr || pb != nullptr;
        pa = pa == nullptr ? nullptr : pa->m_pNext,
        pb = pb == nullptr ? nullptr : pb->m_pNext,
        prev = prev->m_pNext) {
            const int ai = pa == nullptr ? 0 : pa->m_nValue;
            const int bi = pb == nullptr ? 0 : pb->m_nValue;
            const int value = (ai + bi + carry) % 10;
            carry = (ai + bi + carry) / 10;
            //prev->m_pNext = new ListNode(value); 
            prev->m_pNext = new ListNode();
            prev->m_pNext->m_nValue = value;
        }
        if (carry > 0){
            prev->m_pNext = new ListNode();
            prev->m_pNext->m_nValue = carry;
        }
        return dummy.m_pNext;
    }
}; */
        
        
// ====================测试代码====================
ListNode* Test(ListNode* pHead1, ListNode* pHead2)
{
    printf("The original list1 is: \n");
    PrintList(pHead1);
    
    printf("The original list2 is: \n");
    PrintList(pHead2);

    Solution Sol;
    ListNode* pHeadSum = Sol.addTwoNumbers(pHead1, pHead2);

    printf("The sum list is: \n");
    PrintList(pHeadSum);

    return pHeadSum;
}

// 输入的链表有多个结点
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    
    ListNode* pNode6 = CreateListNode(1);
    ListNode* pNode7 = CreateListNode(2);
    ListNode* pNode8 = CreateListNode(3);
    ListNode* pNode9 = CreateListNode(12);
    ListNode* pNode10 = CreateListNode(5);

    ConnectListNodes(pNode6, pNode7);
    ConnectListNodes(pNode7, pNode8);
    ConnectListNodes(pNode8, pNode9);
    ConnectListNodes(pNode9, pNode10);

    ListNode* pHeadSum = Test(pNode1, pNode6);

    DestroyList(pHeadSum);
}

// 输入的链表只有一个结点
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    
    ListNode* pNode2 = nullptr;

    ListNode* pHeadSum = Test(pNode1, pNode2);

    DestroyList(pHeadSum);
}

// 输入空链表
void Test3()
{
    Test(nullptr, nullptr);
}

// 两个链表长短不一致
void Test4()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    
    ListNode* pNode6 = CreateListNode(18);
    ListNode* pNode7 = CreateListNode(4);
    ListNode* pNode8 = CreateListNode(3);

    ConnectListNodes(pNode6, pNode7);
    ConnectListNodes(pNode7, pNode8);

    ListNode* pHeadSum = Test(pNode1, pNode6);

    DestroyList(pHeadSum);
}

// 两个链表长短不一致
void Test5()
{
    ListNode* pNode1 = CreateListNode(12);
    ListNode* pNode2 = CreateListNode(213);

    ConnectListNodes(pNode1, pNode2);
    
    ListNode* pNode6 = CreateListNode(18);
    ListNode* pNode7 = CreateListNode(4);
    ListNode* pNode8 = CreateListNode(3);

    ConnectListNodes(pNode6, pNode7);
    ConnectListNodes(pNode7, pNode8);

    ListNode* pHeadSum = Test(pNode1, pNode6);

    DestroyList(pHeadSum);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}