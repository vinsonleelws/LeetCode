/*The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

 

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int numRows);

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

class Solution {
public:
    string convert(string s, int numRows) {
        
    }
};


// 之字形字符串转换
// 找规律

// My solution:
// 分情况处理：
// 第一行的字符包括: 0, 2*numRows-2, ... j < s.length()，
// 中间行的字符...
// 最后一行包括：j = numRows-1, j += 2*numRows-2, ... j < s.length()
class Solution {
public:
    string convert(string s, int numRows) {
        if(s.length()<=2 || numRows<=1)
            return s;
        
        string result;

        string firstRow;
        int j=0;
        while(j<s.length())
        {
            firstRow.push_back(s[j]);
            j+=(2*numRows-2);
        }
        
        string midRow;
        for(int i=1, interval=2*numRows-4; i<=numRows-2 && interval>=1; i++, interval = interval-2)  // interval = interval-2
        {
            int k = i;
            int l = i+interval;
            while(k<s.length() || l<s.length())
            {
                if(k<s.length())
                    midRow.push_back(s[k]);
                if(l<s.length())
                    midRow.push_back(s[l]);
                k+=(2*numRows-2);
                l+=(2*numRows-2);
            }
        }
        
        string lastRow;
        j=numRows-1;
        while(j<s.length())
        {
            lastRow.push_back(s[j]);
            j+=(2*numRows-2);
        }
        
        result = firstRow+midRow+lastRow;
        return result;
    }
};


// Reference solution:
/*
比如有一个字符串 “0123456789ABCDEF”，转为zigzag

当 n = 2 时：

0 2 4 6 8 A C E

1 3 5 7 9 B D F

当 n = 3 时：

0   4    8     C

1 3 5 7  9  B  D F
  _   _     _    _
2   6    A     E

当 n = 4 时：

0     6       C

1   5 7    B  D
    _      _
2 4   8  A    E
  _      _
3     9       F

*/

// 我们发现，除了第一行和最后一行没有中间形成之字型的数字外，其他都有，而首尾两行中相邻两个元素的index之差跟行数是相关的，为 2*nRows - 2, 
// 根据这个特点，我们可以按顺序找到所有不带下划线的元素在原字符串的位置，将他们按顺序加到新字符串里面。对于带下划线的元素出现的位置也是有规律的，
// 每个带下划线元素的位置为 j + 2*nRows-2 - 2*i, 其中，j为前一个不带下划线元素的列数，i为当前行数。 比如当n = 4中的那个带下划线的5，
// 它的位置为 1 + 2*4-2 - 2*1 = 5，为原字符串的正确位置。当我们知道所有不带下划线元素和带下划线元素位置的正确算法，我们就可以一次性的把它们按顺序都加到新的字符串里面。
class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows <= 1) return s;
        string res = "";
        int size = 2 * nRows - 2;
        for (int i = 0; i < nRows; ++i) {
            for (int j = i; j < s.size(); j += size) {
                res += s[j];
                int tmp = j + size - 2 * i;
                if (i != 0 && i != nRows - 1 && tmp < s.size()) res += s[tmp];
            }
        }
        return res;
    }
};

//
// Input: "ABCDE"
// 4
// Expected: "ABCED"

// "PAYPALISHIRING"
// 3