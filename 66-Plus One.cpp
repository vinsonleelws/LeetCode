/* Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

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

 */
 
// 对数组表示的非负整数加1
// Math
 
// 需注意的特殊情况：如果输入数组为空，则返回{1}
// My solution:
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
        
        if(i<0 && digits[0]==0)  // 最高位产生进位的情况
            digits.insert(digits.begin(), 1);
        
        return digits;
    }
};

// Reference solution:
// #1
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] == 9) digits[i] = 0;
            else {
                digits[i] += 1;
                return digits;
            }
        }
        if (digits.front() == 0) digits.insert(digits.begin(), 1);
        return digits;
    }
};

// #2
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) return digits;
        int carry = 1, n = digits.size();
        for (int i = n - 1; i >= 0; --i) {
            if (carry == 0) return digits;
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }
        if (carry == 1) digits.insert(digits.begin(), 1);
        return digits;
    }
};