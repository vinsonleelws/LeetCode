Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

    Only one letter can be changed at a time.
    Each transformed word must exist in the word list. Note that beginWord is not a transformed word.

Note:

    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.
    You may assume no duplicates in the word list.
    You may assume beginWord and endWord are non-empty and are not the same.

Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.

// BFS
// 参考思路：
// 这道词句阶梯的问题给了我们一个单词字典，里面有一系列很相似的单词，然后给了一个起始单词和一个结束单词，每次变换只能改变一个单词，
// 并且中间过程的单词都必须是单词字典中的单词，让我们求出最短的变化序列的长度。这里用到了两个高级数据结构unordered_map和queue，
// 即哈希表和队列，其中哈希表是记录单词和目前序列长度之间的映射，而队列的作用是保存每一个要展开的单词。首先把起始单词映射为1，
// 把起始单词排入队列中，开始队列的循环，取出队首词，然后对其每个位置上的字符，用26个字母进行替换，如果此时和结尾单词相同了，
// 就可以返回取出词在哈希表中的值加一。如果替换词在字典中存在但在哈希表中不存在，则将替换词排入队列中，并在哈希表中的值映射为之前取出词加一。如果循环完成则返回0.
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_map<string, int> m;
        queue<string> q;
        m[beginWord] = 1;
        q.push(beginWord);
        while (!q.empty()) 
        {
            string word = q.front(); q.pop();
            for (int i = 0; i < word.size(); ++i) 
            {
                string newWord = word;
                for (char ch = 'a'; ch <= 'z'; ++ch) 
                {
                    newWord[i] = ch;
                    if (dict.count(newWord) && newWord == endWord) 
                        return m[word] + 1;
                    if (dict.count(newWord) && !m.count(newWord)) 
                    {
                        q.push(newWord);
                        m[newWord] = m[word] + 1;
                    }   
                }
            }
        }
        return 0;
    }
};