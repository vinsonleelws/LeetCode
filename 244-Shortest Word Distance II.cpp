This is a follow up of Shortest Word Distance. The only difference is now you are given the list of words and your method will be called repeatedly many times with different parameters. How would you optimize it?

Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

// 这道题是之前"243-Shortest Word Distance"的拓展，不同的是这次我们需要多次调用求最短单词距离的函数。
// 为了更加高效地实现，我们用哈希表来建立每个单词和其所有出现的位置的映射，然后在找最短单词距离时，我们只需要取出该单词在哈希表中映射的位置数组进行两两比较即可
// Reference solution:
// #1
class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            m[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int res = INT_MAX;
        for (int i = 0; i < m[word1].size(); ++i) {
            for (int j = 0; j < m[word2].size(); ++j) {
                res = min(res, abs(m[word1][i] - m[word2][j]));
            }
        }
        return res;
    }
    
private:
    unordered_map<string, vector<int> > m;
};

// #2
// 我们可以优化上述的代码，使查询的复杂度由上面的O(MN)变为O(M+N)，其中M和N为两个单词的长度，我们需要两个指针i和j来指向位置数组中的某个位置，开始初始化都为0，然后比较位置数组中的数字，
// 将较小的一个的指针向后移动一位，直至其中一个数组遍历完成即可
class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            m[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int i = 0, j = 0, res = INT_MAX;
        while (i < m[word1].size() && j < m[word2].size()) {
            res = min(res, abs(m[word1][i] - m[word2][j]));
            m[word1][i] < m[word2][j] ? ++i : ++j;
        }
        return res;
    }
    
private:
    unordered_map<string, vector<int> > m;
};