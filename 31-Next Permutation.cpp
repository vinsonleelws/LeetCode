Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

// 思路：
// 这道题让我们求下一个排列顺序，由题目中给的例子可以看出来，如果给定数组是降序，
// 则说明是全排列的最后一种情况，则下一个排列就是最初始情况.
// 我们再来看下面一个例子，有如下的一个数组.

// 1　　2　　7　　4　　3　　1
// 下一个排列为：
// 1　　3　　1　　2　　4　　7
// 我们通过观察原数组可以发现，如果从末尾往前看，数字逐渐变大，到了2时才减小的，
// 然后我们再从后往前找第一个比2大的数字，是3，那么我们交换2和3，再把此时3后面的所有数字转置一下.

// Reference solution.
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i = n - 2, j = n - 1;
        while(i >= 0 && nums[i] >= nums[i + 1]) 
            --i;
        if(i >= 0) 
        {
            while(nums[j] <= nums[i]) 
                --j;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

// 另一种写法：
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int i, j, n = num.size();
        for(i = n - 2; i >= 0; --i) 
        {
            if(num[i + 1] > num[i]) 
            {
                for(j = n - 1; j > i; --j) 
                {
                    if(num[j] > num[i]) 
                        break;
                }
                swap(num[i], num[j]);
                break;
            }
        }
        reverse(num.begin()+i+1, num.end());
    }
};

