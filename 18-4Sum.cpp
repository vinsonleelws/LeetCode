/* 
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
] 
*/

// 四数之和
// Sort + Tow Pointers or Hash Table

// My solution
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size()<4)
            return result;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++)
        {
            if(i>0 && nums[i]==nums[i-1])   // 先固定一个数
                continue;
            
            for(int j=i+1;j<=nums.size()-2; j++)
            {
                if(j>i+1 && nums[j] == nums[j-1])   // 再固定一个数
                    continue;
                
                int k=j+1;
                int l=nums.size()-1;
                while(k<l)  // 再用双指针夹逼    
                {
                    int sum = nums[i]+nums[j]+nums[k]+nums[l];
                    if(target == sum)
                    {
                        result.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while(j<k && k<l && nums[l] == nums[l-1])
                            l--;
                        while(j<k && k<l && nums[k] == nums[k+1])
                            k++;
                        l--;
                        k++;
                    }
                    else if(sum<target)
                    {
                        k++;
                    }
                    else
                    {
                        l--;
                    }
                }
            }
            
        }
        
        return result;
    }
};


// 另一种解法：Hash Table
// 采用set避免重复项的粗暴解法，比上一个解法慢。
class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < int(nums.size() - 3); ++i) 
        {
            for (int j = i + 1; j < int(nums.size() - 2); ++j) 
            {
                if (j > i + 1 && nums[j] == nums[j - 1]) 
                    continue;
                int left = j + 1, right = nums.size() - 1;
                while (left < right) 
                {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) 
                    {
                        vector<int> out{nums[i], nums[j], nums[left], nums[right]};
                        res.insert(out);
                        ++left; --right;
                    } 
                    else if (sum < target) 
                        ++left;
                    else 
                        --right;
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};


// Testing cases:
// [0]
// 0

// Input: [-3,-2,-1,0,0,1,2,3]
// 0
// Expected: [[-3,-2,2,3],[-3,-1,1,3],[-3,0,0,3],[-3,0,1,2],[-2,-1,0,3],[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]