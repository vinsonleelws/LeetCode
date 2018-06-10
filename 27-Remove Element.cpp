/* 
Given an array nums and a value val, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example 1:

Given nums = [3,2,2,3], val = 3,

Your function should return length = 2, with the first two elements of nums being 2.

It doesn't matter what you leave beyond the returned length.

Example 2:

Given nums = [0,1,2,2,3,0,4,2], val = 2,

Your function should return length = 5, with the first five elements of nums containing 0, 1, 3, 0, and 4.

Note that the order of those five elements can be arbitrary.

It doesn't matter what values are set beyond the returned length.

Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.

Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeElement(nums, val);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
 */
 
// 删除指定元素
// Two Pointers 快慢指针。数值覆盖法。

// My solution.
// 基于两数交换的方法。
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty())
            return 0;
        
        int i=0;
        int j=nums.size()-1;
        while(i<=j)
        {
            if(nums[i]!=val)
                i++;
            else if(nums[j]!=val)
                swap(nums[i++], nums[j--]);
            else if(nums[j] == val)
                j--;
        }
        return i;
    }
    void swap(int& a, int& b)
    {
        if(a!=b)
        {
            int temp = a;
            a = b;
            b = a;
        }
    }
};

// Reference solution:
// 基于赋值的方法。
// 只需要一个变量用来计数，然后遍历原数组，如果当前的值和给定值不同，我们就把当前值覆盖计数变量的位置，并将计数变量加1。
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) 
                nums[len++] = nums[i];
        }
        return len;
    }
};


// Testing cases
// Input: [1]
// Expected: []