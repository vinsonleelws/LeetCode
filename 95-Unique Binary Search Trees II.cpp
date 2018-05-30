Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

   
   
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// 这道题是"96-Unique Binary Search Trees"独一无二的二叉搜索树的延伸，之前那个只要求算出所有不同的二叉搜索树的个数，
// 这道题让把那些二叉树都建立出来。这种建树问题一般来说都是用递归来解，这道题也不例外，划分左右子树，递归构造。

// 构建BST的基本原则：
// 当数组为 1，2，3，4，.. i，.. n时，基于以下原则的BST建树具有唯一性：
// 以i为根节点的树，其左子树由[0, i-1]构成， 其右子树由[i+1, n]构成。

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) 
            return {};
        return *generateTreesDFS(1, n);
    }
    
    vector<TreeNode*> *generateTreesDFS(int start, int end) {
        vector<TreeNode*> *subTree = new vector<TreeNode*>();
        if (start > end) 
            subTree->push_back(NULL);
        else 
        {
            for (int i = start; i <= end; ++i) // i is the root node value.
            {
                vector<TreeNode*> *leftSubTree = generateTreesDFS(start, i - 1);
                vector<TreeNode*> *rightSubTree = generateTreesDFS(i + 1, end);
                for (int j = 0; j < leftSubTree->size(); ++j) 
                {
                    for (int k = 0; k < rightSubTree->size(); ++k) 
                    {
                        TreeNode *node = new TreeNode(i);
                        node->left = (*leftSubTree)[j];
                        node->right = (*rightSubTree)[k];
                        subTree->push_back(node);
                    }
                }
            }
        }
        return subTree;
    }
};