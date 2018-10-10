/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
 */

class Solution {
public:
	bool canJump(vector<int>& nums) {

	}
};

// 55-跳跃游戏  [M]
// DP, Greedy

// 每个数字表示在当前位置的基础上最多可以走的步数，求判断能不能到达最后一个位置
// #1
// Greedy
// 贪婪算法每到一个位置就去更新该位置最远能到达的位置，如果最远能到达末尾元素则提前终止
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int maxIndex = 0;

		for (int i = 0; i < nums.size() && i <= maxIndex; i++)
		{
			maxIndex = max(maxIndex, i + nums[i]); // i + nums[i]表示当前位置能到达的最大位置
			if (maxIndex >= nums.size() - 1)
				return true;
		}
		return false;
	}
};

// #2
// DP
// 用dp[i]表示每个位置上的剩余步数。
// 当前位置的剩余步数（dp值）和当前位置的跳力中的较大那个数决定了当前能到的最远距离，而下一个位置的剩余步数（dp值）就等于当前的这个较大值减去1，
// 因为需要花一个跳力到达下一个位置，所以我们就有状态转移方程了：dp[i] = max(dp[i - 1], nums[i - 1]) - 1，如果当某一个时刻dp数组的值为负了，说
// 明无法抵达当前位置，则直接返回false，最后我们判断dp数组最后一位是否为非负数即可知道是否能抵达该位置
class Solution {
public:
	bool canJump(vector<int>& nums) {
		vector<int> dp(nums.size(), 0);
		for (int i = 1; i < nums.size(); ++i) {
			dp[i] = max(dp[i - 1], nums[i - 1]) - 1;
			if (dp[i] < 0) return false;
		}
		return dp.back() >= 0;
	}
};