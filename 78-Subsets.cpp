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

// 78-幂集
// DFS

// My solution；
// Beats 100% cpp solutions.
// 基于递归的解法：
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int> sol;
        vector<vector<int>> result(1, sol);
        if(n<=0)
            return result;
        
        for(int i=0; i<n; i++)
            result.push_back({nums[i]});
        
        for(int targetNum=2; targetNum<n; targetNum++)
        {
            subsetsDFS(nums, 0, targetNum, sol, result);
            sol.clear();
        }
        
        if(n>1) // n>1 避免当数组只有一个元素重复添加数组。
            result.push_back(nums);
        return result;
    }
    
    void subsetsDFS(const vector<int>& nums, int index, const int& targetNum, vector<int>& sol, vector<vector<int>>& result)
    {
        if(sol.size() == targetNum)
            result.push_back(sol);
        else
        {
            for(int i=index; i<nums.size(); i++)
            {
                sol.push_back(nums[i]);
                subsetsDFS(nums, i+1, targetNum, sol, result);
                sol.pop_back();
            }
        }
    }
};

// 另一种写法：
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &num) {
        vector<vector<int> > res;
        vector<int> out;
        getSubsets(num, 0, out, res);
        return res;
    }
    void getSubsets(vector<int> &num, int pos, vector<int> &out, vector<vector<int> > &res) {
        res.push_back(out);
        for (int i = pos; i < num.size(); ++i) {
            out.push_back(num[i]);
            getSubsets(num, i + 1, out, res);
            out.pop_back();
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