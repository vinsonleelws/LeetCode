/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle. */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

    }
};

// 53-最大子序列和  [E]
// DP, Greedy; Divide and Conquer

// O(n) solution
// Greedy approach
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, curSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            curSum = max(nums[i], curSum + nums[i]);
            if (curSum > maxSum)
                maxSum = curSum;
        }
        return maxSum;
    }
};

// Divide and conquer approach
// 基本思路：
// 这个分治法的思想就类似于二分搜索法，我们需要把数组一分为二，分别找出左边和右边的最大子数组之和，
// 然后还要从中间开始向左右分别扫描，求出的最大值分别和左右两边得出的最大值相比较取最大的那一个.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty())
            return 0;

        return maxSubArrayDC(0, nums.size() - 1, nums);
    }
    int maxSubArrayDC(int left, int right, vector<int>& nums)
    {
        if (left >= right)
            return nums[left];
        else
        {
            int mid = (left + right) >> 1;
            int maxLeft = maxSubArrayDC(left, mid - 1, nums);
            int maxRight = maxSubArrayDC(mid + 1, right, nums);
            int maxMid = sum = nums[mid];
            for (int l = mid - 1; l >= left; l--)
            {
                sum += nums[l];
                maxMid = max(maxMid, sum);
            }
            sum = maxMid;
            for (int r = mid + 1; r <= right; r++)
            {
                sum += nums[r];
                maxMid = max(maxMid, sum);
            }

            return max(maxMid, max(maxLeft, maxRight));
        }
    }
};