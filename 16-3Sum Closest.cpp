Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sum = 0;
        if(nums.size()>=3)
        {
            sort(nums.begin(), nums.end());
            sum = nums[0]+nums[1]+nums[2];
            bool neg_target = false;
            if(target<0)
                neg_target = true;
            for(int i=0; i<nums.size(); i++)
            {
                if(neg_target && nums[i]>=0)
                    break;
                
                if(i>0 && nums[i]==nums[i-1])
                    continue;
                    
                int j=i+1, k=nums.size()-1;
                while(j<k)
                {
                    int curSum = nums[i] + nums[j] + nums[k];
                    if(abs(target-curSum) < abs(target-sum))
                    {
                        if(target == curSum)
                            return curSum;
                        sum = curSum;
                        while(j<k && nums[j] == nums[j+1])
                            j++;
                        while(j<k && nums[k] == nums[k-1])
                            k--;
                        
                        if(curSum<target)
                            j++;
                        else    
                            k--;
                    }
                    else if(curSum<target)
                        j++;
                    else
                        k--;
                }
            }
        }
        
        return sum;
    }
};

// Testing cases:
// Input: [13,2,0,-14,-20,19,8,-5,-13,-3,20,15,20,5,13,14,-17,-7,12,-6,0,20,-19,-1,-15,-2,8,-2,-9,13,0,-3,-18,-9,-9,-19,17,-14,-19,-4,-16,2,0,9,5,-7,-4,20,18,9,0,12,-1,10,-17,-11,16,-13,-14,-3,0,2,-18,2,8,20,-15,3,-13,-12,-2,-19,11,11,-10,1,1,-10,-2,12,0,17,-19,-7,8,-19,-17,5,-5,-10,8,0,-12,4,19,2,0,12,14,-9,15,7,0,-16,-5,16,-12,0,2,-16,14,18,12,13,5,0,5,6]
// -59
// Expected: -58

// Input: [1,2,4,8,16,32,64,128]
// 82
// Expected: 82 (2+16+64)

// Input: [13,2,0,-14,-20,19,8,-5,-13,-3,20,15,20,5,13,14,-17,-7,12,-6,0,20,-19,-1,-15,-2,8,-2,-9,13,0,-3,-18,-9,-9,-19,17,-14,-19,-4,-16,2,0,9,5,-7,-4,20,18,9,0,12,-1,10,-17,-11,16,-13,-14,-3,0,2,-18,2,8,20,-15,3,-13,-12,-2,-19,11,11,-10,1,1,-10,-2,12,0,17,-19,-7,8,-19,-17,5,-5,-10,8,0,-12,4,19,2,0,12,14,-9,15,7,0,-16,-5,16,-12,0,2,-16,14,18,12,13,5,0,5,6]
// Expected: -58