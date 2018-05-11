Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.


// 哈希表 / Union Find Set
// Reference solution:
// #1
// 这道题要求求最长连续序列，并给定了O(n)复杂度限制，我们的思路是，使用一个集合set存入所有的数字，然后遍历数组中的每个数字val，如果其在集合中存在，那么将其移除，
// 然后分别用两个变量pre和next算出其前一个数字(val-1)跟后一个数字(val+1)，然后在集合中循环查找，如果pre在集合中，那么将pre移除集合，然后pre再自减1，直至pre不在集合之中，
// 对next采用同样的方法，那么next-pre-1就是当前数字的最长连续序列，更新res即可。
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int result = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for (int val : nums) 
        {
            if (!s.count(val)) 
                continue;
            s.erase(val);
            int pre = val - 1, next = val + 1;
            while (s.count(pre)) 
                s.erase(pre--);
            while (s.count(next)) 
                s.erase(next++);
            result = max(result, next - pre - 1);
        }
        return result;
    }
};


// #2
// 另一种解法：
// 一开始哈希表为空，然后遍历所有数字，如果该数字不在哈希表中，那么我们分别看其左右两个数字是否在哈希表中，如果在，则返回其哈希表中映射值，若不在，则返回0，
// 然后我们将left+right+1作为当前数字的映射，并更新res结果，然后更新d-left和d-right的映射值.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> m;
        for (int d : nums) {
            if (!m.count(d)) {
                int left = m.count(d - 1) ? m[d - 1] : 0;
                int right = m.count(d + 1) ? m[d + 1] : 0;
                int sum = left + right + 1;
                m[d] = sum;
                res = max(res, sum);
                m[d - left] = sum;
                m[d + right] = sum;
            }
        }
        return res;
    }
};