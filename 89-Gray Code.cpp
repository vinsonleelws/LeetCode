The gray code is a binary numeral system where two successive values differ in only one bit.

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


// 基于转换公式的方法：93. Restore IP Addresses


             // pre指O��|a�/D%�带O��|a�/D%�反O��|a�/D%�的O��|a�/D%�前O��|a�/D%�结O��|第O��|a�/D%�待O��|a�/D%�结O��|a�/D%�
、O��|a�/D%�、O��|a�/D// 93, front 指O��|a�/D记O��|a�/D%�上O��|a�/D%�c，O��|a�/D%，O��|a�/D%, last表O��|a�/D%�反O��|a�/D%�后O��|a�/D%�的O��|a�/D%�最O��|a�/D%�一O��|a�/D%�节O��|a�/D%�，O��|a�/D结O��|a�/D%�（O��|a�/D%�）O��|a�/D%也O��|a�/D%�即O��|a�/D%�第O��|a�/D%�待O��|a�/D%
、O��|a�/D%�、O��|a�/D// Runtime beats 100% of cpp submissions.�反O��|a�/D%�结O��|a�/D%��estore IP Addresses�/D%�
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