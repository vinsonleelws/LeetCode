/*Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/

class Solution {
public:
	int lengthOfLongestSubstring(string s) {

	}
};


// 最长无重复字符的子串的长度  [M]
// Hash Table


// My solution
// Hash Table
// 使用哈希表记录字符上一次出现的位置
// 如果相同字符之间的间距大于当前的count，则count++;
// 反之，如果count > max_count，则更新max_count，更新count = i - pre_position[s[i]];
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.empty())
			return 0;

		int n = s.size();
		vector<int> pre_position(256, -1);
		int count = 0, max_count = 0;
		for (unsigned i = 0; i < n; i++)
		{
			if (pre_position[s[i]] != -1 && i - pre_position[s[i]] <= count)
			{
                if (max_count < count)
                    max_count = count;

                count = i - pre_position[s[i]];
			}
			else
				count++;

			pre_position[s[i]] = i;
		}

		if (max_count < count)
			max_count = count;

		return max_count;
	}
};


// 另一种写法
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.c_str() == nullptr || s.c_str() == "")
			return 0;

		int* pre_position = new int[256];
		for (unsigned i = 0; i < 256; i++)
			pre_position[i] = -1;

		int count = 0;
		int max_count = 0;
		for (unsigned i = 0; i < s.length(); i++)
		{
			if (pre_position[s[i]] != -1)
			{
				if (i - pre_position[s[i]]  <= count)
				{
					if (max_count < count)
						max_count = count;

					count = i - pre_position[s[i]];
				}
				else
					count++;
			}
			else
				count++;

			pre_position[s[i]] = i;
		}
		if (max_count < count)
			max_count = count;

		delete[] pre_position;
		return max_count;
	}
};