/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
    }
};

// 搜索目标值的起始和结束位置	[M]
// Binary Search

// Reference solution:
// 使用两次二分查找法，第一次找到左边界，第二次调用找到右边界
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> result(2, -1);
		if (nums.empty())
			return result;
		int left = 0, right = nums.size() - 1;

		while (left < right) // 使right指向最左边的目标值 （二分查找返回key(可能有重复)第一次出现的下标）
		{
			int mid = (left + right) / 2;	
			if (nums[mid] < target)	// <
				left = mid + 1;
			else
				right = mid;
		}

		if (nums[right] != target)
			return result;

		result[0] = right;
		right = nums.size();
		while (left < right)  // 使left指向最右边的目标值的右边的一个数
		{
			int mid = (left + right) / 2;
			if (nums[mid] <= target)  // <=
				left = mid + 1;
			else
				right = mid;
		}
		result[1] = left - 1;
		return result;
	}
};

// My solution.
// 基于两次二分查找
// 特别考虑：数字在头和/或尾的情况
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.empty())
			return { -1, -1};

		vector<int> result;
		int start = 0;
		int end = nums.size() - 1;
		int mid = (start + end) >> 1;
		while (start <= end)  // 找左边界
		{
			if (nums[mid] == target)
			{
				if (mid >= 1 && nums[mid - 1] != target || mid == 0)
				{
					result.push_back(mid);
					break;
				}
				else
					end = mid - 1;
			}
			else if (nums[mid] < target)
				start = mid + 1;
			else
				end = mid - 1;

			mid = (start + end) >> 1;
		}

		if (result.empty())
			return { -1, -1};

		start = result[0];
		end = nums.size() - 1;
		mid = (start + end) >> 1;
		while (start <= end)  // 找右边界
		{
			if (nums[mid] == target)
			{
				if (mid < nums.size() - 1 && nums[mid + 1] != target || mid == nums.size() - 1)
				{
					result.push_back(mid);
					break;
				}
				else
					start = mid + 1;
			}
			else if (nums[mid] < target)
				start = mid + 1;
			else
				end = mid - 1;

			mid = (start + end) >> 1;
		}

		return result;
	}
};