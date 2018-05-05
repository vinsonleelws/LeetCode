Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2

Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.

// 思路：
// 本质上是要找到平方小于等于目标数的最大的数。
// 采用二分搜索法来找平方根，每次根据x/mid的值来更新low和high，
// 若x/mid>=mid，表明当前的mid可能太小，更新low=mid+1；反之，
// 当前的mid太大，更新high=mid。最后返回high-1.
class Solution {
public:
    int mySqrt(int x) {
        if(x<=1)
            return x;
        
        int low = 1;
        int high = x;
        while(low<high)
        {
            int mid = (low+high)>>1;
            if(x/mid >= mid)
                low = mid+1;
            else
                high = mid;
        }
        return high-1;
    }
};


// 其它方法：
// #1
// 基于牛顿迭代法的解法：
// 因为要求x^2 = n的解，令f(x)=x^2-n，相当于求解f(x)=0的解，可以求出递推式如下：
// xi+1= xi-(xi^2-n)/(2xi) = xi - xi / 2 + n / (2xi) = xi / 2 + n / 2xi = (xi + n/xi) / 2
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        double res = 1, pre = 0;
        while (abs(res - pre) > 1e-6) {
            pre = res;
            res = (res + x / res) / 2;
        }
        return int(res);
    }
};

// #2
// 也是牛顿迭代法，写法更加简洁一些，注意为了防止越界，声明为长整型
class Solution {
public:
    int mySqrt(int x) {
        long res = x;
        while (res * res > x) {
            res = (res + x / res) / 2;
        }
        return res;
    }
};