Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.

Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.


// 需注意的特殊情况：如果输入数组为空，则饭后{1}
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(n==0)
        {
            digits.push_back(1);
            return digits;
        }
        
        digits[n-1] += 1;
        if(digits[n-1]<=9)
            return digits;
        int carry = 1;
        digits[n-1] = 0;
        int i = n-2;
        for(; i>=0; i--)
        {
            digits[i] += carry;
            carry = digits[i]/10;
            if(!carry)
                break;
            else
                digits[i] = 0;
        }
        if(i<0 && digits[0]==0)
            digits.insert(digits.begin(), 1);
        
        return digits;
    }
};