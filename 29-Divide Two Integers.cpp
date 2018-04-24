// Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

// Return the quotient after dividing dividend by divisor.

// Example 1:

// Input: dividend = 10, divisor = 3
// Output: 3

// Example 2:

// Input: dividend = 7, divisor = -3
// Output: -2

// Note:

    // Both dividend and divisor will be 32-bit signed integers.
    // The divisor will never be 0.
    // Assume we are dealing with an environment which could only 
    // store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1].  [-2147483648, 2147483647]
    // For the purpose of this problem, assume that your function returns 2^31 − 1 when the division result overflows.


// tips: 可以用异或去判断两个数是否异号. eg. bool sign = ((num1<0)^(num2<0)) ? -1 : 1;


// My solution (improved version)
// 两个整数相除需注意的几点：
// (1) 除零返回INT_MAX; 除1返回被除数本身; 若被除数小于除数返回0
// (2) 由于除法得到的商也可能溢出，所以计算过程中都采用长整型long long来计算。
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0 || (dividend==INT_MIN && divisor==-1))
            return INT_MAX;

        bool negative = ((dividend<0)^(divisor<0))? true : false;
        long long ll_dividend = abs((long long)dividend);
        long long ll_divisor = abs((long long)divisor);
        
        if(ll_dividend < ll_divisor)
            return 0;
        if(ll_divisor==1)
            return negative==true? -ll_dividend : ll_dividend;
        
        long long result = 0;
        while(ll_dividend >= ll_divisor)
        {
            long long times = 1, num = ll_divisor;
            while(ll_dividend >= (num<<1))  // note that >=
            {
                num <<= 1;
                times <<= 1;
            }
            result += times;
            ll_dividend -= num;
        }
   
        result = negative==true? -result : result;
        
        if(result>INT_MAX || result<INT_MIN)
            return INT_MAX;
        else
            return result;
    }
};

// My solution 
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0 || (dividend==INT_MIN && divisor==-1))
            return INT_MAX;

        bool negative = ((dividend<0)^(divisor<0))? true : false;
        //bool negative = false;
        //if((dividend<0 && divisor>0) || (dividend>0 && divisor<0))
            //negative = true;
        
        long long ll_dividend = abs((long long)dividend);
        long long ll_divisor = abs((long long)divisor);
        
        if(ll_dividend < ll_divisor)
            return 0;
        if(ll_divisor==1)
            return negative==true? -ll_dividend : ll_dividend;
        
        long long result = 1;
        long long num = ll_divisor;
        while(ll_dividend >= (num<<1))  // note that >=
        {
            num <<= 1;
            result <<= 1;
        }
        while(ll_dividend >= num+ll_divisor)  // Here is too slow!
        {
            result+=1;
            num+=ll_divisor;
        }
        
        result = negative==true? -result : result;
        
        if(result>INT_MAX || result<INT_MIN)
            return INT_MAX;
        else
            return result;
    }
};


// Reference solution: #1

// 如果被除数大于或等于除数，则进行如下循环，定义变量t等于除数，定义计数p，当t的两倍小于等于被除数时，
// 进行如下循环，t扩大一倍，p扩大一倍，然后更新res和m。这道题的OJ给的一些test case非常的讨厌，
// 因为输入的都是int型，比如被除数是-2147483648，在int范围内，当除数是-1时，结果就超出了int范围，
// 需要返回INT_MAX，所以对于这种情况我们就在开始用if判定，将其和除数为0的情况放一起判定，返回INT_MAX。
// 然后我们还要根据被除数和除数的正负来确定返回值的正负，这里我们采用长整型long long来完成所有的计算，
// 最后返回值乘以符号。

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        long long m = abs((long long)dividend), n = abs((long long)divisor), res = 0;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        if (n == 1) return sign == 1 ? m : -m;
        while (m >= n) {
            long long t = n, p = 1;
            while (m >= (t << 1)) {
                t <<= 1;
                p <<= 1;
            }
            res += p;
            m -= t;
        }
        return sign == 1 ? res : -res;
    }
};

// #2 (更简洁)
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long m = abs((long long)dividend), n = abs((long long)divisor), res = 0;
        if (m < n) return 0;    
        while (m >= n) {
            long long t = n, p = 1;
            while (m > (t << 1)) {
                t <<= 1;
                p <<= 1;
            }
            res += p;
            m -= t;
        }
        if ((dividend < 0) ^ (divisor < 0)) res = -res;
        return res > INT_MAX ? INT_MAX : res;
    }
};

// #3 使用递归
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long res = 0;
        long long m = abs((long long)dividend), n = abs((long long)divisor);
        if (m < n) return 0;
        long long t = n, p = 1;
        while (m > (t << 1)) {
            t <<= 1;
            p <<= 1;
        }
        res += p + divide(m - t, n);
        if ((dividend < 0) ^ (divisor < 0)) res = -res;
        return res > INT_MAX ? INT_MAX : res;
    }
};

// Testing cases:
// 2147483647
// 1
// 2147483647

// -2147483648
// -1
// 2147483647

// Input: 2147483647
// 2
// Expected: 1073741823

// Input: -2147483648
// 2
// Expected: -1073741824