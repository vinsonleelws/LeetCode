/* 
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.

Example 1:

Input: [1,3,5]
Output: 1

Example 2:

Input: [2,2,2,0,1]
Output: 0 
*/

// 寻找旋转数组的最小值（可能包含重复元素）
// Binary Search

// 当旋转数组有重复项时，我们需考虑特殊情况：
// (1) 当头和尾元素值相等时，我们进一步看中间元素是否相等，如果三个元素都相等，我们不能得到进一步行动的指导信息，此时最好的办法将左指针(或右指针)移动一位，这对结果不会产生影响，再继续搜索。
// 在最坏的情况下，比如数组所有元素都相同，时间复杂度会升到O(n)。当然对于这种情况还有一种直接法：就是从头到尾遍历找到最小元素即可。
// (2) 当头和尾元素相等而中间元素不相等时，根据中间元素的值缩小查找区间。
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        int n=nums.size();
        if(nums[0]<nums[n-1] || n==1)
            return nums[0];
        
        int start = 0, end = n-1;
        while(nums[start] >= nums[end])
        {
            if(start == end-1)
                return nums[end];
            int mid = (start+end)>>1;
            if(nums[start]==nums[mid] && nums[end]==nums[mid])  // 关键。相比"153-Find Minimum in Rotated Sorted Array"多的一步判断步骤
                start++;  // or end--;
            else if(nums[mid] >= nums[start])
                start = mid;
            else if(nums[mid] <= nums[end])
                end = mid;
        }
        return nums[start];
    }
};


// 另一种写法
class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.empty()) return 0;
        int left = 0, right = nums.size() - 1, res = nums[0];
        while (left < right - 1) {
            int mid = left + (right - left) / 2;
            if (nums[left] < nums[mid]) {
                res = min(res, nums[left]);
                left = mid + 1;
            } else if (nums[left] > nums[mid]) {
                res = min(res, nums[right]);
                right = mid;
            } else ++left;
        }
        res = min(res, nums[left]);
        res = min(res, nums[right]);
        return res;
    }
};