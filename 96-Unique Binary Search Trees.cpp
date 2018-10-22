/*Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/
   


// 独一无二的二叉搜索树(数目)  [M]
// DP
//  
//    
// 思路：找规律，获得地推公式，然后用DP算法求。


// 这道题实际上是 Catalan Number卡塔兰数的一个例子。
// 先来看n=1,2,3时的例子：
                    1                        n = 1 : 1种

                2        1                   n = 2 : 2种
               /          \
              1            2
  
   1         3     3      2      1           n = 3 : 5种
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

// 以1为根的树有几个，完全取决于有二个元素的子树有几种。同理，2为根的子树取决于一个元素的子树有几个。以3为根的情况，则与1相同。
// 就跟斐波那契数列一样，我们把n = 0 时赋为1，因为空树也算一种二叉搜索树，
// 那么n = 1时的情况可以看做是其左子树个数乘以右子树的个数，左右字数都是空树，所以1乘1还是1。因此：

dp[1] = 1;

// n = 2时，由于1和2都可以为跟，分别算出来，再把它们加起来即可。n = 2的情况可由下面式子算出：

dp[2] =  dp[0] * dp[1]　　　(1为根的情况)

　　　　+ dp[1] * dp[0]　　 (2为根的情况)

同理可写出 n = 3 的计算方法：

dp[3] =  dp[0] * dp[2]　　　(1为根的情况)

　　　　+ dp[1] * dp[1]　　 (2为根的情况)

 　　　 + dp[2] * dp[0]　　 (3为根的情况)

问题至此划归为一维动态规划。

可以用卡塔兰数列的递推式表示：
(1) C0 =1;
(2) Cn+1 = sum{Ci*Cn-i}_i=0_to_n for n>=0

/* 
  总结：
 当数组为 1，2，3，4，.. i，.. n时，我们发现基于以下原则的BST建树具有唯一性：
 以i为根节点的树，其左子树由[0, i-1]构成， 其右子树由[i+1, n]构成。
 */

// Reference solution: Runtime beats 100% of cpp submitions.
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};

