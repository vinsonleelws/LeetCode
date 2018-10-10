/* 
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.

Example 2:

Given nums = [0,0,1,1,1,2,2,3,3,4],

Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

It doesn't matter what values are set beyond the returned length.

Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.

Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}

 */

// 删除有序数组中的重复项  [E]
// Two Pointers 快慢指针

// Reference method:
// 我们使用快慢指针来记录遍历的坐标，最开始时两个指针都指向第一个数字，
// 如果两个指针指的数字相同，则快指针向前走一步，如果不同，
// 则将快指针指向的值赋给慢指针指向的值，两个指针都向前走一步.
// 这样当快指针走完整个数组后，慢指针当前的坐标加1就是数组中不同数字的个数.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) 
            return 0;

        int pre = 0, cur = 0;
        while(cur < nums.size()) 
        {
            if(nums[pre] == nums[cur]) 
                ++cur;
            else 
                nums[++pre] = nums[cur++];
        }
        return pre + 1;
    }
};

// 我们也可以用for循环来写，这里的j就是上面解法中的pre，i就是cur，所以本质上都是一样的.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) 
            return 0;

        int j = 0;
        for(int i = 0; i < nums.size(); ++i)
            if (nums[i] != nums[j]) 
                nums[++j] = nums[i];

        return j + 1;
    }
};


// My solution:
// 基于赋值的方法
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int len = 1;
        for(int i=1; i<nums.size(); i++, len++)
        {
            if(nums[i-1] == nums[nums.size()-1])
                return len;
            else
                if(nums[i] <= nums[i-1])
                {
                    int j=i+1;
                    while(j<nums.size() && nums[j]<=nums[i-1])
                        j++;
                    
                    if(j==nums.size())
                        return len;
                    else
                        nums[i] = nums[j];
                }
        }
            
        return len;
    }
};