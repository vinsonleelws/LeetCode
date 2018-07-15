/*Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

 

Requirements for atoi:

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

*/

class Solution {
public:
    int myAtoi(string str) {
        
    }
};


// 字符串转整数（须有空格处理和越界检查）
// Math

// My solution
class Solution {
public:
    int myAtoi(string str) {
        if(str == string(""))
            return 0;
        
        unsigned length = str.length();
        int start = 0;
        // remove the whitespace characters
        while(str[start] == ' ' && start<length)
        {
            start++;
        }
        
        bool minus = false;
        if(str[start]=='+')
            start++;
        else if(str[start]=='-')
        {
            start++;
            minus = true;
        }
        
        if(start>length-1 || (str[start]<'0' || str[start]>'9'))
            return 0;
        
        long long num = 0;  // 注意大数问题。要转换的数很可能超过int最大或最小数，因此用long long来存储转换数。
        while(start<=length-1 && str[start]>='0' && str[start]<='9')
        {
            num = num*10 + (str[start]-'0');
            
            if(minus)       // 要转换数甚至大于long long的取值范围，因此在转换过程中就进行溢出检查。
            {
                if(-num<INT_MIN)
                    return INT_MIN;
            }
            else if(num>INT_MAX)
                return INT_MAX;
            
            start++;
        }   
        
        if(minus)
           num = -num;
           
        return num;
    }
};


// Reference solution:
class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) 
        	return 0;
        int sign = 1, base = 0, i = 0, n = str.size();
        while (i < n && str[i] == ' ') 
        	++i;
        if (str[i] == '+' || str[i] == '-') 
        {
            sign = (str[i++] == '+') ? 1 : -1;
        }

        while (i < n && str[i] >= '0' && str[i] <= '9') 
        {
            if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) 
            {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            base = 10 * base + (str[i++] - '0');
        }
        return base * sign;
    }
};

// Input: "+-2"
// Expected: 0

// "  -0012a42"
// Expected: -12

// Input: "2147483648"
// Expected: 2147483647

// Input: "9223372036854775809"
// Expected: 2147483647