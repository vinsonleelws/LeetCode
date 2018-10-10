/*Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

Example 1:

Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.

Note:
1 <= k <= len(nums) <= 16.
0 < nums[i] < 10000.*/

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
    }
};


// 分割K个等和的子集  [M]
// DFS + visit数组

// 类似于"416-Partition Equal Subset Sum"-判断是否能够对半分、和相等（0-1背包问题）
// 首先我们还是求出数组的所有数字之和sum，首先判断sum是否能整除k，不能整除的话直接返回false。
// 然后需要一个visited数组来记录哪些数组已经被选中了，然后调用递归函数，我们的目标是组k个子集合，
// 每个子集合之和为target = sum/k。我们还需要变量start，表示从数组的某个位置开始查找，
// curSum为当前子集合之和，在递归函数中，如果k=1，说明此时只需要组一个子集合，那么当前的就是了，
// 直接返回true。如果curSum等于target了，那么我们再次调用递归，此时传入k-1，start和curSum都重置为0，
// 因为我们当前又找到了一个和为target的子集合，要开始继续找下一个。否则的话就从start开始遍历数组，
// 如果当前数字已经访问过了则直接跳过，否则标记为已访问。然后调用递归函数，k保持不变，
// 因为还在累加当前的子集合，start传入i+1，curSum传入curSum+nums[i]，因为要累加当前的数字，
// 如果递归函数返回true了，则直接返回true。否则就将当前数字重置为未访问的状态继续遍历。

// Reference solution:
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) 
            return false;
        vector<bool> visited(nums.size(), false);
        return helper(nums, k, sum / k, 0, 0, visited);
    }
    bool helper(vector<int>& nums, int k, int target, int start, int curSum, vector<bool>& visited) {
        if (k == 1) 
            return true;
        if (curSum == target) 
            return helper(nums, k - 1, target, 0, 0, visited);
        for (int i = start; i < nums.size(); ++i) {
            if (visited[i]) 
                continue;
            visited[i] = true;
            if (helper(nums, k, target, i + 1, curSum + nums[i], visited)) 
                return true;
            visited[i] = false;
        }
        return false;
    }
};