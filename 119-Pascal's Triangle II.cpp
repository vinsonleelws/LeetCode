Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]

Follow up:

Could you optimize your algorithm to use only O(k) extra space?

// [1],
// [1,1],
// [1,2,1],
// [1,3,3,1],
// [1,4,6,4,1]

// My solution:
// O(k)的空间复杂度的解法：
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex < 0)
            return {};
        else if(rowIndex == 0)
            return {1};
        
        vector<int> result(rowIndex+1, 1);
        for(int i=2; i<=rowIndex; i++)
        {
            int upLeft = 1;
            for(int j=1; j<=i-1; j++)
            {
                int tmp = result[j];
                result[j] = upLeft + result[j];
                upLeft = tmp;
            }
            result[i] = 1;
        }
        
        return result;
    }
};