/*Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1

Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
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
	vector<vector<int>> pathSum(TreeNode* root, int sum) {

	}
};


// 二叉树的路径和II (找所有合法路径)  [M]
// DFS


class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		if (!root)
			return {};
		vector<vector<int>> result;
		vector<int> sol;
		pathSumDFS(root, sum, 0, sol, result);
		return result;
	}

	void pathSumDFS(const TreeNode* root, const int& sum, int cursum, vector<int> sol, vector<vector<int>>& result)
	{
		if (!root)
			return;
		else
		{
			cursum += root->val;
			sol.push_back(root->val);
			if (!root->left && !root->right && cursum == sum)
				result.push_back(sol);
			else
			{
				pathSumDFS(root->left, sum, cursum, sol, result);
				pathSumDFS(root->right, sum, cursum, sol, result);
			}
		}
	}
};

// 另一种更简洁的写法：
class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		if (!root)
			return {};
		vector<vector<int>> result;
		vector<int> sol;
		pathSumDFS(root, sum, sol, result);
		return result;
	}

	void pathSumDFS(const TreeNode* root, int sum, vector<int> sol, vector<vector<int>>& result)
	{
		if (!root)
			return;
		else
		{
			sum -= root->val;
			sol.push_back(root->val);
			if (!root->left && !root->right && sum == 0)
				result.push_back(sol);
			else
			{
				pathSumDFS(root->left, sum, sol, result);
				pathSumDFS(root->right, sum, sol, result);
			}
		}
	}
};


// 基于迭代的写法：
// 在中序遍历的基础上记录路径
// 需注意的地方：如果当前最左节点已经是个叶节点了，我们要转移到其他的节点上时需要把当前的节点值减去，而如果当前最左节点不是叶节点，
// 下面还有一个右子节点，这时候移动指针时就不能减去当前节点值，为了区分这两种情况，我们需要用一个额外指针pre来指向前一个节点，如果
// 右子节点存在且不等于pre，我们直接将指针移到右子节点，反之我们更新pre为cur，cur重置为空，val减去当前节点，s删掉最后一个节点.
class Solution {
public:
	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		vector<vector<int>> res;
		vector<TreeNode*> s;
		TreeNode *cur = root, *pre = NULL;
		int val = 0;
		while (cur || !s.empty()) {
			while (cur) {
				s.push_back(cur);
				val += cur->val;
				cur = cur->left;
			}
			cur = s.back();
			if (!cur->left && !cur->right && val == sum) {
				vector<int> v;
				for (auto it : s) {
					v.push_back(it->val);
				}
				res.push_back(v);
			}
			if (cur->right && cur->right != pre) cur = cur->right;
			else {
				pre = cur;
				val -= cur->val;
				s.pop_back();
				cur = NULL;
			}
		}
		return res;
	}
};