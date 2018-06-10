/* 
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 */
 

// 54-螺旋数组
// 找规律 
 
// 思路：
// m x n的矩阵中算出按螺旋顺序的环数计算公式是：min(m+1, n+1) / 2

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.empty() || matrix[0].empty())
            return result;    
        int m = matrix.size();
        int n = matrix[0].size();
        int times = min(m+1, n+1)>>1;
        for(int i=0; i<times; i++)
        {
            int start = i;
            int endCol = n-1-i;
            int endRow = m-1-i;
            // for upper rows
            for(int col=start; col<=endCol; col++)
                result.push_back(matrix[start][col]);
            
            // for right cols
            if(start+1<=endRow)
            {
                for(int row=start+1; row<=endRow; row++)
                    result.push_back(matrix[row][endCol]);
            }

            // for lower rows
            if(endCol-1>=start && endRow-1>=start)
            {
                for(int col=endCol-1; col>=start; col--)
                    result.push_back(matrix[endRow][col]);
            }
            
            // for left cols
            if(endRow-1>start && endCol>start)
            {
                for(int row=endRow-1; row>start; row--)
                    result.push_back(matrix[row][start]);
            }
        }
        return result;
    }
};