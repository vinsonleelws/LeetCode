/*You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed.
All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile,
adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
             because they are adjacent houses.

Example 2:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.*/

class Solution {
public:
    int rob(vector<int>& nums) {

    }
};

// 打家劫舍II (房子连成圈)  [M]
// DP


// DP
// 这道题是"198-House Robber"的拓展，现在房子排成了一个圆圈，则如果抢了第一家，就不能抢最后一家，因为首尾相连了，所以第一家和最后一家只能抢其中的一家，或者都不抢，
// 我们这里可以变通一下，如果我们把第一家和最后一家分别去掉，各算一遍能抢的最大值，然后比较两个值取其中较大的一个即为所求。只需参考"198-House Robber"的解题方法，然后调用两边取较大值。

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        else if (nums.size() == 1)
            return nums[0];

        int m1 = rob(nums, 1, nums.size() - 1);
        int m2 = rob(nums, 0, nums.size() - 2);
        return max(m1, m2);
    }

    int rob(vector<int>& nums, const int& left, const int& right) {
        if (left > right)
            return 0;
        else if (left == right)
            return nums[left];

        int p1 = nums[left];
        int p2 = max(nums[left], nums[left + 1]);
        int result = p2;
        for (int i = left + 2; i <= right; i++)
        {
            result = max(nums[i] + p1, p2);
            p1 = p2;
            p2 = result;
        }
        return result;
    }
};