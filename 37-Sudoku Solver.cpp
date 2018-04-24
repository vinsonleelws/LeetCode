Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

    Each of the digits 1-9 must occur exactly once in each row.
    Each of the digits 1-9 must occur exactly once in each column.
    Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

Empty cells are indicated by the character '.'.


A sudoku puzzle...


...and its solution numbers marked in red.

Note:

    The given board contain only digits 1-9 and the character '.'.
    You may assume that the given Sudoku puzzle will have a single unique solution.
    The given board size is always 9x9.


// 基于回溯法。
// 思路：对于每个需要填数字的格子带入1到9，每代入一个数字都判定其是否合法，如果合法就继续下一次递归，
// 结束时把数字设回'.'，判断新加入的数字是否合法时，只需要判定当前数字是否合法，不需要判定这个数组是否为数独数组，
// 因为之前加进的数字都是合法的，这样可以使程序更加高效一些.

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if(board.size()!=9 || board[0].size()!=9)
            return;
        
        solveSudokuDFS(board, 0, 0);
        
    }
    bool solveSudokuDFS(vector<vector<char>>& board, int i, int j){
        if(j>8)
        {
            i++;
            j=0;
        }
        
        if(i>8)
            return true;
        
        if(board[i][j]=='.')
        {
            for(char num='1'; num<='9'; num++)
            {
                if(isValid(board, i, j, num))
                {
                    board[i][j] = num;
                    if(solveSudokuDFS(board, i, j+1))  // 关键
                        return true;
                    board[i][j] = '.';
                }
            }
        }
        else
            return solveSudokuDFS(board, i, j+1);
        
        return false;
        
    }
    bool isValid(vector<vector<char> > &board, const int i, const int j, const char num) {
        for(int row = 0; row<board.size(); row++)
            if(row!=i && board[row][j] == num)
                return false;
        
        for(int col = 0; col<board[0].size(); col++)
            if(col!=j && board[i][col]==num)
                return false;
        
        for(int r=(i/3)*3; r<(i/3)*3+3; r++)
            for(int c=(j/3)*3; c<(j/3)*3+3; c++)
                if((r!=i || c!=j) && board[r][c]==num)
                    return false;
                
        return true;
    }
};