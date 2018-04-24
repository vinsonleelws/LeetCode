Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3

Example 2:

Input: [3,4,-1,1]
Output: 2

Example 3:

Input: [7,8,9,11,12]
Output: 1

// Reference solution:
// 思路：
// Put each number in its right place.
// For example:
// When we find 5, then swap it with A[4].
// At last, the first place where its number is not right, return the place + 1.
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while (i < n) {
            if (nums[i] != i + 1 && nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {  // nums[i] != i + 1的判断可以不必，但若加上，可以加速
                swap(nums[i], nums[nums[i] - 1]);
            } else {
                ++ i;
            }
        }
        for (i = 0; i < n; ++i) {
            if (nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }

};