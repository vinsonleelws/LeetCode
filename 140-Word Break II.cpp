Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

    The same word in the dictionary may be reused multiple times in the segmentation.
    You may assume the dictionary does not contain duplicate words.

Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]

Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.

Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]

// Backtracking
// 基本思路是采用递归。为了避免解重复的子问题，使用一个哈希表，将中间结果保存起来，如果遇到已知的求解将直接查表返回，以空间换时间。
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string>> m;
        return wordBreakDFS(s, wordDict, m);
    }
    
    vector<string> wordBreakDFS(string s, vector<string>& wordDict, unordered_map<string, vector<string>>& m) {
        if (m.count(s)) 
            return m[s];
        if (s.empty()) 
            return {""};
        vector<string> res;
        for (string word : wordDict) 
        {
            if (s.substr(0, word.size()) != word) 
                continue;
            vector<string> rem = wordBreakDFS(s.substr(word.size()), wordDict, m);
            for (string str : rem) 
                res.push_back(word + (str.empty() ? "" : " ") + str);
            
        }
        return m[s] = res;
    }
};

// 另一种写法：
// 我们也可以将将主函数本身当作递归函数，这样就不用单独的使用一个递归函数了，不过我们的HashMap必须是全局了，写在外部就好了
class Solution {
public:
    unordered_map<string, vector<string>> m;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (m.count(s)) return m[s];
        if (s.empty()) return {""};
        vector<string> res;
        for (string word : wordDict) {
            if (s.substr(0, word.size()) != word) continue;
            vector<string> rem = wordBreak(s.substr(word.size()), wordDict);
            for (string str : rem) {
                res.push_back(word + (str.empty() ? "" : " ") + str);
            }
        }
        return m[s] = res;
    }
};