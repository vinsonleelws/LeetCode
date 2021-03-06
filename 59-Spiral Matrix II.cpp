/* Given a positive integer n, generate a square matrix filled with elements from 1 to n^2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
 */

// 59-生成螺旋数组
// 找规律


// m x n的矩阵中算出按螺旋顺序的环数计算公式是：min(m+1, n+1) / 2
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> matrix(n, vector<int>(n, 0));
		if (n == 0)
			return matrix;
		int times = (n + 1) >> 1;
		int curNum = 1;
		for (int i = 0; i < times; i++)
		{
			int start = i;
			int end = n - 1 - i;
			// for upper rows
			for (int col = start; col <= end; col++)
				matrix[start][col] = curNum++;

			// for right cols
			if (start + 1 <= end)
			{
				for (int row = start + 1; row <= end; row++)
					matrix[row][end] = curNum++;
			}

			// for lower rows
			if (end - 1 >= start && end - 1 >= start)
			{
				for (int col = end - 1; col >= start; col--)
					matrix[end][col] = curNum++;
			}

			// for left cols
			if (end - 1 > start && end > start)
			{
				for (int row = end - 1; row > start; row--)
					matrix[row][start] = curNum++;
			}
		}
		return matrix;
	}
};