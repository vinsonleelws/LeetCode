Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"

Note:

    If there is no such window in S that covers all characters in T, return the empty string "".
    If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
    

// 思路：使用哈希表，其中key是t中的字符，value是该字符出现的次数。
// - 最开始先扫描一遍t，把对应的字符及其出现的次数存到哈希表中。
// - 然后遍历s，遇到t中的字符，就把对应的哈希表中的value减一，直到包含了t中的所有的字符(用一个变量count计数，只在value自减后>=0的情况+1)，纪录一个字串并更新最小字串值。
// - 将子窗口的左边界向右移，略掉不在t中的字符，如果某个在t中的字符出现的次数大于哈希表中的value，则也可以跳过该字符。

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty())
            return "";
        
        string result;
        int low=0, count=0, minCount = s.length()+1;
        unordered_map<char, int> cMap;
        for(int i=0; i<t.length(); i++)
            cMap[t[i]]++;
        
        for(int i=0; i<s.length(); i++)
        {
            if(cMap.find(s[i])!=cMap.end())
            {
                cMap[s[i]]--;
                if(cMap[s[i]]>=0)
                    count++;
            
                while(count == t.size())
                {
                    if(i-low+1 < minCount)
                    {
                        minCount = i-low+1;
                        result = s.substr(low, minCount);
                    }    
                    if(minCount == t.size())
                        return result;

                    if(cMap.find(s[low])!=cMap.end())
                    {
                        cMap[s[low]]++;
                        if(cMap[s[low]]>0)
                            count--;
                    }
                    low++;
                }   
            }
        }
        return result;
    }
};