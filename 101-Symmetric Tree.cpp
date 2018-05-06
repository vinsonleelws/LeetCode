Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3

Note:
Bonus points if you could solve it both recursively and iteratively.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Recursively
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        
        return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode* l, TreeNode* r)
    {
        if(!l && !r)
            return true;
            return true;
        else if(!l && r || l && !r || l->val!=r->val)
            return false;
        
        return isSymmetric(l->left, r->right) && isSymmetric(l->right, r->left);
    }
};

// Iteratively
// 用两个队列来实现，分别保存根节点左子树各结点的值和右子树各结点的值
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        
        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        
        while(q1.size() && q2.size())
        {
            TreeNode* l = q1.front();
            TreeNode* r = q2.front();
            q1.pop();
            q2.pop();
            if(l && !r || !l && r)
                return false;
            
            if(l && r)
            {
                if(l->val != r->val)
                    return false;
                q1.push(l->left);
                q1.push(l->right);
                q2.push(r->right);
                q2.push(r->left);
            }
        }
        return true;
    }
};