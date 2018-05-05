Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2

Example 2:

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3

Follow up:

    A solution using O(n) space is pretty straight forward.
    Could you devise a constant space solution?

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// Reference solution:
// #1 空间复杂度为O(n)的直接解法:
// 基于中序遍历，将所有节点存到一个一维向量中，并把所有节点值存到另一个一维向量中，然后对存节点值的一维向量排序，再将排好的数组按顺序赋给节点。
// (这种最一般的解法可针对任意个数目的节点错乱的情况。)
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> list;
        vector<int> vals;
        inorder(root, list, vals);
        sort(vals.begin(), vals.end());
        for (int i = 0; i < list.size(); ++i) {
            list[i]->val = vals[i];
        }
    }
    
    void inorder(TreeNode *root, vector<TreeNode*> &list, vector<int> &vals) {
        if (!root) return;
        inorder(root->left, list, vals);
        list.push_back(root);
        vals.push_back(root->val);
        inorder(root->right, list, vals);
    }
};

// #2 空间复杂度为O(1)的解法
// 基于线索二叉树
// 使用辅助变量parent来保存中序遍历当前结点的上一个结点，用于比较当前节点值和其前一节点值的大小。
// 分别用first和second记录待交换的两个结点。具体地，fisrt和second初始化为NULL, 当parent->val > cur->val时。
// 如果fisrt==NULL, 更新fisrt为parent，而直接更新second为cur。
// 最后交换这两个结点的值。

class Solution {
public:
    void recoverTree(TreeNode *root) {
        TreeNode *first = NULL, *second = NULL, *parent = NULL;
        TreeNode *cur, *pre;
        cur = root;
        while(cur) 
        {
            if (!cur->left) 
            {
                if (parent && parent->val > cur->val) 
                {
                    if (!first) 
                        first = parent;
                    second = cur;
                }
                parent = cur;
                cur = cur->right;
            } 
            else 
            {
                pre = cur->left;
                while (pre->right && pre->right != cur) 
                    pre = pre->right;
                if (!pre->right) 
                {
                    pre->right = cur;
                    cur = cur->left;
                } 
                else 
                {
                    pre->right = NULL;
                    if (parent->val > cur->val) 
                    {
                        if (!first) 
                            first = parent;
                        second = cur;
                    }
                    parent = cur;
                    cur = cur->right;
                }
            }
        }
        if (first && second) 
            swap(first->val, second->val);
    }
};