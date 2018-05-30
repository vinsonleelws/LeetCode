Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: [5,7]
Output: 4

Example 2:

Input: [0,1]
Output: 0

// Bit Manipulation:
// 我们先从题目中给的例子来分析，[5, 7]里共有三个数字，分别写出它们的二进制为：
// 101　　110　　111
// 相与后的结果为100，仔细观察我们可以得出，最后的数是该数字范围内所有的数的左边共同的部分，如果上面那个例子不太明显，我们再来看一个范围[26, 30]，它们的二进制如下：
// 11010　　11011　　11100　　11101　　11110
// 发现了规律后，我们只要写代码找到左边公共的部分即可。

// #1
// 直接平移m和n，每次向右移一位，直到m和n相等，记录下所有平移的次数i，然后再把m左移i位即为最终结果.
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i = 0;
        while(m != n)
        {
            if(m == n)
                return m<<i;
            else
            {
                m >>= 1;
                n >>= 1;
                i++;
            }
        }
        
        return m;
    }
};

// #2
// 使用一个32位都是1的mask，用它来与m和n相与，比较m和n是否相同，不同就将mask左移一位，直至相同，然后把m和mask相与就是最终结果
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int d = INT_MAX;
        while ((m & d) != (n & d)) {
            d <<= 1;
        }
        return m & d;
    }
};

// #3
// 递归方法只需一行
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        return (n > m) ? (rangeBitwiseAnd(m / 2, n / 2) << 1) : m;
    }
};



// #4
// 下面这种方法也不错，如果m小于n就进行循环，n与上n-1（相当于将最右边的1变为0），如果小于等于m了，返回此时的n即可
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while (m < n) n &= (n - 1);
        return n;
    }
};