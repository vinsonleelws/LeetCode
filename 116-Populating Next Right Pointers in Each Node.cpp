Given a binary tree

struct TreeLinkNode {
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
}

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

    You may only use constant extra space.
    Recursive approach is fine, implicit stack space does not count as extra space for this problem.
    You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).

Example:

Given the following perfect binary tree,

     1
   /  \
  2    3
 / \  / \
4  5  6  7

After calling your function, the tree should look like:

     1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \  / \
4->5->6->7 -> NULL


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
// 法一：空间复杂度为O(1)的解法
// 用两个指针start和cur，其中start标记每一层的起始节点，cur用来遍历该层的节点
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) 
            return;
        TreeLinkNode *start = root, *cur = NULL;
        while (start->left) 
        {
            cur = start;
            while (cur) 
            {
                cur->left->next = cur->right;
                if (cur->next) 
                    cur->right->next = cur->next->left;
                cur = cur->next;
            }
            start = start->left;
        }
    }
};

// 法二：基于递归的实现
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)
            return;
        if(root->left)
            root->left->next = root->right;
        if(root->right)
            root->right->next = root->next? root->next->left : NULL;
        
        connect(root->left);
        connect(root->right);
    }
};

// 法三：基于层次遍历的实现，使用队列。
// 空间复杂度为O(n).
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeLinkNode *t = q.front(); q.pop();
                if (i < size - 1) {
                    t->next = q.front();
                }
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
    }
};

// 另一种写法，在队列中使用NULL来分层
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        q.push(NULL);
        while (true) {
            TreeLinkNode *cur = q.front();
            q.pop();
            if (cur) {
                cur->next = q.front();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            } else {
                if (q.size() == 0 || q.front() == NULL) return;
                q.push(NULL);
            }
        }
    }
};
