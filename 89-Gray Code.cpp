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


// åŸºäºè½¬æ¢å…¬å¼çš„æ–¹æ³•ï¼š93. Restore IP Addresses


             // preæŒ‡Oš¸|a /D%¤å¸¦Oš¸|a /D%¤åOš¸|a /D%¤çš„Oš¸|a /D%¤å‰Oš¸|a /D%¤ç»“Oš¸|ç¬¬Oš¸|a /D%¤å¾…Oš¸|a /D%¤ç»“Oš¸|a /D%¤
ã€Oš¸|a /D%¤ã€Oš¸|a /D// 93, front æŒ‡Oš¸|a /Dè®°Oš¸|a /D%¤ä¸ŠOš¸|a /D%¤cï¼ŒOš¸|a /D%ï¼ŒOš¸|a /D%, lastè¡¨Oš¸|a /D%¤åOš¸|a /D%¤åOš¸|a /D%¤çš„Oš¸|a /D%¤æœ€Oš¸|a /D%¤ä¸€Oš¸|a /D%¤èŠ‚Oš¸|a /D%¤ï¼ŒOš¸|a /Dç»“Oš¸|a /D%¤ï¼ˆOš¸|a /D%¤ï¼‰Oš¸|a /D%ä¹ŸOš¸|a /D%¤å³Oš¸|a /D%¤ç¬¬Oš¸|a /D%¤å¾…Oš¸|a /D%
ã€Oš¸|a /D%¤ã€Oš¸|a /D// Runtime beats 100% of cpp submissions.¤åOš¸|a /D%¤ç»“Oš¸|a /D%¤¤estore IP Addresses /D%¤
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


// é™„ï¼š
// æ ¼é›·ç å’Œè‡ªç„¶æ•°çš„è½¬æ¢å‡½æ•°ï¼š

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