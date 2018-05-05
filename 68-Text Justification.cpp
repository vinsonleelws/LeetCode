Given an array of words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

Note:

    A word is defined as a character sequence consisting of non-space characters only.
    Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
    The input array words contains at least one word.

Example 1:

Input:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]

Example 2:

Input:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be",
             because the last line must be left-justified instead of fully-justified.
             Note that the second line is also left-justified becase it contains only one word.

Example 3:

Input:
words = ["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]

// My solution: Runtime beats 100% cpp submisions.
// 需注意的几点：
// (1) 对不均匀空格数的处理；
// (2) 最后一行的处理.
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        if(n==0)
            return words;
        vector<string> result;
        int i=0;
        while(i<n)
        {
            int start = i;
            int wordWidth = words[i].length();
            while(i<n && wordWidth+i-start<=maxWidth)
            {
                i++;
                wordWidth += words[i].length();
            }
            wordWidth -= words[i--].length();
            int spaces = maxWidth - wordWidth;
            int gaps = i-start;
            int interval = 1;
            int unevenSpaces = 0; // Used to handle uneven spaces.
            
            if(gaps==0)
                interval = spaces;
            else
            {
                interval = spaces/gaps;
                unevenSpaces = spaces%gaps;
            }
            
            string line = "";
            if(i<n-1)
            {
                for(int j=start; j<i; j++)
                {
                    line += words[j];
                    if(unevenSpaces)
                    {
                        line += string(interval+1, ' ');
                        unevenSpaces--;
                    }
                    else
                        line += string(interval, ' ');
                }
                line += words[i];
                if(i==start)
                    line += string(spaces, ' ');
            }
            else
            {
                for(int j=start; j<i; j++)
                    line += words[j] + " ";
                int res_spaces = spaces - (i-start);
                line += words[i] + string(res_spaces, ' ');
            }
            result.push_back(line);
            i++;
        }
        return result;
    }
};


// Reference solution:
// 思路：
// 我们进行一行一行地处理：首先要做的就是确定每一行能放下的单词数，这个不难，
// 就是比较n个单词的长度和加上n - 1个空格的长度跟给定的长度L来比较即可，找到了一行能放下的单词个数，
// 然后计算出这一行存在的空格的个数，是用给定的长度L减去这一行所有单词的长度和。
// 得到了空格的个数之后，就要在每个单词后面插入这些空格，这里有两种情况，比如某一行有两个单词"to" 和 "a"，给定长度L为6，
// 如果这行不是最后一行，那么应该输出"to   a"，如果是最后一行，则应该输出 "to a  "，所以这里需要分情况讨论，
// 最后一行的处理方法和其他行之间略有不同。最后一个难点就是，如果一行有三个单词，这时候中间有两个空，如果空格数不是2的倍数，
// 那么左边的空间里要比右边的空间里多加入一个空格，那么我们只需要用总的空格数除以空间个数，能除尽最好，说明能平均分配，
// 除不尽的话就多加个空格放在左边的空间里，以此类推.
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res;
        int i = 0;
        while (i < words.size()) {
            int j = i, len = 0;
            while (j < words.size() && len + words[j].size() + j - i <= L) {
                len += words[j++].size();
            }
            string out;
            int space = L - len;
            for (int k = i; k < j; ++k) {
                out += words[k];
                if (space > 0) {
                    int tmp;
                    if (j == words.size()) { 
                        if (j - k == 1) tmp = space;
                        else tmp = 1;
                    } else {
                        if (j - k - 1 > 0) {
                            if (space % (j - k - 1) == 0) tmp = space / (j - k - 1);
                            else tmp = space / (j - k - 1) + 1;
                        } else tmp = space;
                    }
                    out.append(tmp, ' ');
                    space -= tmp;
                }
            }
            res.push_back(out);
            i = j;
        }
        return res;
    }
};