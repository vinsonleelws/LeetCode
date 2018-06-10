/* Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1 */

// 在旋转有序数组中搜索
// Binary Search

// 思路：基于二分查找，根据旋转数组的性质，进一步细化更新左右端点的条件

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())
            return -1;
        
        if(nums.size()==1 && target == nums[0])
            return 0;
     
        int start = 0;
        int end = nums.size()-1;
        while(start<=end)
        {
            int mid = (start+end)>>1;
            if(target==nums[mid])
                return mid;
            else if(nums[mid]>nums[end])
            {        
                if(nums[mid]>target && nums[start]<=target)
                    end = mid-1;
                else
                    start = mid+1;
            }
            else
            {
                if(nums[mid]<target && nums[end]>=target)
                    start = mid+1;
                else
                    end = mid-1;
            }
        }
        
        return -1;
    }
};