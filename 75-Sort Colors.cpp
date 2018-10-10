/*
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
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {

    }
};

// 75-颜色排序  (M)
// Two Pointers

// 只遍历一遍并且空间复杂度为O(1)的解法：
// 使用双指针：
// - 首先定义p0指针指向开头位置，p2指针指向末尾位置。分别从原数组的首尾往中心移动。
// - 从头开始遍历原数组，如果遇到0，则交换该值和p0指针指向的值，并将p0指针后移一位。若遇到2，则交换该值和p2指针指向的值，并将blue指针前移一位。若遇到1，则继续遍历。
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.empty())
            return;
        int p0 = 0, p2 = nums.size() - 1;
        for (int i = 0; i <= p2; i++)
        {
            if (nums[i] == 0)
                swap(nums[p0++], nums[i]);
            else if (nums[i] == 2)
                swap(nums[p2--], nums[i--]);  // Note here: i--. 交换后，nums[i]可能是0,1,2，因此需要再次检查nums[i]
        }
    }
};


// 基于计数排序的方法：
// 需要遍历数组两遍
// - 首先遍历一遍原数组，分别记录0,1,2的个数
// - 然后更新原数组，按个数分别赋上0，1，2
class Solution {
public:
    void sortColors(int A[], int n) {
        int count[3] = {0}, idx = 0;
        for (int i = 0; i < n; ++i) ++count[A[i]];
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < count[i]; ++j) {
                A[idx++] = i;
            }
        }
    }
};