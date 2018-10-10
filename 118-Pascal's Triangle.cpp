/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
 */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
    }
};

// [1],
// [1,1],
// [1,2,1],
// [1,3,3,1],
// [1,4,6,4,1]

// 杨辉三角  (E)
// DP
// 递推公式：result[i][j] = result[i - 1][j - 1] + result[i - 1][j]
// 边界：result[i][0] = 1， result[i][i] = 1
// 

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		if (numRows < 1)
			return {};

		vector<vector<int>> result(numRows, vector<int>(1, 0));
		result[0][0] = 1;
		for (int i = 1; i < numRows; i++)
		{
			result[i][0] = 1;
			for (int j = 1; j < i; j++)
				result[i].push_back(result[i - 1][j - 1] + result[i - 1][j]);
			result[i].push_back(1);
		}

		return result;
	}
};