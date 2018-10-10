/*Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note:

    1. is typically treated as an ugly number.
    2. n does not exceed 1690.
*/

class Solution {
public:
    int nthUglyNumber(int n) {

    }
};


// 264-求第n个丑数  [M]
// 三指针，Math


// My solution
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n < 1)
            return 0;
        int p1 = 0, p2 = 0, p3 = 0;
        int cnt = 1;
        vector<int> ugly(n, 0);
        ugly[0] = 1;
        int target = 1;
        while (cnt < n)
        {
            while (ugly[p1] * 2 <= target)
                p1++;
            while (ugly[p2] * 3 <= target)
                p2++;
            while (ugly[p3] * 5 <= target)
                p3++;

            target = min(ugly[p1] * 2, min(ugly[p2] * 3, ugly[p3] * 5));
            ugly[cnt] = target;
            cnt++;
        }

        return target;
    }
};