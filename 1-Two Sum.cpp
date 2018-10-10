//==================================================================
// LeetCode  
// 1-two-sum
// Author：wsli
//==================================================================

// Problem:
// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// Example:
// Given nums = [2, 7, 11, 15], target = 9,
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].


#include <unordered_map>
#include <vector>
#include <time.h>
#include <iostream>
#include <exception>

using std::vector;

// Approach 2 (Hash Table)	[E]
// Time complexity: O(n), Space complexity: O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.size() < 2)
            return {};
		unordered_map<int, int> mapping;
		for(unsigned int i=0; i<nums.size(); i++)
		{
			int value = target - nums[i];
			if(mapping.count(value))
				return {mapping[value] , int(i)};
			mapping.emplace(nums[i], int(i));
		}
		return {-1, -1};
    }
};

// Approach 1 (Brute Force)
// Time complexity: O(n^2)
/* class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(unsigned i=0; i<nums.size()-1; i++)
            for(unsigned j=i+1; j<nums.size(); j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    vector<int> solution;
                    solution.push_back(i);
                    solution.push_back(j);
                    return solution;
                }
            }
    }
}; */

/**********************************Testing Code **********************************/

int main()
{
	clock_t start, end;
	Solution s;
	vector<int> nums{2, 7, 11, 15};
	start = clock();
	if((s.twoSum(nums, 13) == std::vector<int>{0, 2}))
		std::cout<<"[Info] Testing passed.\n";
	else	
		std::cout<<"[Info] Error: not passed.\n";
	end = clock();
	double timeuse = (double)((end - start)*1000000.0/CLOCKS_PER_SEC); 
	std::cout<<"\nExecution time: "<<timeuse<<" ms\n\n";
	return 0;
}