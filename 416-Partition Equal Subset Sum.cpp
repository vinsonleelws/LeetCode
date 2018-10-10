/*Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:

    Each of the array element will not exceed 100.
    The array size will not exceed 200.

Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.
*/


class Solution {
public:
    bool canPartition(vector<int>& nums) {

    }
};


// 对半分（0-1背包问题）  [M]
// DP

// dp[i]表示是否能找到和为i的划分
// 递推公式：dp[i] = dp[i] || dp[i-num]
// 边界条件：dp[0] = 1, 其余等于0

// 根据题意：
// 1. 原数组所有数字和一定是偶数，否则返回false；
// 2. 在尝试放一个元素的时候还要避免他对尝试放其他位置时对自己的影响，因此需要从容量最大的位置开始，
//    如果（当前位置－当前元素大小）位置可以通过放置之前的元素达到，则当前位置也可以通过放置当前元素正好达到这个位置。
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), target = sum >> 1;
        if (sum & 1) return false;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : nums) 
            for (int i = target; i >= num; --i)  // 注意从后往前更新
                dp[i] = dp[i] || dp[i - num];

        return dp[target];
    }
};