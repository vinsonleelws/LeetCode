/*
The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

    "123"
    "132"
    "213"
    "231"
    "312"
    "321"

Given n and k, return the kth permutation sequence.

Note:

    Given n will be between 1 and 9 inclusive.
    Given k will be between 1 and n! inclusive.
    
Example 1:

Input: n = 3, k = 3
Output: "213"

Example 2:

Input: n = 4, k = 9
Output: "2314"
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        
    }
};


// 排列顺序
// 找规律 ; DFS (Backtracking)

// 思路：
// 可通过找规律，根据公式直接求出每一位的数字。
// 以n = 4，k = 9为例：

// 1234
// 1243
// 1324
// 1342
// 1423
// 1432
// 2134
// 2143
// 2314  <= k = 9
// 2341
// 2413
// 2431
// 3124
// 3142
// 3214
// 3241
// 3412
// 3421
// 4123
// 4132
// 4213
// 4231
// 4312
// 4321

// 首先将k对应于下标，即将k减去1，k=k-1=9-1=8;
// 确定第一个数字：最高位可以取{1, 2, 3, 4}，而每个数重复3! = 6次，即重复(n-1)!次。所以第一个数为{1, 2, 3, 4}中下标为k/(n-1)!=8/6=1的数字：2;
// 确定第二个数字：对于以2开头的6个数字而言，k=8是其中的第8%(3!)=2个，此处更新k的公式为：k=k%(n-1)!。而剩下的数字{1, 3, 4}的重复周期为2! = 2次，因此第二个数字
//                 为{1, 3, 4}中下标为k/(n-2)!=2/2=1的数字：3;
// 确定第三个数字：更新k=k%(n-2)!=2%2=0，第三个数字是{1, 4}中下标为可k/(n-3)!=0/1=0的数字：1;
// 确定第四个数字：更新k=k%(n-3)!=0%1=0，第四个数字是{4}中下标为k/(n-4)!=0/1=0的数字：4.

// 总结：算法步骤：
// 首先将k对应于下标，k <- k-1;
// index更新公式：index <- k/(n-1)!
// k更新公式：k <- k%(n-1)!
// 更新n：n--;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n, 1);
        vector<char> nums(n, '1');
        string result;
        for(int i=1; i<n; i++)
        {
            factorial[i] = factorial[i-1]*i;
            nums[i] = nums[i-1]+1;
        }
        
        k--;
        for(int i=n; i>=1; i--)
        {
            int j = k/factorial[i-1];
            k %= factorial[i-1];
            result.push_back(nums[j]);
            nums.erase(nums.begin()+j);
        }
        
        return result;
    }
};


// My solution: (TLE)
// 纯粹采用类似于题目"46-Permutations"的Backtracking方法将导致TLE
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<bool> iFlag(n+1, 0);
        string res;
        int K = k;
        permutations(n, n, iFlag, res, K);
        return res;
    }
    
    void permutations(int n, int level, vector<bool> iFlag, string& res, int& k)
    {
        if(level==0)
            k--;
        else
            for(int i=1; i<=n; i++)
            {   
                if(!iFlag[i])
                {
                    res += to_string(i);
                    iFlag[i] = true;
                    permutations(n, level-1, iFlag, res, k);
                    if(k==0)
                        return;
                    res.pop_back();
                    iFlag[i] = false;
                }
            }
    }
};