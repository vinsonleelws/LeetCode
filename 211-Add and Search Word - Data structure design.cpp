/*Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)

search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true*/

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
 

// 添加和查找单词 - 数据结构设计  [M]
// Backtracking, Design, Trie


// --------------------------------------------------------------------

// 一般要在字典中搜索字符串，最简单而有效率的方式还是使用字典树结构，
// 与一般字典树search不一样的地方是，这道题里面'.'可以代替任意字符，
// 所以一旦有了'.'，就需要查找所有的子树，只要有一个返回true，整个
// search函数就返回true。其他部分跟"208-Implement Trie (Prefix Tree)"
// 实现字典树没有太大区别。
class WordDictionary {
public:
    struct TrieNode {
    public:
        TrieNode *child[26];
        bool isWord;
        TrieNode() : isWord(false) {
            for (auto &a : child) 
                a = NULL;
        }
    };

    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *p = root;
        for (auto &a : word) 
        {
            int i = a - 'a';
            if (!p->child[i]) 
                p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchWord(word, root, 0);
    }
    
    bool searchWord(string &word, TrieNode *p, int i) {
        if (i == word.size()) 
            return p->isWord;
        if (word[i] == '.') 
        {
            for (auto &a : p->child) 
            {
                if (a && searchWord(word, a, i + 1)) 
                    return true;
            }
            return false;
        } 
        else 
        {
            return p->child[word[i] - 'a'] && searchWord(word, p->child[word[i] - 'a'], i + 1);
        }
    }    
private:
    TrieNode* root;
};