/* 
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]

Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
   
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
    }
};


// 由先序和中序遍历建立二叉树
// DFS
 
// My solution
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty() || preorder.size()!=inorder.size())
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[0]);
        int i=0;
        while(i<inorder.size() && inorder[i]!=preorder[0]) // 确定左子树结点数
            i++;
        
        vector<int> preorderLeftPart, preorderRightPart, inorderLeftPart, inorderRightPart;
        if(i>=1)   
        {
            preorderLeftPart.assign(preorder.begin()+1, preorder.begin()+i+1);  // 注意这里last iterator应是正确下标值+1
            inorderLeftPart.assign(inorder.begin(), inorder.begin()+i);  // 注意这里last iterator应是正确下标值+1
        }
        
        if(i+1 < preorder.size())
        {
            preorderRightPart.assign(preorder.begin()+i+1, preorder.end());
            inorderRightPart.assign(inorder.begin()+i+1, inorder.end());
        }
        
        root->left = buildTree(preorderLeftPart, inorderLeftPart);
        root->right = buildTree(preorderRightPart, inorderRightPart);
        
        return root;
    }
};

// 另外一种写法：
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    
    TreeNode *buildTree(vector<int> &preorder, int pLeft, int pRight, vector<int> &inorder, int iLeft, int iRight) 
    {
        if (pLeft > pRight || iLeft > iRight) 
            return NULL;
        
        int i = iLeft;
        while(i<=iRight && preorder[pLeft] != inorder[i])
            i++;
        
        TreeNode *cur = new TreeNode(preorder[pLeft]);
        cur->left = buildTree(preorder, pLeft + 1, pLeft + i - iLeft, inorder, iLeft, i - 1);  // i-iLeft 是因为inorder tree是从数组的iLeft开始的
        cur->right = buildTree(preorder, pLeft + i - iLeft + 1, pRight, inorder, i + 1, iRight);
        return cur;
    }
};
