/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]

Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
 */

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
    }
};

// 组合之和（数组中的数字可以重复使用）	 [M]
// Backtracking

// 思路：
// 像这种结果要求返回所有符合要求解的题十有八九都是要利用到递归，而且解题的思路都大同小异，
// 相类似的题目有 Path Sum II 二叉树路径之和之二，Subsets II 子集合之二，Permutations 全排列，
// Permutations II 全排列之二，Combinations 组合项等等，如果仔细研究这些题目发现都是一个套路，
// 都是需要另写一个递归函数，这里我们新加入三个变量，start记录当前的递归到的下标，
// numbers为一个解，result保存所有已经得到的解，每次调用新的递归函数时，此时的target要减去当前数组的的数.

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		if (candidates.empty() || target < 0)
			return result;
		vector<int> numbers;
		combinationSumDFS(candidates, target, 0, numbers, result);
		return result;
	}

	void combinationSumDFS(const vector<int>& candidates, int target, int start, vector<int> numbers, vector<vector<int>>& result) {
		if (target == 0)
			result.push_back(numbers);
		else
		{
			for (int i = start; i < candidates.size(); i++)
			{
				if (candidates[i] <= target)
				{
					numbers.push_back(candidates[i]);
					combinationSumDFS(candidates, target - candidates[i], i, numbers, result);  // i
					numbers.pop_back();
				}
			}
		}
	}
};