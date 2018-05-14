A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5 
Explanation: Your function can return either index number 1 where the peak element is 2, 
             or index number 5 where the peak element is 6.

Note:

Your solution should be in logarithmic complexity.

// 题目要求在对数时间复杂度内完成，自然而然就想到了二分查找法：
// 解法如下，每次去比较中间数字和它右边一个数字的大小，进而缩小查找空间。
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        while(low<high)
        {
            int mid = (low+high)>>1;
            if(nums[mid]>nums[mid+1])
                high = mid;
            else
                low = mid+1; 
        }
        
        return high;
    }
};


// 另一种非常好的方法：(采用)
// 由于题目中说明了局部峰值一定存在，那么实际上可以从第二个数字开始往后遍历，如果第二个数字比第一个数字小，说明此时第一个数字就是一个局部峰值；
// 否则就往后继续遍历，现在是个递增趋势，如果此时某个数字小于前面那个数字，说明前面数字就是一个局部峰值，返回位置即可。如果循环结束了，说明原数组是个递增数组，返回最后一个位置即可。
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i]<nums[i-1])
                return i-1;
        }
        
        return nums.size()-1;
    }
};