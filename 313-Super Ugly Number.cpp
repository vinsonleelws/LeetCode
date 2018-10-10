/*Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k.

Example:

Input: n = 12, primes = [2,7,13,19]
Output: 32
Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12
             super ugly numbers given primes = [2,7,13,19] of size 4.

Note:

    1 is a super ugly number for any given primes.
    The given numbers in primes are in ascending order.
    0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
    The nth super ugly number is guaranteed to fit in a 32-bit signed integer.
*/

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {

    }
};

// 313-求第n个超级丑数（指定质数集）  [M]
// DP + Pointers

// My solution
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly(n, 1);
        int target = 1;
        int cnt = 1;
        vector<int> index(primes.size(), 0);
        while (cnt < n)
        {
            for (int i = 0; i < primes.size(); i++)
                while (ugly[index[i]]*primes[i] <= target)
                    index[i]++;

            target = ugly[index[0]] * primes[0];
            for (int i = 1; i < primes.size(); i++)
                target = min(target, ugly[index[i]] * primes[i]);

            ugly[cnt] = target;
            cnt++;
        }

        return target;
    }
};