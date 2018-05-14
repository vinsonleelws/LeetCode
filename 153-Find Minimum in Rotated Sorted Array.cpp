Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2] 
Output: 1

Example 2:

Input: [4,5,6,7,0,1,2]
Output: 0

// 这道题简化了难度，明确告诉我们没有重复项在数组里面，因此，我们可以不用考虑这种特殊情况。
// 基于二分查找。
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        int n=nums.size();
        if(nums[0]<=nums[n-1])
            return nums[0];
        int start = 0, end = n-1;
        while(nums[start] >= nums[end])
        {
            if(start == end-1)
                return nums[end];
            int mid = (start+end)>>1;
            if(nums[mid]>=nums[start])
                start = mid;
            else if(nums[mid] <= nums[end])
                end = mid;
        }
        return 0;
    }
};

// 另一种写法：
class Solution {
public:
    int findMin(vector<int> &num) {
        int left = 0, right = num.size() - 1;
        if (num[left] > num[right]) 
        {
            while(left != (right - 1)) 
            {
                int mid = (left + right) / 2;
                if (num[left] < num[mid]) 
                    left = mid;
                else 
                    right = mid;
            }
            return min(num[left], num[right]);
        }
        return num[0];
    }
};