/*Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1

Example 2:

Input:
11000
11000
00100
00011

Output: 3*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
    }
};

// 岛屿数量
// DFS + visit数组

// DFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty())
            return 0;
        
        int m = grid.size(), n = grid[0].size();
        int result = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == '1' && !visited[i][j])  // 注意此处必须写grid[i][j] == '1'而不能简写成grid[i][j]，因为当grid[i][j] == '0'时其bool值也为1.
                {
                    numIslandsDFS(grid, visited, i, j);
                    result++;
                }
            }
        
        return result;
    }
    
    void numIslandsDFS(const vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size())
            return;
        
        if(grid[i][j] == '1' && !visited[i][j])
        {
            visited[i][j] = true;
            numIslandsDFS(grid, visited, i+1, j);
            numIslandsDFS(grid, visited, i-1, j);
            numIslandsDFS(grid, visited, i, j+1);
            numIslandsDFS(grid, visited, i, j-1);
        }
    }
};