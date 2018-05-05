Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example:

Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6


// Reference solution:
// #1
// 此题是之前那道 Largest Rectangle in Histogram 直方图中最大的矩形的扩展。这里二维矩阵每一层向上
// 都可以看做一个直方图，输入矩阵有多少行，就可以形成多少个直方图，对每个直方图都调用 Largest Rectangle 
// in Histogram 直方图中最大的矩形中的方法，就可以得到最大的矩形面积。关键在于将每一层构成直方图，
// 由于题目限定了输入矩阵的字符只有 '0' 和 '1' 两种，所以处理起来也相对简单。方法是，对于每一个点，
// 如果是‘0’，则赋0，如果是 ‘1’，就赋 之前的height值加上1。

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        int result = 0;
        vector<int> height(n + 1, 0);
        for (int i = 0; i < m; ++i) 
        {
            stack<int> s;
            for (int j = 0; j < n + 1; ++j) 
            {
                if (j < n) 
                    height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0;
                
                while (!s.empty() && height[s.top()] >= height[j]) 
                {
                    int cur = s.top(); 
                    s.pop();
                    result = max(result, height[cur] * (s.empty() ? j : (j - s.top() - 1)));
                }
                s.push(j);
            }
        }
        return result;
    }
};


// #2
// 基于DP的方法：
The DP solution proceeds row by row, starting from the first row. Let the maximal rectangle area at row i and column j be computed by [right(i,j) - left(i,j)]*height(i,j).

All the 3 variables left, right, and height can be determined by the information from previous row, and also information from the current row. 
So it can be regarded as a DP solution. The transition equations are:

left(i,j) = max(left(i-1,j), cur_left), cur_left can be determined from the current row

right(i,j) = min(right(i-1,j), cur_right), cur_right can be determined from the current row

height(i,j) = height(i-1,j) + 1, if matrix[i][j]=='1';

height(i,j) = 0, if matrix[i][j]=='0'

For example:

0 0 0 1 0 0 0 
0 0 1 1 1 0 0 
0 1 1 1 1 1 0

The vector "left" and "right" from row 0 to row 2 are as follows

row 0:
h: 0 0 0 1 0 0 0
l: 0 0 0 3 0 0 0
r: 7 7 7 4 7 7 7

row 1:
h: 0 0 1 2 1 0 0 
l: 0 0 2 3 2 0 0
r: 7 7 5 4 5 7 7 

row 2:
h: 0 1 2 3 2 1 0
l: 0 1 2 3 2 1 0
r: 7 6 5 4 5 6 7


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int res = 0, m = matrix.size(), n = matrix[0].size();
        vector<int> height(n, 0), left(n, 0), right(n, n);
        for (int i = 0; i < m; ++i) {
            int cur_left = 0, cur_right = n;
            for (int j = 0; j < n; ++j) {           // compute height (can do this from either side)
                if (matrix[i][j] == '1') ++height[j];
                else height[j] = 0;
            }
            for (int j = 0; j < n; ++j) {           // compute left (from left to right)
                if (matrix[i][j] == '1') left[j] = max(left[j], cur_left);
                else {left[j] = 0; cur_left = j + 1;}
            }
            for (int j = n - 1; j >= 0; --j) {      // compute right (from right to left)
                if (matrix[i][j] == '1') right[j] = min(right[j], cur_right);
                else {right[j] = n; cur_right = j;}
            }
            for (int j = 0; j < n; ++j) {            // compute the area of rectangle (can do this from either side)
                res = max(res, (right[j] - left[j]) * height[j]);
            }
        }
        return res;
    }
};

// 可以通过合并一些for循环，使得运算速度更快一些:
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int res = 0, m = matrix.size(), n = matrix[0].size();
        vector<int> height(n, 0), left(n, 0), right(n, n);
        for (int i = 0; i < m; ++i) {
            int cur_left = 0, cur_right = n;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    ++height[j];
                    left[j] = max(left[j], cur_left);
                } else {
                    height[j] = 0;
                    left[j] = 0;
                    cur_left = j + 1;
                }
            }
            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], cur_right);
                } else {
                    right[j] = n;
                    cur_right = j;
                }
                res = max(res, (right[j] - left[j]) * height[j]);
            }
        }
        return res;
    }
};

