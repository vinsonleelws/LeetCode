/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
    }
};

// 78-幂集  [M]
// DFS


// Reference solution：
class Solution {
public:
	vector<vector<int> > subsets(vector<int> &num) {
		vector<vector<int> > result;
		vector<int> res;
		getSubsets(num, 0, res, result);
		return result;
	}
	
	void getSubsets(const vector<int> &num, int pos, vector<int> &res, vector<vector<int> > &result) {
		result.push_back(res);
		for (int i = pos; i < num.size(); ++i) 
		{
			res.push_back(num[i]);
			getSubsets(num, i + 1, res, result);
			res.pop_back();
		}
	}
};

// 添加的顺序为：
// []
// [1]
// [1 2]
// [1 2 3]
// [1 3]
// [2]
// [2 3]
// [3]


// My solution；
// Beats 100% cpp solutions.
// 基于递归的解法：
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		int n = nums.size();
		vector<int> sol;
		vector<vector<int>> result(1, sol);
		if (n <= 0)
			return result;

		for (int i = 0; i < n; i++)  // 单个数的情况
			result.push_back({nums[i]});

		for (int targetNum = 2; targetNum < n; targetNum++)  // 2~n-1个数分别调用DFS函数构造
		{
			subsetsDFS(nums, 0, targetNum, sol, result);
			sol.clear();
		}

		if (n > 1) // n>1 避免当数组只有一个元素重复添加数组。
			result.push_back(nums);
		return result;
	}

	void subsetsDFS(const vector<int>& nums, int index, const int& targetNum, vector<int>& sol, vector<vector<int>>& result)
	{
		if (sol.size() == targetNum)
			result.push_back(sol);
		else
		{
			for (int i = index; i < nums.size(); i++)
			{
				sol.push_back(nums[i]);
				subsetsDFS(nums, i + 1, targetNum, sol, result);
				sol.pop_back();
			}
		}
	}
};


// 非递归的解法：
// 基本思路：
// 以nums=[1,2,3]为例子说明
// 初始化result为[]，然后每一步如下进行
// [] -> [] [1]
// [] [1] -> [] [1] [2] [1,2]
// [] [1] [2] [1,2] -> [] [1] [2] [1,2] [3] [1,3] [2,3] [1,2,3]

class Solution {
public:
	vector<vector<int> > subsets(vector<int>& nums) {
		vector<vector<int> > result(1);

		for (int i = 0; i < nums.size(); ++i)
		{
			int size = result.size();
			for (int j = 0; j < size; ++j)
			{
				result.push_back(result[j]);
				result.back().push_back(nums[i]);
			}
		}
		return result;
	}
};