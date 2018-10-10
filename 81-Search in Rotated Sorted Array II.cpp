/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true

Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false

Follow up:

    This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
    Would this affect the run-time complexity? How and why?
     */

// 在旋转有序数组中搜索II  [M]
// Binary Search

// 这道是之前 "33-Search in Rotated Sorted Array" 在旋转有序数组中搜索的延伸，现在数组中允许出现重复数字，
// 这个也会影响我们选择哪半边继续搜索，由于之前那道题不存在相同值，我们在比较中间值和最右值时就完全
// 符合之前所说的规律：如果中间的数小于最右边的数，则右半段是有序的，若中间数大于最右边数，则左半段是有序的。
// 而如果可以有重复值，就会出现来面两种情况，[3 1 1] 和 [1 1 3 1]，对于这两种情况中间值等于最右值时，目标值3既可以在左边又可以在右边.
// 其实对于这种情况其实处理非常简单，只要把最右值向左一位(自减1)即可继续循环，如果还相同则继续移，直到移到不同值为止，
// 然后其他部分还采用 "33-Search in Rotated Sorted Array" 在旋转有序数组中搜索中的方法。

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		if (nums.empty())
			return false;

		int start = 0;
		int end = nums.size() - 1;
		while (start <= end)
		{
			int mid = (start + end) >> 1;
			if (nums[mid] == target)
				return true;
			else if (nums[mid] < nums[end])
			{
				if (nums[end] >= target && nums[mid] < target)
					start = mid + 1;
				else
					end = mid - 1;
			}
			else if (nums[mid] > nums[end])
			{
				if (nums[start] <= target && nums[mid] > target)
					end = mid - 1;
				else
					start = mid + 1;
			}
			else // 重点在这个else
				end--;
		}

		return false;
	}
};

// Corner case:
// [0,0,1,0]    // 若有重复元素，当中间元素等于最右边元素时，目标数有可能在左边也有可能在右边
// [1,0,0,0]
