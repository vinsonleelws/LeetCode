Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:

    All inputs will be in lowercase.
    The order of your output does not matter.

// 思路：基于字符串排序 + 哈希表的算法。
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<string, vector<string>> str_map;
        for(string s:strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            str_map[key].push_back(s);
        }
        for(auto x:str_map)
            result.push_back(x.second);
        
        return result;
    }
};


// Reference solution:
// 也是基于哈希表的，但在key值的处理上不使用字符串排序，而是用一个26位的数组来表示每一个字符串，
// 将每个字符串对应的26位数组转化为唯一的key值。

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for (string str : strs) {
            vector<int> cnt(26, 0);
            string t = "";
            for (char c : str) ++cnt[c - 'a'];
            for (int d : cnt) t += to_string(d) + "/";
            m[t].push_back(str);
        }
        for (auto a : m) {
            res.push_back(a.second);
        }
        return res;
    }
};