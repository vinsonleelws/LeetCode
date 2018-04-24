Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000

Example 2:

Input: 2.10000, 3
Output: 9.26100

Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

Note:

    -100.0 < x < 100.0
    n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]


class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1.0;
        else if(n==1)
            return x;
        
        bool negative = n<0? true:false;
        if(negative)
            n = -n;
        double result = powerRecursive(x, n);
        if(negative)
            result = 1.0/result;
        return result;
    }
    double powerRecursive(double x, int n)
    {
        if(n==0)
            return 1.0;
        else if(n==1)
            return x;
        else
        {
            double result = 1.0;
            result*=powerRecursive(x, n/2);
            result*=result;
            if(n&0x1)
                result*=x;
            return result;
        }
    }
};


// 更简洁的写法：
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0.0) 
            return 1.0;
        else if(n == 1.0)
            return x;
        
        double half = myPow(x, n / 2);
        if((n&0x1)==0) 
            return half * half;
        else if(n > 0) 
            return half * half * x;
        else 
            return half * half / x;
    }
};

// Testing cases:
// -1.00000
// -2147483648
// 1.0