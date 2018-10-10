/* 
Given an array of size n, find the majority element. The majority element is the element that appears more than |_ n/2 _| times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3

Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
    }
};

// 众数（找次数超|_n/2_|的数）  [E]
// 找规律（摩尔投票法，O(n)，O(1)）；Hash Table；Bit Manipulation

// 思路：最简单的方法是用哈希表来做，时间复杂度和空间复杂度都为O(n)
// 然而有一种十分精巧的方法：摩尔投票法 Moore Voting，时间复杂度为O(n)，空间复杂度为O(1)
// 这种投票法先将第一个数字假设为众数，然后把计数器设为1，比较下一个数和此数是否相等，若相等则计数器加一，反之减一。
// 然后看此时计数器的值，若为零，则将当前值设为候选众数。以此类推直到遍历完整个数组，当前候选众数即为该数组的众数.
// 这是一种先假设候选者，然后再进行验证的算法。使用这个算法有一个大前提：必须保证数组中有众数。
// Reference solution:
// #1 摩尔投票法 Moore Voting
// PS: 这个方法可以应用到题"229-Majority Element II".
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, cnt = 0;
        for (int num : nums) 
        {
            if (cnt == 0) 
            {
                res = num; 
                ++cnt;
            }
            else 
                (num == res) ? ++cnt : --cnt;
        }
        return res;
    }
};


// #2 Bit Manipulation : 将众数按位来构建
// 从0到31位，每次统计下数组中该位上0和1的个数，如果1多，那么我们将结果res中该位变为1，最后累加出来的res就是众数了。
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < 32; ++i) {
            int ones = 0, zeros = 0;
            for (int num : nums) {
                if ((num & (1 << i)) != 0) 
                    ++ones;
                else 
                    ++zeros;
                if (ones > n / 2 || zeros > n / 2) 
                    break;
            }
            if (ones > zeros) 
                res |= (1 << i);
        }
        return res;
    }
};