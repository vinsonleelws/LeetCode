/*Reverse bits of a given 32 bits unsigned integer.

Example:

Input: 43261596
Output: 964176192
Explanation: 43261596 represented in binary as 00000010100101000001111010011100, 
             return 964176192 represented in binary as 00111001011110000010100101000000.

Follow up:
If this function is called many times, how would you optimize it?*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
    }
};


// 反转位 (eg. 001 -> 100)  [E]
// Bit Manipulation

// -------------------------------------
// 基本思路都是对原数字的每一位进行操作，低位反转成高位
// 原数字可以从低位开始，这样每次将原数字右移一位，而结果数字则每次左移一位并根据原数字的位是1还是0置位
// #1
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; ++i) 
        {
            if (n & 1 == 1) 
                res = (res << 1) + 1;
            else 
                res = res << 1;
            
            n = n >> 1;
        }
        return res;
    }
};

// 其它更简洁的写法
// #2
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; ++i) 
        {
            res <<= 1;
            if ((n & 1) == 1) 
                ++res;
            n >>= 1;
        }
        return res;
    }
};

// #3
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; ++i) 
        {
            res = (res << 1) | (n & 1);
            n >>= 1;
        }
        return res;
    }
};

// #4
// 下面这种方法不更新n的值，而是直接将n右移i位，然后通过‘与’1来提取出该位，加到左移一位后的结果res中即可
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; ++i) {
            res = (res << 1) + (n >> i & 1);
        }
        return res;
    }
};

// #5
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; ++i) {
            res |= ((n >> i) & 1) << (31 - i);
        }
        return res;
    }
};