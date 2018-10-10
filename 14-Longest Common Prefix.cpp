/*Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.*/


class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {

	}
};


// 字符串最长公共前缀  [E]

// Reference method
// 以第一个字符串作为prefix，遍历其它字符串进行比对，更新prefix
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty())
			return "";
		string prefix = strs[0];
		for (int i = 1; i < strs.size(); ++i) 
			for (int j = 0; j < prefix.size(); ++j) 
			{
				if (strs[i][j] != prefix[j]) 
				{
					prefix = prefix.substr(0, j);
					break;
				}
			}
			
		return prefix;
	}
};


// My solution
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string prefix("");
		if (strs.size())
		{
			bool common = true;
			for (int len = strs[0].length(); len >= 1; len--)
			{
				for (int i = 1; i < strs.size(); i++)
				{
					if ( strs[i].length() < len || (strs[i].substr(0, len) != strs[0].substr(0, len)) )
					{
						common = false;
						break;
					}
				}
				if (common == true)
				{
					prefix = strs[0].substr(0, len);
					break;
				}
				else
					common = true;
			}
		}

		return prefix;

	}
};


