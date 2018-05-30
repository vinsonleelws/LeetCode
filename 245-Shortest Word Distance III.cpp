This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.

Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “makes”, word2 = “coding”, return 1.
Given word1 = "makes", word2 = "makes", return 3.

Note:
You may assume word1 and word2 are both in the list. 


// 这道题增加了一个条件：word1和word2可能一样，而且它们表示的是单词列表中的两个不同个体。
// Reference solution:
// #1
// 使用两个变量p1和p2分别记录word1和word2的位置，由于word1和word2可以相等，我们要对word1和word2是否的相等的情况分开处理，如果相等了，由于p1和p2会相同，
// 所以我们需要一个变量t来记录p1的上一个位置，这样如果t不为-1，且和当前的p1不同（说明找到了第二个或更多个相同词），我们可以更新结果，如果word1和word2不
// 等，那么还是按"243-Shortest Word Distance"的方法做。
class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int p1 = -1, p2 = -1, res = INT_MAX;
        for (int i = 0; i < words.size(); ++i) {
            int t = p1;
            if (words[i] == word1) p1 = i;
            if (words[i] == word2) p2 = i;
            if (p1 != -1 && p2 != -1) {
                if (word1 == word2 && t != -1 && t != p1) {
                    res = min(res, abs(t - p1));
                } else if (p1 != p2) {
                    res = min(res, abs(p1 - p2));
                }
            }
        }
        return res;
    }
};

// #2
// 上述代码其实可以优化一下，我们并不需要变量t来记录上一个位置，我们将p1初始化为数组长度，p2初始化为数组长度的相反数，然后当word1和word2相等的情况，我们用p1来保存p2的结果，
// p2赋为当前的位置i，这样我们就可以更新结果了，如果word1和word2不相等，则还跟原来的做法一样.
class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int p1 = words.size(), p2 = -words.size(), res = INT_MAX;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1) p1 = word1 == word2 ? p2 : i;
            if (words[i] == word2) p2 = i;
            res = min(res, abs(p1 - p2));
        }
        return res;
    }
};


// #3
// 我们再来看一种更进一步优化的方法，只用一个变量idx，这个idx的作用就相当于记录上一次的位置，当前idx不等-1时，说明当前i和idx不同，然后我们在word1和word2相同或者words[i]和words[idx]相同
// 的情况下更新结果，最后别忘了将idx赋为i
class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int idx = -1, res = INT_MAX;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1 || words[i] == word2) {
                if (idx != -1 && (word1 == word2 || words[i] != words[idx])) {
                    res = min(res, i - idx);
                }
                idx = i;
            }
        }
        return res;
    }
};
