Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Iterative
// 基于队列的实现
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size())
        {
            vector<int> sol;
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                sol.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            result.push_back(sol);
        }
        
        return result;
    }
};


// Recursive
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> result;
        levelOrderRecursive(root, 0, result);
        return result;
    }
    
    void levelOrderRecursive(TreeNode* root, int level, vector<vector<int>>& result){
        if(!root)
            return;
        if(result.size() == level)
            result.push_back({});
        result[level].push_back(root->val);
        if(root->left)
            levelOrderRecursive(root->left, level+1, result);
        if(root->right)
            levelOrderRecursive(root->right, level+1, result);
    }
};