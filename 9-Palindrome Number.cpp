Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true

Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Follow up:

Coud you solve it without converting the integer to a string?


// Reference solution
class Solution {
public:
    bool isPalindrome(int x) {
        int reverse_num = 0, num = x;
        while(num>0){
            reverse_num = reverse_num*10 + num%10;
            num = num/10;
        }
        return reverse_num == x;
    }
};
//反转数字，记得考虑个位的情况
//负数不是回文数


// My solution
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        
        string str = to_string(x);
        int length = str.length();
        int start = 0;
        int end = length-1;
        while(start<end)
        {
            if(str[start] != str[end])
                return false;
            
            ++start;
            --end;
        }
        
        return true;
        
    }
};
