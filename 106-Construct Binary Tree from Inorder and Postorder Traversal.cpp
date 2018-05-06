Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]

Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    
    TreeNode *buildTree(vector<int> &inorder, int iLeft, int iRight, vector<int> &postorder, int pLeft, int pRight) 
    {
        if (pLeft > pRight || iLeft > iRight) 
            return NULL;
        int i = 0;
        while(i<=iRight && postorder[pRight] != inorder[i])
            i++;
        
        TreeNode *cur = new TreeNode(postorder[pRight]);
        cur->left = buildTree(inorder, iLeft, i-1, postorder, pLeft, pLeft+i-1-iLeft);
        cur->right = buildTree(inorder, i+1, iRight, postorder, pLeft+i-iLeft, pRight-1);
        return cur;
    }
};
