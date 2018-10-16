/*Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

Example 1:

Input:
    2
   / \
  1   3
Output: true

Example 2:

    5
   / \
  1   4
     / \
    3   6
Output: false
Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
             is 5 but its right child's value is 4.*/

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
	bool isValidBST(TreeNode* root) {

	}
};


// 验证二叉搜索树  [M]
// DFS ; Binary tree inorder traversal


// Reference solution:
// #1
// 递归法，利用BST本身的性质来做：左<根<右
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return isValidBST(root, LONG_MIN, LONG_MAX);
	}

	bool isValidBST(TreeNode* root, long min, long max)
	{
		if (!root)
			return true;

		if (root->val <= min || root->val >= max)
			return false;
		else
			return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
	}
};



// #2
// 基于中序遍历的方法：
// 这题实际上简化了难度，因为一般的二叉搜索树是左<=根<右，而这道题设定为左<根<右，那么就可以用中序遍历来做。
// 因为如果不去掉左=根这个条件的话，那么下边两个数用中序遍历无法区分：

20       20
/          \
20           20

// 它们的中序遍历结果都一样，但是左边的是BST，右边的不是BST。去掉等号的条件则相当于去掉了这种限制条件。
// 下面我们来看使用中序遍历来做，这种方法思路很直接，通过中序遍历将所有的节点值存到一个数组里，然后再判断这个数组是不是有序的。
class Solution {
public:
	bool isValidBST(TreeNode *root) {
		if (!root)
			return true;
		vector<int> vals;
		inorder(root, vals);
		for (int i = 0; i < vals.size() - 1; ++i)
			if (vals[i] >= vals[i + 1])
				return false;
		return true;
	}

	void inorder(TreeNode *root, vector<int> &vals)
	{
		if (!root)
			return;
		inorder(root->left, vals);
		vals.push_back(root->val);
		inorder(root->right, vals);
	}
};

// 下面这种解法跟上面那个很类似，都是用递归的中序遍历，但不同之处是不将遍历结果存入一个数组遍历完成再比较，
// 而是每当遍历到一个新节点时和其上一个节点比较，如果不大于上一个节点那么则返回false，全部遍历完成后返回true。
// Still recursion
class Solution {
public:
	TreeNode *pre;
	bool isValidBST(TreeNode *root) {
		int res = 1;
		pre = NULL;
		inorder(root, res);
		if (res == 1)
			return true;
		else
			return false;
	}
	void inorder(TreeNode *root, int &res) {
		if (!root)
			return;
		inorder(root->left, res);
		if (!pre)
			pre = root;
		else
		{
			if (root->val <= pre->val)
				res = 0;
			pre = root;
		}
		inorder(root->right, res);
	}
};