/* Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input:
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output:
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]

Example 2:

Input:
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output:
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]

Follow up:

    A straight forward solution using O(mn) space is probably a bad idea.
    A simple improvement uses O(m + n) space, but still not the best solution.
    Could you devise a constant space solution?
 */

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

    }
};

// 73-矩阵赋零  [M]
// Trick

// 解法比较：
// 空间复杂度为O(mn)的直接解法：直接新建一个和matrix等大小的矩阵，然后一行一行的扫，只要有0，
// 就将新建的矩阵的对应行全赋0，行扫完再扫列，然后把更新完的矩阵赋给matrix即可，这个算法的空间复杂度太高。
// 将其优化到O(m+n)的方法是：用一个长度为m的一维数组记录各行中是否有0，用一个长度为n的一维数组记录各列中是否有0，
// 最后直接更新matrix数组即可。

// 空间复杂度为O(1)的解法：
// 思路：首先使用两个变量firstRowZero和firstColZero来分别记录第一行和第一列是否有0元素。然后用原数组的第一行第一列来记录各行各列是否有0：
// 总步骤如下：
// - 先扫描第一行第一列，如果有0，则将各自的flag设置为true;
// - 然后扫描除去第一行第一列的整个数组，如果有0，则将对应的第一行和第一列的数字赋0，比如matrix[i][j]==0，则令matrix[0][j] = 0; matrix[i][0] = 0;;
// - 再次遍历除去第一行第一列的整个数组，如果对应的第一行和第一列的数字有一个为0，则将当前值赋0;
// - 最后根据第一行第一列的flag来更新第一行第一列.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return;
        int m = matrix.size(), n = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;

        for (int i = 0; i < n; i++)
            if (matrix[0][i] == 0)
            {
                firstRowZero = true;
                break;
            }
        for (int i = 0; i < m; i++)
            if (matrix[i][0] == 0)
            {
                firstColZero = true;
                break;
            }

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }

        if (firstRowZero)
        {
            for (int i = 0; i < n; i++)
                matrix[0][i] = 0;
        }

        if (firstColZero)
        {
            for (int j = 0; j < m; j++)
                matrix[j][0] = 0;
        }
    }
};