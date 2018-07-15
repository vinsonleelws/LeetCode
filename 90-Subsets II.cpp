/* 
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
 */

// 幂集II (nums数组中可能包含重复元素，返回所有可能的子集，要求子集不能重复)
// DFS

// DFS
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        if (nums.empty()) 
            return {};
        vector<vector<int>> res;
        vector<int> sol;
        sort(nums.begin(), nums.end());
        getSubsets(nums, 0, sol, res);
        return res;
    }
    void getSubsets(vector<int> &nums, int pos, vector<int> &sol, vector<vector<int>> &res) {
        res.push_back(sol);
        for (int i = pos; i < nums.size(); ++i) 
        {
            sol.push_back(nums[i]);
            getSubsets(nums, i + 1, sol, res);
            sol.pop_back();
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) // 跳过重复元素，相比"78-Subsets"多的一个步骤
                ++i;
        }
    }
};

// My solution:
// 此题在"78-Subsets"基础上改变了条件：nums数组中可能包含重复元素，返回所有可能的子集，要求子集不能重复。
// 基于递归的方法：
// 关键在于跳过重复元素，为此我们需将数组先排序。
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        vector<int> sol;
        vector<vector<int>> result(1, sol);
        if(n<=0)
            return result;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++)
        {
            if(i>0 && nums[i]==nums[i-1])   // 跳过重复元素
                continue;
            result.push_back({nums[i]});
        }
        
        for(int targetNum=2; targetNum<n; targetNum++)
        {
            subsetsWithDupDFS(nums, 0, targetNum, sol, result);
            sol.clear();
        }
        
        if(n>1) // n>1 避免当数组只有一个元素重复添加数组
            result.push_back(nums);
        return result;
    }
    void subsetsWithDupDFS(const vector<int>& nums, int index, const int& targetNum, vector<int>& sol, vector<vector<int>>& result)
    {
        if(sol.size() == targetNum)
            result.push_back(sol);
        else
        {
            for(int i=index; i<nums.size(); i++)
            {
                sol.push_back(nums[i]);
                subsetsWithDupDFS(nums, i+1, targetNum, sol, result);
                sol.pop_back();
                while(i+1<nums.size() && nums[i+1] == nums[i]) // 跳过重复元素
                    i++;
            }
        }
    }
};


// 非递归解法：
// 思路：拿题目中的例子[1 2 2]来分析，根据之前 "78-Subsets 子集合" 里的分析可知，当处理到第一个2时，
// 此时的子集合为[], [1], [2], [1, 2]，而这时再处理第二个2时，如果在[]和[1]后直接加2会产生重复，
// 所以只能在上一个循环生成的后两个子集合后面加2，发现了这一点，题目就可以做了，
// 我们用last来记录上一个处理的数字，然后判定当前的数字和上面的是否相同，若不同，则循环还是从0到当前子集的个数，
// 若相同，则新子集个数减去之前循环时子集的个数当做起点来循环，这样就不会产生重复了
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        if (nums.empty()) return {};
        vector<vector<int>> res(1);
        sort(nums.begin(), nums.end());
        int size = 1, last = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            if (last != nums[i]) {
                last = nums[i];
                size = res.size();
            }
            int newSize = res.size();
            for (int j = newSize - size; j < newSize; ++j) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};