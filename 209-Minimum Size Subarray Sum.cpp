/*
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example:

Input: [2,3,1,2,4,3], s = 7
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.

Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).

*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {

    }
};

// 给定一个目标和，求连续子数组的最小长度  [M]
// Two Pointers ; Binery Search

// 双指针
// 时间复杂度O(n)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty())
            return 0;

        int n = nums.size();
        int left = 0, right = 0, sum = 0, len = n + 1;
        while (right < n)
        {
            while (right < n && sum < s)
                sum += nums[right++];

            while (sum >= s)
            {
                len = min(right - left, len); // 注意这里是right-left而不是right-left+1，因为right比实际加到sum里的数的下标多1
                sum -= nums[left++];
            }
        }

        if (len == n + 1)
            return 0;
        else
            return len;
    }
};

// 另一种写法
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty())
            return 0;

        int n = nums.size();
        int left = 0, right = 0, sum = 0, len = n + 1;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            while (left <= i && sum >= s)
            {
                len = min(i - left + 1, len);
                sum -= nums[left++];
            }
        }
        if (len == n + 1)
            return 0;
        else
            return len;
    }
};


// 时间复杂度为O(nlogn)的解法：
// 基于二分查找
// 思路：建立一个比原数组长一位的sums数组，其中sums[i]表示nums数组中[0, i - 1]的和，然后我们对于sums中每一个值sums[i]，
// 用二分查找法找到子数组的右边界位置，使该子数组之和大于sums[i] + s，然后更新最短长度的距离。
// O(nlgn)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size(), sums[len + 1] = {0}, res = len + 1;
        for (int i = 1; i < len + 1; ++i)
            sums[i] = sums[i - 1] + nums[i - 1];
        for (int i = 0; i < len + 1; ++i)
        {
            int right = searchRight(i + 1, len, sums[i] + s, sums);
            if (right == len + 1)
                break;
            if (res > right - i)
                res = right - i;
        }
        return res == len + 1 ? 0 : res;
    }
    int searchRight(int left, int right, int key, int sums[]) {
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (sums[mid] >= key)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};

// 另一种写法：可以不用为二分查找法专门写一个函数，直接嵌套在for循环中即可
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int res = INT_MAX, n = nums.size();
        vector<int> sums(n + 1, 0);
        for (int i = 1; i < n + 1; ++i) sums[i] = sums[i - 1] + nums[i - 1];
        for (int i = 0; i < n; ++i) {
            int left = i + 1, right = n, t = sums[i] + s;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (sums[mid] < t) left = mid + 1;
                else right = mid - 1;
            }
            if (left == n + 1) break;
            res = min(res, left - i);
        }
        return res == INT_MAX ? 0 : res;
    }
};



