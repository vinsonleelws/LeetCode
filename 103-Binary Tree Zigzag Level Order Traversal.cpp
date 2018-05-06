Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
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

// 使用两个栈。Runtime beats 100% of cpp submissions.
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> result;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        bool pushLeftToRight = 1;
        s1.push(root);
        while(s1.size() || s2.size())
        {
            vector<int> sol;
            if(pushLeftToRight)
            {
                int size = s1.size();
                for(int i=0; i<size; i++)
                {
                    TreeNode* node = s1.top();
                    s1.pop();
                    sol.push_back(node->val);
                    if(node->left)
                        s2.push(node->left);
                    if(node->right)
                        s2.push(node->right);
                }
            }
            else
            {
                int size = s2.size();
                for(int i=0; i<size; i++)
                {
                    TreeNode* node = s2.top();
                    s2.pop();
                    sol.push_back(node->val);
                    if(node->right)
                        s1.push(node->right);
                    if(node->left)
                        s1.push(node->left);
                }
            }
            result.push_back(sol);
            pushLeftToRight = !pushLeftToRight;
        }
        return result;
    }
};