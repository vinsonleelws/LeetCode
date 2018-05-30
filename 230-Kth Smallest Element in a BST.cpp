Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:

Input: root = [3,1,4,null,2], k = 1
Output: 1

Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

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
// 基于二叉树的中序遍历的递归方法：
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return kthSmallestDFS(root, k);
    }
    int kthSmallestDFS(TreeNode* root, int &k) {
        if (!root) 
            return -1;
        int val = kthSmallestDFS(root->left, k);
        if (k == 0) 
            return val;
        if (--k == 0) 
            return root->val;
        return kthSmallestDFS(root->right, k);
    }
};

// 另一种写法：
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root || k<=0)
            return -1;
        return kthSmallestDFS(root, k);
    }
    int kthSmallestDFS(TreeNode* root, int &k) {
        int val = -1;
        if(root->left)
            val = kthSmallestDFS(root->left, k);
        
        if (k == 0) 
            return val;
        if (--k == 0) 
            return root->val;
        
        if(root->right)
            val = kthSmallestDFS(root->right, k);
        
        return val;
    }
};

// #2
// 非递归方法：
// 使用一个计数变量，每遍历一个结点，计数器自增1，当计数器到达k时，返回当前结点值即可
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        stack<TreeNode*> s;
        TreeNode *p = root;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            p = s.top(); s.pop();
            ++cnt;
            if (cnt == k) return p->val;
            p = p->right;
        }
        return 0;
    }
};

// #3
// 一种分治法的思路，由于BST的性质，我们可以快速定位出第k小的元素是在左子树还是右子树，我们首先计算出左子树的结点个数总和cnt，
// 如果k小于等于左子树结点总和cnt，说明第k小的元素在左子树中，直接对左子结点调用递归即可。如果k大于cnt+1，说明目标值在右子树中，
// 对右子结点调用递归函数，注意此时的k应为k-cnt-1，应为已经减少了cnt+1个结点。如果k正好等于cnt+1，说明当前结点即为所求，返回当前结点值即可。
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = count(root->left);
        if (k <= cnt) {
            return kthSmallest(root->left, k);
        } else if (k > cnt + 1) {
            return kthSmallest(root->right, k - cnt - 1);
        }
        return root->val;
    }
    int count(TreeNode* node) {
        if (!node) return 0;
        return 1 + count(node->left) + count(node->right);
    }
};


// 这道题的Follow up中说假设该BST被修改的很频繁，而且查找第k小元素的操作也很频繁，问我们如何优化。其实最好的方法还是像上面的解法那样利用分治法
// 来快速定位目标所在的位置，但是每个递归都遍历左子树所有结点来计算个数的操作并不高效，所以我们应该修改原树结点的结构，使其保存包括当前结点和其
// 左右子树所有结点的个数，这样我们使用的时候就可以快速得到任何左子树结点总数来帮我们快速定位目标值了。定义了新结点结构体，然后就要生成新树，还
// 是用递归的方法生成新树，注意生成的结点的count值要累加其左右子结点的count值。然后在求第k小元素的函数中，我们先生成新的树，然后调用递归函数。
// 在递归函数中，不能直接访问左子结点的count值，因为左子节结点不一定存在，所以我们先判断，如果左子结点存在的话，那么跟上面解法的操作相同。如果
// 不存在的话，当此时k为1的时候，直接返回当前结点值，否则就对右子结点调用递归函数，k自减1.
// Follow up
class Solution {
public:
    struct MyTreeNode {
        int val;
        int count;
        MyTreeNode *left;
        MyTreeNode *right;
        MyTreeNode(int x) : val(x), count(1), left(NULL), right(NULL) {}
    };
    
    MyTreeNode* build(TreeNode* root) {
        if (!root) return NULL;
        MyTreeNode *node = new MyTreeNode(root->val);
        node->left = build(root->left);
        node->right = build(root->right);
        if (node->left) node->count += node->left->count;
        if (node->right) node->count += node->right->count;
        return node;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        MyTreeNode *node = build(root);
        return helper(node, k);
    }
    
    int helper(MyTreeNode* node, int k) {
        if (node->left) {
            int cnt = node->left->count;
            if (k <= cnt) {
                return helper(node->left, k);
            } else if (k > cnt + 1) {
                return helper(node->right, k - 1 - cnt);
            }
            return node->val;
        } else {
            if (k == 1) return node->val;
            return helper(node->right, k - 1);
        }
    }
};
