Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 基于递归的实现：
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTRecursive(nums, 0, nums.size()-1);
    }
    
    TreeNode* sortedArrayToBSTRecursive(vector<int>& nums, int start, int end) {
        if(nums.empty() || start>end)
            return NULL;
        
        int rootIndex = (start+end)>>1;
        TreeNode* root = new TreeNode(nums[rootIndex]);
        root->left = sortedArrayToBSTRecursive(nums, start, rootIndex-1);
        root->right = sortedArrayToBSTRecursive(nums, rootIndex+1, end);
        return root;
    }
};
