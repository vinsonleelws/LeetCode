/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
 */

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

    }
};

// 组合之和II (数字不能重复使用)    [M]
// Backtracking

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        if (candidates.empty() || target < candidates[0])
            return result;
        vector<int> numbers;
        combinationSumDFS(candidates, target, 0, numbers, result);
        return result;
    }

    void combinationSumDFS(vector<int>& candidates, int target, int start, vector<int> numbers, vector<vector<int>>& result) {
        if (target == 0)
            result.push_back(numbers);
        else
        {
            for (int i = start; i < candidates.size(); i++)
            {
                if (i > start && candidates[i] == candidates[i - 1]) // 跳过重复数字
                    continue;
                if (candidates[i] <= target)
                {
                    numbers.push_back(candidates[i]);
                    combinationSumDFS(candidates, target - candidates[i], i + 1, numbers, result); // i+1，避免重复
                    numbers.pop_back();
                }
                else  // 因为是排序的，数字递增，可提前终止
                    return;
            }
        }
    }
};