/*Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
    }
};


// 全排列II (含重复项)
// Sort + DFS (Backtracking) + visit数组


// 避免重复的产生，在递归函数中要判断前面一个数和当前的数是否相等，如果相等，
// 前面的数必须已经使用了，即对应的iFlag中的值为1，当前的数字才能使用，
// 否则需要跳过，这样就不会产生重复排列了。

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<bool> iFlag(nums.size(), 0);
        vector<int> res;
        sort(nums.begin(), nums.end());
        permutations(nums, nums.size(), iFlag, res, result);
        return result;
    }
    
    void permutations(vector<int>& nums, int level, vector<bool> iFlag, vector<int>& res, vector<vector<int>>& result)
    {
        if(level==0)
            result.push_back(res);
        else
            for(int i=0; i<nums.size(); i++)
            {   
                if(i>0 && nums[i]==nums[i-1] && !iFlag[i-1])
                    continue;
                if(!iFlag[i])
                {
                    res.push_back(nums[i]);
                    iFlag[i] = true;
                    permutations(nums, level-1, iFlag, res, result);
                    res.pop_back();
                    iFlag[i] = false;
                }
            }
    }
};