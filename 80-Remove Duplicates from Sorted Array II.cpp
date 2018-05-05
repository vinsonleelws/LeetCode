Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.

It doesn't matter what you leave beyond the returned length.

Example 2:

Given nums = [0,0,1,1,1,1,2,3,3],

Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.

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


// 思路：
// 这题是Remove Duplicates from Sorted Array 有序数组中去除重复项的延续，依然采用快慢指针的方法去做。
// 这里允许最多重复的次数是两次，那么我们就需要用一个变量count来记录允许重复的次数，count初始化为1，
// 如果出现过一次重复，则count加1(变为2)。每次根据快慢指针指向的数进行操作：如果快慢指针指向的值相等而且count==1，
// 那么nums[++j] = nums[i]; count++; 而如果两值不相等，nums[++j] = nums[i], count = 1;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) 
            return 0;
        int j = 0, count=1;
        for(int i = 1; i < nums.size(); ++i) // note that i starts with 1
        {
            if(nums[i]!=nums[j])
            {
                nums[++j] = nums[i];
                count = 1;
            }
            else
            {
                if(count == 1)
                {
                    nums[++j] = nums[i];
                    count++;
                }
            }
                
        }
        return j + 1;
    }
};