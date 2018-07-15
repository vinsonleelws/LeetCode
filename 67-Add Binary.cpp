/*Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"

Example 2:

Input: a = "1010", b = "1011"
Output: "10101"*/

class Solution {
public:
    string addBinary(string a, string b) {
        
    }
};


// 二进制数相加
// Math

// Reference solution:
// 用两个指针分别指向a和b的末尾，然后每次取出一个字符，转为数字，若无法取出字符则按0处理，然后定义进位carry，初始化为0，
// 将三者加起来，对2取余即为当前位的数字，对2取商即为当前进位的值，记得最后还要判断下carry，如果为1的话，要在结果最前面加上一个1
class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int m = a.size() - 1, n = b.size() - 1, carry = 0;
        while (m >= 0 || n >= 0) {
            int p = m >= 0 ? a[m--] - '0' : 0;
            int q = n >= 0 ? b[n--] - '0' : 0;
            int sum = p + q + carry;
            res = to_string(sum % 2) + res;
            carry = sum / 2;
        }
        return carry == 1 ? "1" + res : res;
    }
};

// My solution: 
// 从尾到头扫描两个字符串，相加并把结果存入结果字符串，最后再反转结果；
class Solution {
public:
    string addBinary(string a, string b) {
        if(a.empty())
            return b;
        else if(b.empty())
            return a;
        
        string result;
        int i=a.length()-1;
        int j=b.length()-1;
        int carry=0;
        while(i>=0 && j>=0)
        {
            int bit = a[i]-'0' + b[j]-'0' +carry;
            if(bit>=2)
            {
                bit -=2;
                carry = 1;
            }
            else
                carry = 0;
            result.push_back(bit+'0');
            i--;
            j--;     
        }
        
        while(i>=0)
        {
            int bit = a[i]-'0'+carry;
            if(bit>=2)
            {
                bit -=2;
                carry = 1;
            }
            else
                carry = 0;
            result.push_back(bit+'0');
            i--;
        }
        
        while(j>=0)
        {
            int bit = b[j]-'0'+carry;
            if(bit>=2)
            {                
                bit -=2;
                carry = 1;
            }
            else
                carry = 0;
            result.push_back(bit+'0');
            j--;
        }
        
        if(carry == 1)
            result.push_back('1');
        
        reverse(result.begin(), result.end());
        return result;
    }
};

// 另一种最后不使用reverse的写法：
// 但由于每次需对结果字符串进行插入操作，因而时间效率很低。
class Solution {
public:
    string addBinary(string a, string b) {
        if(a.empty())
            return b;
        else if(b.empty())
            return a;
        
        string result;
        int i=a.length()-1;
        int j=b.length()-1;
        int carry=0;
        while(i>=0 && j>=0)
        {
            int bit = a[i]-'0' + b[j]-'0' +carry;
            if(bit>=2)
            {
                bit -=2;
                carry = 1;
            }
            else
                carry = 0;
            
            result = to_string(bit) + result;
            i--;
            j--;     
        }
        
        while(i>=0)
        {
            int bit = a[i]-'0'+carry;
            if(bit>=2)
            {
                bit -=2;
                carry = 1;
            }
            else
                carry = 0;
            
            result = to_string(bit) + result;
            i--;
        }
        
        while(j>=0)
        {
            int bit = b[j]-'0'+carry;
            if(bit>=2)
            {                
                bit -=2;
                carry = 1;
            }
            else
                carry = 0;
            
            result = to_string(bit) + result;
            j--;
        }
        
        if(carry == 1)
            result = "1" + result;
        
        return result;
    }
};


