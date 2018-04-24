You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

Example 1:

Input:
  s = "barfoothefoobarman",
  words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.

Example 2:

Input:
  s = "wordgoodstudentgoodword",
  words = ["word","student"]
Output: []


// 采用两个哈希表：一个用于存储所要串联的所有单词，一个用于记录在字符串中出现的单词。
// 遍历字符串，停止条件为当剩余字符个数小于单词集里所有字符的长度（节省时间）。
// 每次找出给定单词长度的子串，看其是否在第一个哈希表里，如果没有，则break，如果有，
// 则加入第二个哈希表，但相同的词只能出现一次，如果多了，也break。
// 如果正好匹配完给定单词集里所有的单词，则把i存入结果中.

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if(s.empty() || words.empty())
            return result;
        
        int s_len = s.size();
        int w_num = words.size();
        int w_len = words[0].size();
        if(s_len < w_num*w_len)
            return result;
        
        unordered_map<string, int> m1;
        for(auto &x: words)
            m1[x]++;
        
        for(int i=0; i <= s_len-w_num*w_len; i++)
        {
            unordered_map<string, int> m2;
            int j=0;
            for(; j<w_num; j++)
            {
                string str = s.substr(i+j*w_len, w_len);
                if(m1.find(str)==m1.end())
                    break;
                
                m2[str]++;
                
                if(m2[str]>m1[str])
                    break;
            }
            if(j==w_num)
                result.push_back(i);
        }
            
        return result;
    }
};