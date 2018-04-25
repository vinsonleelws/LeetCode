The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example:

Input: 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

class Solution {
public:
    int totalNQueens(int n) {
        int result=0;
        vector<int> row_pos(n, -1);
        totalNQueensDFS(n, 0, row_pos, result);
        return result;
    }
    
    void totalNQueensDFS(const int& n, int row, vector<int>& row_pos, int& result)
    {
        if(row == n)
            result++;
        else
        {
            for(int col=0; col<n; col++)
            {
                row_pos[row] = col;
                if(isValid(row, col, row_pos))
                    totalNQueensDFS(n, row+1, row_pos, result);
                row_pos[row] = -1;
            }
        }
    }
    
    bool isValid(const int& row, const int& cur_pos, const vector<int>& row_pos)
    {
        for(int i=0; i<row; i++)
        {
            if(row_pos[i] == cur_pos || row-i == abs(cur_pos - row_pos[i]))
                return false;
        }
        return true;
    }
};