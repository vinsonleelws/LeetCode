Given an integer, write a function to determine if it is a power of two.

Example 1:

Input: 1
Output: true

Example 2:

Input: 16
Output: true

Example 3:

Input: 218
Output: false

// Bit Manipulation
// My solution:
class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n)
        {
            if(n&1)
            {
                n >>= 1;
                if(n == 0)
                    return true;
                else
                    return false;
            }
            n >>= 1;
        }
        return false;
    }
};

// Other solution：
// #1
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int cnt = 0;
        while (n > 0) {
            cnt += (n & 1);
            n >>= 1;
        }
        return cnt == 1;
    } 
};

// #2 
// 这道题还有一个技巧，如果一个数是2的次方数的话，根据上面分析，那么它的二进数必然是最高位为1，其它都为0，那么如果此时我们减1的话，
// 则最高位会降一位，其余为0的位现在都为变为1，那么我们把两数相与，就会得到0，用这个性质也能来解题，而且只需一行代码就可以搞定。

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && (!(n & (n - 1)));
    } 
};
