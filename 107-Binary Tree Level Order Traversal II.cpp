Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its bottom-up level order traversal as:

[
  [15,7],
  [9,20],
  [3]
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

// 递归解法：
// Recurive
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        levelorder(root, 0, res);
        return vector<vector<int> > (res.rbegin(), res.rend());  // 最后反转
    }
    
    void levelorder(TreeNode *root, int level, vector<vector<int> > &res) {
        if (!root) 
            return;
        if (res.size() == level) 
            res.push_back({});
        res[level].push_back(root->val);
        if (root->left) levelorder(root->left, level + 1, res);
        if (root->right) levelorder(root->right, level + 1, res);
    }
};

// 队列+栈
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
            return {};
        
        stack<vector<int>> s;
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
            s.push(sol);
        }
        
        vector<vector<int>> result;
        while(s.size())
        {
            result.push_back(s.top());
            s.pop();
        }
        return result;
    }
};

// 队列 + insert
// 但由于有insert操作，时间效率不高
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
            result.insert(result.begin(), sol);
        }
        
        return result;
    }
};

// 队列 + rbegin, rend
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
        
        return vector<vector<int>> (result.rbegin(), result.rend());
    }
}; 
