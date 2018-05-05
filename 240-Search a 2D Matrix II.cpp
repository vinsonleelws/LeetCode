Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted in ascending from left to right.
    Integers in each column are sorted in ascending from top to bottom.

For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

Given target = 5, return true.

Given target = 20, return false.

// My solution:
// 思路：首先选取右上角的数字，与target比较：
// 如果target比较小，则剔除该列，反之剔除该行.
// PS: 我们也可以选取左下角的数字。但这种方法不能选取左上角数字或右下角数字
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        
        int m=matrix.size(), n=matrix[0].size();
        int i=0;
        int j=n-1;  // from up right corner
        while(i<m && j>=0)
        {
            // move down
            while(i<m && target > matrix[i][j])
                i++;
            if(i==m)
                return false;
            else if(target == matrix[i][j])
                return true;
            
            // move left
            while(j>=0 && target < matrix[i][j])
                j--;
            if(j<0)
                return false;
            else if(target == matrix[i][j])
                return true;
        }
        
        return false;
    }
};

// [[3, 3, 8, 13,13,18],
//  [4, 5, 11,13,18,20],
//  [9, 9, 14,15,23,23],
//  [13,18,22,22,25,27],
//  [18,22,23,28,30,33],
//  [21,25,28,30,35,35],
//  [24,25,33,36,37,40]]
// 21
// true