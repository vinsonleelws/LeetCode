The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.

// 经典解法为回溯递归，一层一层的向下扫描，需要用到一个row_pos数组，其中row_pos[i]表示第i行皇后的位置，初始化为-1，
// 然后从第0开始递归，每一行都一次遍历各列，判断如果在该位置放置皇后会不会有冲突，以此类推，当到最后一行的皇后放好后，
// 一种解法就生成了，将其存入结果result中，然后再还会继续完成搜索所有的情况
// 关于判断是否合法：合法位置需保证：
// (1) 当前行的放置位置不等于前面所有行的放置位置；
// (2) 当前行与前面某一行的行差不等于它们的列差（保证对角线上的位置不冲突）.

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<int> row_pos(n, -1);
        solveNQueensDFS(n, 0, row_pos, result);
        return result;
    }
    void solveNQueensDFS(const int& n, int row, vector<int>& row_pos, vector<vector<string>>& result)
    {
        if(row == n)
        {
            vector<string> solution(n, string(n, '.'));
            for(int i=0; i<n; i++)
                    solution[i][row_pos[i]] = 'Q';
            result.push_back(solution);
        }
        else
        {
            for(int col=0; col<n; col++)
            {
                row_pos[row] = col;
                if(isValid(row, col, row_pos))
                    solveNQueensDFS(n, row+1, row_pos, result);
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