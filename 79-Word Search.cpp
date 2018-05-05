Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.

// 思路：这道题是典型的深度优先遍历DFS的应用，原二维数组就像是一个迷宫，可以上下左右四个方向行走，
// 我们以二维数组中每一个数都作为起点和给定字符串做匹配，利用一个和原数组等大小的bool型visited数组来记录
// 当前位置是否已经被访问过，因为题目要求一个cell只能被访问一次。如果二维数组board的当前字符和目标字符串
// word对应的字符相等，则对其上下左右四个邻字符分别调用DFS的递归函数，
// 只要有一个返回true，那么就表示可以找到对应的字符串，否则就不能找到.
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || board[0].empty() || word.empty())
            return false;
        int m=board.size(), n=board[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                if(existDFS(board, word, visited, 0, i, j))
                    return true;
            }
        return false;
    }
    
    bool existDFS(const vector<vector<char>>& board, const string& word, vector<vector<bool> > visited, int index, int i, int j)
    {
        if(index==word.size())
            return true;
        else
        {
            if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || visited[i][j]==true || word[index] != board[i][j])
                return false;
            else
            {
                visited[i][j] = true;
                bool flag =  existDFS(board, word, visited, index+1, i+1, j) || existDFS(board, word, visited, index+1, i, j+1) || \
                existDFS(board, word, visited, index+1, i-1, j) ||existDFS(board, word, visited, index+1, i, j-1);
                visited[i][j] = false;
                return flag;
            }
        }
    }
};