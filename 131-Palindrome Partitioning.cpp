/*Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]
*/

// 拆分回文串
// DFS (Backtracking)

// Backtracking/DFS
class Solution {
public:
    vector<vector<string>> partition(string s) {
        if(s.empty())
            return {};
        
        vector<vector<string>> result;
        vector<string> sol;
        partitionDFS(s, 0, sol, result);
        return result;
    }
    
    void partitionDFS(string s, int start, vector<string>& sol, vector<vector<string>> &result) {
        if (start == s.size()) 
        {
            result.push_back(sol);
            return;
        }
        for (int i = start; i < s.size(); ++i) 
        {
            if (isPalindrome(s, start, i)) 
            {
                sol.push_back(s.substr(start, i - start + 1));
                partitionDFS(s, i + 1, sol, result);
                sol.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s, int start, int end) {
        while (start < end) 
        {
            if (s[start] != s[end]) 
                return false;
            ++start;
            --end;
        }
        return true;
    }
};