/*Count the primeber of prime primebers less than a non-negative primeber, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime primebers less than 10, they are 2, 3, 5, 7.
*/

class Solution {
public:
    int countPrimes(int n) {
        
    }
};

// 质数的个数
// 埃氏筛法

// 埃拉托斯特尼筛法的应用
// 埃拉托斯特尼筛法（sieve of Eratosthenes），简称埃氏筛，也有人称素数筛。这是一种简单且历史悠久的筛法，用来找出一定范围内所有的素数。
// 所使用的原理是从2开始，将每个素数的各个倍数，标记成合数。一个素数的各个倍数，是一个差为此素数本身的等差数列。此为这个筛法和试除法不同的关键之处，后者是以素数来测试每个待测数能否被整除。
// 埃拉托斯特尼筛法是列出所有小素数最有效的方法之一。
// 算法伪代码：
/*
Input: an integer n > 1
 
Let A be an array of Boolean values, indexed by integers 2 to n,
initially all set to true.
 
 for i = 2, 3, 4, ..., not exceeding √n:
  if A[i] is true:
    for j = i2, i2+i, i2+2i, i2+3i, ..., not exceeding n :
      A[j] := false
 
Output: all i such that A[i] is true.
*/

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n, true);
        prime[0] = prime[1] = false;
        int res = 0, limit = sqrt(n);
        for (int i = 2; i <= limit; ++i) 
        {
            if (prime[i]) 
            {
                for (int j = 2*i; j < n; j += i)  // 此处 2*i 也可改为 i*i 来提高效率
                    prime[j] = false;
            }
        }
        
        for (int j = 0; j < n; ++j) 
            if (prime[j]) ++res;
        
        return res;
    }
};