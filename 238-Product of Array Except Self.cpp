/* 
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
*/

// 除本身之外的数组之积（不能用除法）
// 找规律

// O(n) time and O(1) space
// 两次遍历的解法：第一次从前往后错位相乘；第二次从后往前，用到一个临时变量right，初始化为1，然后每次不断累积，最终得到正确结果。
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        for(int i=1; i<n; i++)
            result[i] = result[i-1] * nums[i-1];
        
        int right = 1;
        for(int i = n-1; i>=0; i--)
        {
            result[i] *= right;
            right *= nums[i];
        }
        
        return result;
    }
};