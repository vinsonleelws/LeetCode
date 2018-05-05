Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.

Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true

Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false

// My solution 1:
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

// My solution 2:
// 思路：采用两次二分查找的方法：
// (1) 先确定目标数字的所属行；
// (2) 在所属行中用简单二分查找是否存在目标值即可。

// 需注意的是：目标数字可能不存在所属行，
// 这时的判断条件是 mid<0 || target>matrix[mid][n-1]，
// 即它的所属行小于0或大于最大行数，这时直接返回false.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        
        int m=matrix.size(), n=matrix[0].size();
        
        // binary search in rows
        int start = 0;
        int end = m-1;
        int mid = (start+end)>>1;
        while(start<=end && mid>=0)
        {
            if(target == matrix[mid][0])
                return true;
            else if(target<matrix[mid][0])
                end = mid-1;
            else
            {
                if(target==matrix[mid][n-1])
                    return true;
                else if(target<matrix[mid][n-1])
                    break;
                else
                    start = mid+1;
            }
            mid = (start+end)>>1;
        }
        if(mid<0 || target > matrix[mid][n-1])
            return false;
        
        // binary search in cols
        int row = mid;
        start = 0;
        end = n-1;
        mid = (start+end)>>1;
        while(start<=end)
        {
            if(target == matrix[row][mid])
                return true;
            else if(target < matrix[row][mid])
                end = mid-1;
            else
                start = mid+1;
            
            mid = (start+end)>>1;
        }
        
        return false;
    }
};

// Other reference solution:
// 这道题也可以使用一次二分查找法，如果我们按S型遍历该二维数组，可以得到一个有序的一维数组，
// 那么我们只需要用一次二分查找法，而关键就在于坐标的转换，如何把二维坐标和一维坐标转换是关键点，
// 把一个长度为n的一维数组转化为m*n的二维数组(m*n = n)后，那么原一维数组中下标为i的元素将出现在
// 二维数组中的[i/n][i%n]的位置.
// One pass binary search
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        if (target < matrix[0][0] || target > matrix.back().back()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[mid / n][mid % n] == target) return true;
            else if (matrix[mid / n][mid % n] < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};