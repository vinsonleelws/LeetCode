Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

// 递归解法：
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        if(n<=0 || k<=0)
            return result;
        
        vector<int> sol;
        combineDFS(n, k, 1, sol, result);
        return result;
    }
    
    void combineDFS(const int& n, const int& k, int index, vector<int>& sol, vector<vector<int>>& result)
    {
        if(sol.size()==k)
            result.push_back(sol);
        else
        {
            for(int i=index; i<=n; i++)
            {
                sol.push_back(i);
                combineDFS(n, k, i+1, sol, result);
                sol.pop_back();
            }
        }
    }
};


// Other reference solution:
// 基于迭代的写法:
// 用一个大小为k的数组保存结果，每次
// 这里每次先递增最右边的数字，存入结果res中，当右边的数字超过了n，
// 则增加其左边的数字，然后将当前数组赋值为左边的数字，再逐个递增，直到最左边的数字也超过了n，
// 停止循环。对于n=4, k=2时，遍历的顺序如下所示：

// 0 0 #initialization
// 1 0
// 1 1 
// 1 2 #push_back
// 1 3 #push_back
// 1 4 #push_back
// 1 5 
// 2 5
// 2 2 
// 2 3 #push_back
// 2 4 #push_back
// ...
// 3 4 #push_back
// 3 5
// 4 5
// 4 4
// 4 5
// 5 5 #stop 

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> out(k, 0);
        int i = 0;
        while (i >= 0) {
            ++out[i];
            if (out[i] > n) --i;
            else if (i == k - 1) res.push_back(out);
            else {
                ++i;
                out[i] = out[i - 1];
            }
        }
        return res;
    }
};