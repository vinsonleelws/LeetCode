Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

// DP
// 每次记录最大值和最小值，在每遍历完一个数时，都要更新最终的最大值。递推公式：
// mini = min(min(maximum*nums[i], minimum*nums[i]), nums[i]);
// maxi = max(max(maximum*nums[i], minimum*nums[i]), nums[i]);
// result = max(result, maxi);
// 即每次的最大值和最小值取决于当前数字与上一个最小值或最大值的乘积，以及当前数字本身
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        int n = nums.size();
        int mini = nums[0], maxi = nums[0], result = nums[0];
        for(int i = 1; i<n; i++)
        {
            int maximum = maxi, minimum = mini;
            mini = min(min(maximum*nums[i], minimum*nums[i]), nums[i]);
            maxi = max(max(maximum*nums[i], minimum*nums[i]), nums[i]);
            result = max(result, maxi);
        }
        
        return result;
    }
};


// 其它解法：
// 下面这种方法也是用两个变量来表示当前最大值和最小值的，但是没有无脑比较三个数，而是对于当前的nums[i]值进行了正负情况的讨论：
// 1. 当遍历到一个正数时，此时的最大值等于之前的最大值乘以这个正数和当前正数中的较大值，此时的最小值等于之前的最小值乘以这个正数和当前正数中的较小值。
// 2. 当遍历到一个负数时，我们先用一个变量t保存之前的最大值mx，然后此时的最大值等于之前最小值乘以这个负数和当前负数中的较大值，此时的最小值等于之前保存的最大值t乘以这个负数和当前负数中的较小值。
// 3. 在每遍历完一个数时，都要更新最终的最大值。

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0], mx = res, mn = res;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                mx = max(mx * nums[i], nums[i]);
                mn = min(mn * nums[i], nums[i]);
            } else {
                int t = mx;
                mx = max(mn * nums[i], nums[i]);
                mn = min(t * nums[i], nums[i]);
            }
            res = max(res, mx);
        }
        return res;
    }
};

// 下面这道题使用了一个trick来将上面解法的分情况讨论合成了一种，在上面的解法中我们分析了当nums[i]为正数时，最大值和最小值的更新情况，为负数时，
// 稍有不同的就是最小值更新时要用到之前的最大值，而不是更新后的最大值，所以我们才要用变量t来保存之前的结果。而下面这种方法的巧妙处在于先判断一
// 个当前数字是否是负数，是的话就交换最大值和最小值。那么此时的mx就是之前的mn，所以mx的更新还是跟上面的方法是统一的，而在在更新mn的时候，之前的
// mx已经保存到mn中了，而且并没有改变，所以可以直接拿来用。
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0], mx = res, mn = res;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0) swap(mx, mn);
            mx = max(nums[i], mx * nums[i]);
            mn = min(nums[i], mn * nums[i]);
            res = max(res, mx);
        }
        return res;
    }
};