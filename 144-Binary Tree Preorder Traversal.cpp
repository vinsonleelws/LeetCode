Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]

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

// Recursive
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorderTraversalDFS(root, result);
        return result;
    }
    
    void preorderTraversalDFS(TreeNode* root, vector<int>& result)
    {
        if(!root)
            return;
        else
        {
            result.push_back(root->val);
            if(root->left)
                preorderTraversalDFS(root->left, result);
            if(root->right)
                preorderTraversalDFS(root->right, result);
        }
    }
};

// Iteratively
// #1
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        vector<int> result;
        stack<TreeNode*> nodes;
        nodes.push(root);
        while(nodes.size())
        {
            TreeNode* node = nodes.top();
            nodes.pop();
            result.push_back(node->val);
            if(node->right)
                nodes.push(node->left);
            if(node->left)
                nodes.push(node->right);
        }
        
        return result;
    }
};

// #2
// 下面这种写法使用了一个辅助结点p，这种写法其实可以看作是一个模版，对应的还有中序和后序的模版写法，形式很统一，方便于记忆。辅助结点p初始化为根结点，
// while循环的条件是栈不为空或者辅助结点p不为空，在循环中首先判断如果辅助结点p存在，那么先将p加入栈中，然后将p的结点值加入结果res中，此时p指向其左子结点。
// 否则如果p不存在的话，表明没有左子结点，我们取出栈顶结点，将p指向栈顶结点的右子结点，参见代码如下：
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode *p = root;
        while (!s.empty() || p) {
            if (p) {
                s.push(p);
                res.push_back(p->val);
                p = p->left;
            } else {
                TreeNode *t = s.top(); s.pop();
                p = t->right;
            }
        }
        return res;
    }
};