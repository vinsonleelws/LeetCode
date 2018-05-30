Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example:

Input: 
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 完全二叉树：若设二叉树的深度为h，除第 h 层外，其它各层 (1～h-1) 的结点数都达到最大个数，第 h 层所有的结点都连续集中在最左边。
// 满二叉树：除最后一层无任何子节点外，每一层上的所有结点都有两个子结点。如果一个满二叉树的层数为h，则其结点总数是(2^h) -1 

// 由于完全二叉树有可能是满二叉树，若是满二叉树，节点个数很好求，为(2^h)-1，h该满二叉树的高度。
// 思路是分别找出以当前节点为根节点的左子树和右子树的高度并对比，如果相等，则说明是满二叉树，
// 直接根据计算公式返回节点个数，如果不相等，则节点个数为左子树的节点个数加上右子树的节点个数
// 再加1(根节点)，其中左右子树节点个数的计算可以使用递归来计算

// Reference solution:
class Solution {
public:
    int countNodes(TreeNode* root) {
        int hLeft = 0, hRight = 0;
        TreeNode *pLeft = root, *pRight = root;
        while (pLeft) 
        {
            ++hLeft;
            pLeft = pLeft->left;
        }
        while (pRight) 
        {
            ++hRight;
            pRight = pRight->right;
        }
        if (hLeft == hRight) 
            return pow(2, hLeft) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

// 另一种写法：
class Solution {
public:
    int countNodes(TreeNode* root) {
        int hLeft = leftHeight(root);
        int hRight = rightHeight(root);
        if (hLeft == hRight) return pow(2, hLeft) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
    
    int leftHeight(TreeNode* root) {
        if (!root) return 0;
        return 1 + leftHeight(root->left);
    }
    
    int rightHeight(TreeNode* root) {
        if (!root) return 0;
        return 1 + rightHeight(root->right);
    }
};

// Other
// 若简单实用二叉树遍历来计算结点数，将通不过OJ的最后一个测例而报TLE
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int result = 0;
        countNodesDFS(root, result);
        return result;
    }
    
    void countNodesDFS(const TreeNode* root, int& result)
    {
        if(!root)
            return;
        
        result++;
        if(root->left)
            countNodesDFS(root->left, result);
        if(root->right)
            countNodesDFS(root->right, result);
    }
};