/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2

Example 2:

Input: [1,3,5,6], 2
Output: 1

Example 3:

Input: [1,3,5,6], 7
Output: 4

Example 4:

Input: [1,3,5,6], 0
Output: 0
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

    }
};

// 搜素插入的位置  [E]
// Binary Search

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty())
            return 0;

        int start = 0;
        int end = nums.size() - 1;
        while (start <= end)
        {
            int mid = (start + end) >> 1;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return start;  // 由于总是插入第一个>=目标数字的数字的所在位置，返回start而不是end
    }
};