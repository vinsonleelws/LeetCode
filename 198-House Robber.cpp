/*You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.

Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
*/

// 打家劫舍
// DP

             
// DP
// dp[i]表示到下标为i的位置时，可以抢得的最多金钱。
// 地推公式：
// dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
// 边界值处理：
// dp[0] = nums[0]; 
// dp[1] = max(nums[0], nums[1]).
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        else if(nums.size() == 1)
            return nums[0];
        
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i=2; i<n; i++)
            dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
        
        return dp[n-1];
    }
};

// 可以进一步优化至O(1)的空间复杂度
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        else if(nums.size() == 1)
            return nums[0];
        
        int n = nums.size();
        int p1 = nums[0];
        int p2 = max(nums[0], nums[1]);
        int result = p2;
        for(int i=2; i<n; i++)
        {
            result = max(nums[i]+p1, p2);
            p1 = p2;
            p2 = result;
        }
        return result;
    }
};