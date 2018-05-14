Given a sorted integer array without duplicates, return the summary of its ranges.

Example 1:

Input:  [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.

Example 2:

Input:  [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.

// My solution: Runtime beats 100% of cpp submissions.
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.empty())
            return {};
        
        vector<string> result;
        int l=nums[0], r=nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i]-1 == nums[i-1])
                r = nums[i];
            else
            {
                if(l==r)
                    result.push_back(to_string(l));
                else
                    result.push_back(to_string(l)+"->"+to_string(r));
                
                l = r= nums[i];
            }
                
        }
        
        if(l!=r)
            result.push_back(to_string(l)+"->"+to_string(r));
        else
            result.push_back(to_string(l));
        
        return result;
    }
};


// 其它解法：
// 使用两个变量i和j，其中i是连续序列起始数字的位置，j是连续数列的长度，当j为1时，说明只有一个数字，若大于1，则是一个连续序列。
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int i = 0, n = nums.size();
        while (i < n) {
            int j = 1;
            while (i + j < n && nums[i + j] - nums[i] == j) 
                ++j;
            res.push_back(j <= 1 ? to_string(nums[i]) : to_string(nums[i]) + "->" + to_string(nums[i + j - 1]));
            i += j;
        }
        return res;
    }
};