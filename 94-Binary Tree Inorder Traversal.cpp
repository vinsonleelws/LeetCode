Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]

Follow up: Recursive solution is trivial, could you do it iteratively?


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// #1
// 递归解法：
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr)
            return result;
        inorderTraversal(root, result);
        return result;
    }
    
    void inorderTraversal(TreeNode* root, vector<int>& result)
    {
        if(root == nullptr)
            return;

        if(root->left)
            inorderTraversal(root->left, result);

        result.push_back(root->val);

        if(root->right)
            inorderTraversal(root->right, result);
    }
};

// #2
// 非递归解法：
// 使用栈
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr)
            return result;
        stack<TreeNode*> s;
        TreeNode* pNode = root;
        while(pNode || s.size())
        {
            if(pNode)
            {
                s.push(pNode);
                pNode = pNode->left;
            }
            else
            {
                pNode = s.top();
                s.pop();
                result.push_back(pNode->val);
                pNode = pNode->right;
            }
        }
        return result;
    }
};


// #3
// 非递归，不用栈，空间复杂度为O(1)的解法
// Morris遍历法，基于线索二叉树（Threaded Binary Tree）的解法
// 步骤：
// 1. 如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点。
// 2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点（当前结点左子树中的最右子节点）。
   // a) 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点（将pre指针指向cur的左子树中的最右子节点）。当前节点更新为其左孩子。
   // b) 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空（恢复树的形状）。输出当前节点。当前节点更新为当前节点的右孩子。
// 3. 重复以上1、2直到当前节点为空。

// Non-recursion and no stack, O(1) space complexity
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        if (!root) 
            return result;
        TreeNode *cur, *pre;
        cur = root;
        while(cur) 
        {
            if(!cur->left)  // 1
            {
                result.push_back(cur->val);
                cur = cur->right;
            } 
            else 
            {
                pre = cur->left;
                while (pre->right && pre->right != cur) 
                    pre = pre->right;
                if (!pre->right)  // 2.a)
                {
                    pre->right = cur;
                    cur = cur->left;
                } 
                else  // 2.b)
                {
                    pre->right = NULL;
                    result.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return result;
    }
};