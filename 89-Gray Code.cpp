/*The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2

Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/

class Solution {
public:
    vector<int> grayCode(int n) {
        
    }
};


// 格雷码  [M]
// Math ; Backtracking


// 基于转换公式的方法：
// 左移+异或
// Beats 100% cpp solutions.
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        int nNum = pow(2,n);
        for (int i = 0; i < nNum; ++i) {
            result.push_back((i >> 1) ^ i);
        }
        return result;
    }
};


// 附：
// 格雷码和自然数的转换函数：

/*
        The purpose of this function is to convert an unsigned
        binary number to reflected binary Gray code.
        The operator >> is shift right. The operator ^ is exclusive or.
*/
unsigned int binaryToGray(unsigned int num)
{
        return (num >> 1) ^ num;
}
 
/*
        The purpose of this function is to convert a reflected binary
        Gray code number to a binary number.
*/
unsigned int grayToBinary(unsigned int num)
{
    unsigned int mask;
    for (mask = num >> 1; mask != 0; mask = mask >> 1)
    {
        num = num ^ mask;
    }
    return num;
}


// 使用set来保存已经产生的结果，我们从0开始，遍历其二进制每一位，对其取反，然后看其是否在set中出现过，
// 如果没有，我们将其加入set和结果res中，然后再对这个数的每一位进行遍历，以此类推就可以找出所有的格雷码了
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        unordered_set<int> s;
        helper(n, s, 0, res);
        return res;
    }

    void helper(int n, unordered_set<int>& s, int out, vector<int>& res) {
        if (!s.count(out)) 
        {
            s.insert(out);
            res.push_back(out);
        }
        for (int i = 0; i < n; ++i) {
            int t = out;
            if ((t & (1 << i)) == 0) 
                t |= (1 << i);
            else 
                t &= ~(1 << i);
            if (s.count(t)) 
                continue;
            helper(n, s, t, res);
            break;
        }
    }
};