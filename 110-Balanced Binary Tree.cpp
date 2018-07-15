/*Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

    a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7

Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4

Return false.
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
  bool isBalanced(TreeNode* root) {

  }
};


// 判断是否是平衡二叉树（the depth of the two subtrees of every node never differ by more than 1）
// DFS


// 注意：对于每个非叶子结点产生的子树，都要是平衡的。
// 仍然基于递归实现：
class Solution {
public:
  bool isBalanced(TreeNode* root) {
    if (!root)
      return true;

    int lHeight = height(root->left);
    int rHeight = height(root->right);
    int diff = lHeight - rHeight;
    
    if (-1 > diff || diff > 1)
      return false;
    else
      return isBalanced(root->left) && isBalanced(root->right);
  }

  int height(TreeNode* root)
  {
    if (!root)
      return 0;
    int left = height(root->left);
    int right = height(root->right);

    return left > right ? left + 1 : right + 1;
  }
};