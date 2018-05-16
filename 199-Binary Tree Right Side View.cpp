Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 这道题实际上可以转化为二叉树层次遍历的变种，在基于队列的实现中，每次将孩子从左到右依次入队，对每一层，取出队列中最后一个元素的值保存到结果中即可。
// My solution: Runtime beats 100% of cpp submissions.
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        
        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size())
        {
            TreeNode* node = q.back();
            result.push_back(node->val);
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                node = q.front();
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        
        return result;
    }
};