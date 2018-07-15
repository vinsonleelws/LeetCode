/*Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1

return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {

    }
};


// 二叉树的路径和
// DFS


class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return hasPathSumDFS(root, sum, 0);
    }

    bool hasPathSumDFS(const TreeNode* root, const int& sum, int cursum) {
        if (!root)
            return false;
        else
        {
            cursum += root->val;
            if (!root->left && !root->right && cursum == sum)
                return true;
            else
                return hasPathSumDFS(root->left, sum, cursum) || hasPathSumDFS(root->right, sum, cursum);
        }
    }

};

// 另一种更简洁的写法：
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root)
            return false;
        if (!root->left && !root->right && root->val == sum )
            return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};