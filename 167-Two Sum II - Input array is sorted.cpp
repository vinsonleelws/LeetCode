/* Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

    Your returned answers (both index1 and index2) are not zero-based.
    You may assume that each input would have exactly one solution and you may not use the same element twice.

Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
 */

// 两数之和II-输入数组有序
// Two Pointers ; Binary Search

// 介于是sorted array，我们可以使用分别指向头尾的双指针，时间复杂度为O(n)。
// My solution:
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int start = 0, end = numbers.size() - 1;

        while (start < end)
        {
            if (numbers[start] + numbers[end] == target)
                return {start + 1, end + 1};    /* result.push_back(start); result.push_back(start); return result; */
            else if (numbers[start] + numbers[end] < target)
                start++;
            else
                end--;
        }
    }
};


// 采用Binary Search的方法，时间复杂度为O(nlogn)。因为一定有解，而且数组是有序的，那么第一个数字肯定要小于目标值target，那么我们每次用二分法来搜索target - numbers[i]即可。
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i) {
            int t = target - numbers[i], left = i + 1, right = numbers.size() - 1;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (numbers[mid] == t)
                    return {i + 1, mid + 1};
                else if (numbers[mid] < t)
                    left = mid + 1;
                else
                    right = mid;
            }
        }
        return {};
    }
};