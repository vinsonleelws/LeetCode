Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6

The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

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
// #1
// Recursion
// 思路：先找到最左子节点，然后回到其父节点，把其父节点和右子节点断开，将原左子结点连上父节点的右子节点上，然后再把原右子节点连到新右子节点的右子节点上，然后再回到上一父节点做相同操作。
class Solution {
public:
    void flatten(TreeNode *root) {
        if (!root) 
            return;
        if (root->left) 
            flatten(root->left);
        if (root->right) 
            flatten(root->right);
        TreeNode *tmp = root->right;
        root->right = root->left;
        root->left = NULL;
        while (root->right) 
            root = root->right;
        root->right = tmp;
    }
};

// 例如，对于下面的二叉树，上述算法的变换的过程如下：

     1
    / \
   2   5
  / \   \
 3   4   6

     1
    / \
   2   5
    \   \
     3   6
      \    
       4

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
             
// #2
// 非迭代版本的实现：
// 从根节点开始出发：
// 1）若左结点存在，则找到该左结点的最右结点，将其右孩子设置为根结点的右孩子，再把根节点的右孩子设置为其左孩子，同时根节点左孩子置空。
// 2）更新根节点为其右孩子。
// Non-recursion
class Solution {
public:
    void flatten(TreeNode *root) {
        TreeNode *cur = root;
        while (cur) {
            if (cur->left) {
                TreeNode *p = cur->left;
                while (p->right) p = p->right;
                p->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
};

// 例如，对于下面的二叉树，上述算法的变换的过程如下：

     1
    / \
   2   5
  / \   \
 3   4   6

   1
    \
     2
    / \
   3   4
        \
         5
          \
           6
           
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6


// #3
// 基于前序遍历的迭代解法如下：
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *t = s.top(); s.pop();
            if (t->left) {
                TreeNode *r = t->left;
                while (r->right) r = r->right;
                r->right = t->right;
                t->right = t->left;
                t->left = NULL;
            }
            if (t->right) s.push(t->right);
        }
    }
};