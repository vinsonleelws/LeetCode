/*The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"

Example 2:

Input: 4
Output: "1211"
*/

class Solution {
public:
    string countAndSay(int n) {
        
    }
};


// 数一数，说一说
// 找规律


// 对于前一个数，找出相同元素的个数，把个数和该元素存到新的string里

class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string str = "11";
        for(int i=3; i<=n; i++)
        {
            int j=0;
            string s;
            while(j<=str.length()-1)
            {
                int count=1;
                while(j<str.length()-1 && str[j]==str[j+1])
                {
                    count++;
                    j++;
                }
                if(count==1)
                {
                    s+='1';
                    s+=str[j];
                }
                else
                {
                    s+=to_string(count);
                    s+=str[j];
                }
                j++;
            }
            str = s;
        }

        return str;
    }
};


// Reference solution:
class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) return "";
        string res = "1";
        while (--n) {
            string cur = "";
            for (int i = 0; i < res.size(); ++i) {
                int cnt = 1;
                while (i + 1 < res.size() && res[i] == res[i + 1]) {
                    ++cnt;
                    ++i;
                }
                cur += to_string(cnt) + res[i];
            }
            res = cur;
        }
        return res;
    }
};