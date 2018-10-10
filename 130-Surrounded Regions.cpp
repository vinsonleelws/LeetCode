/*Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'.
Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'.
Two cells are connected if they are adjacent cells connected horizontally or vertically.
*/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
    }
};

// 包围区域（将被X包围住的O变成X）  [M]
// DFS


// Reference solution:
// 这题有点像围棋，将被X包住的O都变成X，但边界上的O以及与边界O相邻的其他O除外。基本思路是使用DFS：
// 首先扫面矩阵的四条边，如果有O，则用DFS遍历，将所有连着的O都变成另一个特殊字符，比如$，这样剩下的O都是被包围的，把这些O都变成X，并把$变回O就行了。
class Solution {
public:
    void solve(vector<vector<char> >& board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if ((i == 0 || i == board.size() - 1 || j == 0 || j == board[i].size() - 1) && board[i][j] == 'O')
                    solveDFS(board, i, j);
            }
        }

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == 'O') 
                    board[i][j] = 'X';
                if (board[i][j] == '$') 
                    board[i][j] = 'O';
            }
        }
    }
    void solveDFS(vector<vector<char> > &board, int i, int j) {
        if (board[i][j] == 'O') {
            board[i][j] = '$';
            if (i > 0 && board[i - 1][j] == 'O')
                solveDFS(board, i - 1, j);
            if (j < board[i].size() - 1 && board[i][j + 1] == 'O')
                solveDFS(board, i, j + 1);
            if (i < board.size() - 1 && board[i + 1][j] == 'O')
                solveDFS(board, i + 1, j);
            if (j > 0 && board[i][j - 1] == 'O')
                solveDFS(board, i, j - 1);
        }
    }
};

// 另一种写法：
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    if (board[i][j] == 'O') dfs(board, i , j);
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '$') board[i][j] = 'O';
            }
        }
    }
    void dfs(vector<vector<char>> &board, int x, int y) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> dir{{0, -1}, { -1, 0}, {0, 1}, {1, 0}};
        board[x][y] = '$';
        for (int i = 0; i < dir.size(); ++i) {
            int dx = x + dir[i][0], dy = y + dir[i][1];
            if (dx >= 0 && dx < m && dy > 0 && dy < n && board[dx][dy] == 'O') {
                dfs(board, dx, dy);
            }
        }
    }
};