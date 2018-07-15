/* 
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

    All numbers will be positive integers.
    The solution set must not contain duplicate combinations.

Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]

Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]] 
*/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
    }
};

// 组合之和III（给定k个数，在1~9中找）
// Backtracking

// 这题是"39-Combination Sum"和"40-Combination Sum II"的延伸，"39-Combination Sum"是给一个数组（数组中无重复项）和一个target，然后求数组中所有不同的元素组合情况，使得元素的值加起来等于target。
// 而"40-Combination Sum II"给的数组包含重复项，但输出要求不变，这就要求我们先对数组进行排序，然后遇到使用过的数字时需跳过重复元素。
// 与前两题不同的是，这道题换了要求，指定了k个数，取值范围是[1, 9]，并且这k个数的和要等于n，k个数不能存在重复的数。

// My solution: Runtime beats 100% of cpp submissions.
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k<=0 || n<=0)
            return {};
        
        vector<vector<int>> result;
        vector<int> numbers;
        combinationSumDFS(k, n, 1, numbers, result);
        return result;
    }
    
    void combinationSumDFS(int k, int n, int start, vector<int> numbers, vector<vector<int>>& result){
        if(k == 0 && n == 0)
        {
            result.push_back(numbers);
            return;
        }
        else
        {
            for(int i=start; i<=9; i++)
            {
                if(i<=n)
                {
                    numbers.push_back(i);
                    combinationSumDFS(k-1, n-i, i+1, numbers, result);
                    numbers.pop_back();
                }
                else
                    return;
            }
        }
    }
};