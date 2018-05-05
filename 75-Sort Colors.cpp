Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Follow up:

    A rather straight forward solution is a two-pass algorithm using counting sort.
    First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
    Could you come up with a one-pass algorithm using only constant space?


// 只遍历一遍并且空间复杂度为O(1)的解法：    
// 使用双指针：
// - 首先定义p0指针指向开头位置，p2指针指向末尾位置。分别从原数组的首尾往中心移动。
// - 从头开始遍历原数组，如果遇到0，则交换该值和p0指针指向的值，并将p0指针后移一位。若遇到2，则交换该值和p2指针指向的值，并将blue指针前移一位。若遇到1，则继续遍历。
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.empty())
            return;
        int p0 = 0, p2 = nums.size()-1;
        for(int i=0; i<=p2; i++)
        {
            if(nums[i]==0)
                swap(nums[p0++], nums[i]);
            else if(nums[i]==2)
                swap(nums[p2--], nums[i--]);  // Note here: i--
        }
    }
};