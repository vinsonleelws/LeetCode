/*Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

class Solution {
public:
	vector<string> letterCombinations(string digits) {

	}
};


// 电话号码的字母组合  [M]
// DFS (Backtracking) ; BFS

// 基于递归的方法。通过建立一个string数组来保存每个数字所代表的字符串，另外用一个变量index来记录当前生成的字符串的字符个数.
// 相当于是深度优先的方法(DFS)

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> result;
		if (digits.size())
		{
			string contents[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
			combineStr(digits, contents, 0, "", result);
		}
		return result;
	}

	void combineStr(string& digits, string contents[], int index, string str, vector<string>& result)
	{
		if (index == digits.size())
			result.push_back(str);
		else
		{
			string s = contents[digits[index] - '2'];
			for (int i = 0; i < s.length(); i++)
			{
				str.push_back(s[i]);
				combineStr(digits, contents, index + 1, str, result);
				str.pop_back();
			}
		}
	}
};

// 基于循环的方法，更快！
// 相当于是广度优先的方法 (BFS)
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> result;
		if (digits.empty())
			return result;
		string contents[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		result.push_back("");

		for (int i = 0; i < digits.size(); ++i)
		{
			int n = result.size();
			string str = contents[digits[i] - '2'];
			for (int j = 0; j < n; ++j)
			{
				string tmp = result.front();
				result.erase(result.begin());
				for (int k = 0; k < str.size(); ++k)
					result.push_back(tmp + str[k]);
			}
		}
		return result;
	}
};

// 以输入"23"为例
// result的产生过程：
// a b c
// b c ad ae af
// c ad ae af bd be bf
// ad ae af bd be bf cd ce cf