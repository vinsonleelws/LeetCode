Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.


// 遍历一次数组的解法：
// 我们用两个变量p1,p2初始化为-1，然后遍历数组，遇到单词1，就将其位置存在p1里，若遇到单词2，就将其位置存在p2里，如果此时p1, p2都不为-1了，那么我们更新结果
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int p1 = -1, p2 = -1, res = INT_MAX;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1) p1 = i;
            else if (words[i] == word2) p2 = i;
            if (p1 != -1 && p2 != -1) res = min(res, abs(p1 - p2));
        }
        return res;
    }
};

// 下面这种方法只用一个辅助变量idx，初始化为-1，然后遍历数组，如果遇到等于两个单词中的任意一个的单词，我们在看idx是否为-1，若不为-1，且指向的单词和当前遍历到的单词不同，我们更新结果
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int idx = -1, res = INT_MAX;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1 || words[i] == word2) {
                if (idx != -1 && words[idx] != words[i]) {
                    res = min(res, i - idx);
                }
                idx = i;
            }
        }
        return res;
    }
};
