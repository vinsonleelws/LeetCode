/*Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Return 4. 
*/

// 最大正方形面积
// DP

// Reference solution: 
// #1:
// DP
// 思路：dp[i][j]表示到达(i, j)位置所能组成的最大正方形的边长width。
// 我们首先来考虑边界情况，也就是当i或j为0的情况:
// d[i][j]=matrix[i][j]-'0'
// 而一般情况的递推公式：
// dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
// 这是由于对于任意一点dp[i][j]，由于该点是正方形的右下角，所以该点的右边，下边，右下边都不用考虑，
// 关心的就是左边，上边，和左上边。这三个位置的dp已经算好，还有就是要知道一点，只有当前(i, j)位置为1，
// dp[i][j]才有可能大于0，否则dp[i][j]一定为0。当(i, j)位置为1，此时要看dp[i-1][j-1], dp[i][j-1]，和dp[i-1][j]这三个位置，
// 我们找其中最小的值，并加上1，就是dp[i][j]的当前值了。
// 最后再用dp[i][j]的值来更新结果width的值即可。
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) 
            return 0;
        int m = matrix.size(), n = matrix[0].size(), width = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                if (i == 0 || j == 0) 
                    dp[i][j] = matrix[i][j] - '0';
                else if (matrix[i][j] == '1') 
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                
                width = max(width, dp[i][j]);
            }
        }
        return width * width;
    }
};


// 可以进一步优化空间复杂度，只需要用一个一维数组，为了处理边界情况，padding了一位，
// 所以dp的长度是m+1，然后还需要一个变量pre来记录上一个层的dp值，我们更新的顺序是行优先，
// 就是先往下遍历，用一个临时变量t保存当前dp值，然后看如果当前位置为1，则更新dp[i]为dp[i], 
// dp[i-1], 和pre三者之间的最小值，再加上1，来更新结果res，如果当前位置为0，则重置当前dp值为0，
// 因为只有一维数组，每个位置会被重复使用.
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) 
            return 0;
        int m = matrix.size(), n = matrix[0].size(), width = 0, left = 0, cur = 0;
        vector<int> dp(n, 0);
        for(int j=0; j<n; j++)
            if(matrix[0][j] == '1')
                dp[j] =  width = 1;
        
        for (int i = 1; i < m; ++i) 
        {
            left = matrix[i][0] - '0';
            if(left && width==0)
                width = 1;
            for (int j = 1; j < n; ++j) 
            {
                if(matrix[i][j] == '1')
                {
                    cur = min(dp[j-1], min(dp[j], left)) + 1;
                    dp[j-1] = left;
                    left = cur;
                    width = max(width, cur);
                }
                else
                {
                    dp[j-1] = left;
                    cur = left = 0;
                }
            }
            dp[n-1] = cur;
        }
        return width * width;
    }
};



// Reference solution: 
// #2:
// Brute force method:
// 这种方法的机理就是把数组中每一个点都当成正方形的左顶点来向右下方扫描，来寻找最大正方形。
// 具体的扫描方法是，确定了左顶点后，再往下扫的时候，正方形的竖边长度就确定了，只需要找到横边即可，
// 这时候我们使用直方图的原理，从其累加值能反映出上面的值是否全为1.
class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        if(matrix.empty() || matrix[0].empty)
            return 0;
        int result = 0;
        for (int i = 0; i < matrix.size(); ++i) 
        {
            vector<int> v(matrix[i].size(), 0);
            for (int j = i; j < matrix.size(); ++j) 
            {
                for (int k = 0; k < matrix[j].size(); ++k) 
                {
                    if (matrix[j][k] == '1') 
                        ++v[k];
                }
                result = max(result, getSquareArea(v, j - i + 1));
            }
        }
        return result;
    }
    
    int getSquareArea(vector<int> &v, int width) {
        if (v.size() < width) 
            return 0;
        int count = 0;
        for (int i = 0; i < v.size(); ++i) 
        {
            if (v[i] != width) 
                count = 0; 
            else 
                ++count;
            
            if (count == width) 
                return width * width;
        }
        return 0;
    }
};