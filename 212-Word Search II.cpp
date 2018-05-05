 Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]

Return ["eat","oath"]. 

Note:
You may assume that all inputs are consist of lowercase letters a-z. 

class Solution {
public:
    struct TrieNode
    {
        TrieNode* child[26];
        string str;
        TrieNode(): str("")
        {
            for(auto &c:child)
                c=NULL;
        }
    };
    
    struct Trie 
    {
        TrieNode *root;
        Trie() : root(new TrieNode()) {}
        void insert(string s) {
            TrieNode *p = root;
            for (auto &x : s) {
                int i = x - 'a';
                if (!p->child[i]) 
                    p->child[i] = new TrieNode();
                p = p->child[i];
            }
            p->str = s;
        }
    };

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        if (words.empty() || board.empty() || board[0].empty()) 
            return result;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        Trie T;
        for (auto &w : words) 
            T.insert(w);
        for (int i = 0; i < m; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                if (T.root->child[board[i][j] - 'a']) 
                    findWordsDFS(board, T.root->child[board[i][j] - 'a'], i, j, visit, result);
            }
        }
        return result;
    }
    
    void findWordsDFS(const vector<vector<char>> &board, TrieNode *p, int i, int j, vector<vector<bool>>& visit, vector<string> &result) { 
        if (!p->str.empty()) 
        {
            result.push_back(p->str);
            p->str.clear();
        }
        
        // 注意找到一个结果后，仍可继续找其它结果。

        int d[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        visit[i][j] = true;
        for (auto a : d) {
            int nx = a[0] + i, ny = a[1] + j;
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && !visit[nx][ny] && p->child[board[nx][ny] - 'a']) {
                findWordsDFS(board, p->child[board[nx][ny] - 'a'], nx, ny, visit, result);
            }
        }
        visit[i][j] = false;
        
    }
};

class Solution {
public:
    struct TrieNode
    {
        TrieNode* child[26];
        string str;
        TrieNode(): str("")
        {
            for(auto &c:child)
                c=NULL;
        }
    };
    
    struct Trie 
    {
        TrieNode *root;
        Trie() : root(new TrieNode()) {}
        void insert(string s) {
            TrieNode *p = root;
            for (auto &x : s) {
                int i = x - 'a';
                if (!p->child[i]) 
                    p->child[i] = new TrieNode();
                p = p->child[i];
            }
            p->str = s;
        }
    };

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        if (words.empty() || board.empty() || board[0].empty()) 
            return result;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        Trie T;
        for (auto &w : words) 
            T.insert(w);
        for (int i = 0; i < m; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                if (T.root->child[board[i][j] - 'a']) 
                    findWordsDFS(board, T.root->child[board[i][j] - 'a'], i, j, visit, result);
            }
        }
        return result;
    }
    
    void findWordsDFS(const vector<vector<char>> &board, TrieNode *p, int i, int j, vector<vector<bool>>& visit, vector<string> &result) { 
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || visit[i][j]==true || p->child[board[i][j]-'a']==NULL)
            return;
        
        if (!p->str.empty()) 
        {
            result.push_back(p->str);
            p->str.clear();
        }

        visit[i][j] = true;
        if(i+1<board.size())
            findWordsDFS(board, p->child[board[i+1][j] - 'a'], i+1, j, visit, result);
        if(i-1>=0)
            findWordsDFS(board, p->child[board[i-1][j] - 'a'], i-1, j, visit, result);
        if(j+1<board[0].size())
            findWordsDFS(board, p->child[board[i][j+1] - 'a'], i, j+1, visit, result); 
        if(j-1>=0)
            findWordsDFS(board, p->child[board[i][j-1] - 'a'], i, j-1, visit, result);
        visit[i][j] = false;

    }
};