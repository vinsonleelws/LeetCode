/*All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

Example:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

Output: ["AAAAACCCCC", "CCCCCAAAAA"]

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
    }
};*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
    }
};


// 重复的DNA序列
// Hash Table ; Bit Manipulation


// -----------------------------------------------------
// Reference solution:
// 基本思路都是采用哈希表：
// #1: 使用set
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string> res, st;
        int n = s.size();
        for (int i = 0; i + 9 < n; ++i) {
            string t = s.substr(i, 10);
            if (st.count(t))  // 如果重复
            {
                if(!res.count(t))
                    res.insert(t);
            }
            else   // 否则
                st.insert(t);
        }
        return vector<string>{res.begin(), res.end()};
    }
};

// 以下是考虑节省内存空间的方法，由于直接将字符串存到哈希表中空间效率不高，因此我们可以考虑对4中字符A, C, G, T进行编码：
// 这就涉及到位操作Bit Manipulation
// #2 
// 此题由于构成输入字符串的字符只有四种，分别是A, C, G, T，下面我们来看下它们的ASCII码用二进制来表示：

A: 0100 0001　　C: 0100 0011　　G: 0100 0111　　T: 0101 0100
         ---             ---             ---             ---
// 由于我们的目的是利用位来区分字符，当然是越少位越好，通过观察发现，每个字符的后三位都不相同，故而我们可以用末尾三位来区分这四个字符。而题目要求是10个字符长度的串，
// 每个字符用三位来区分，10个字符需要30位。为了提取出后30位，我们还需要用个mask，取值为0x7ffffff，用此mask可取出后27位，再向左平移三位即可。
// 算法的思想是，当取出第十个字符时，将其存在哈希表里，和该字符串出现频率映射，之后每向左移三位替换一个字符，查找新字符串在哈希表里出现次数，如果之前刚好出现过一次，
// 则将当前字符串存入返回值的数组并将其出现次数加一，如果从未出现过，则将其映射到1。

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if (s.size() <= 10) return res;
        int mask = 0x7ffffff;
        unordered_map<int, int> m;
        int cur = 0, i = 0;
        while (i < 9) {
            cur = (cur << 3) | (s[i++] & 7);
        }
        while (i < s.size()) {
            cur = ((cur & mask) << 3) | (s[i++] & 7);
            if (m.find(cur) != m.end()) 
            {
                if (m[cur] == 1) 
                    res.push_back(s.substr(i - 10, 10));
                ++m[cur]; 
            } 
            else 
            {
                m[cur] = 1;
            }
        }
        return res;
    }
};

// 上面的方法可以写的更简洁一些，这里我们可以用set来代替哈希表，只要当前的数已经在哈希表中存在了，我们就将其加入res中，这里我们res也定义成set，
// 这样就可以利用set的不能有重复项的特点，从而得到正确的答案，最后我们将set转为vector即可
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> res;
        unordered_set<int> st;
        int cur = 0, i = 0;
        while (i < 9) cur = cur << 3 | (s[i++] & 7);
        while (i < s.size()) {
            cur = ((cur & 0x7ffffff) << 3) | (s[i++] & 7);
            if (st.count(cur)) res.insert(s.substr(i - 10, 10));
            else st.insert(cur);
        }
        return vector<string>(res.begin(), res.end());
    }
};

// #2
// 上面的方法都是用三位来表示一个字符，这里我们可以用两位来表示一个字符，00表示A，01表示C，10表示G，11表示T，那么我们总共需要20位就可以表示十个字符流，
// 其余的思路跟上面的方法完全相同，注意这里的mask只需要表示18位，所以变成了0x3ffff
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> res;
        unordered_set<int> st;
        unordered_map<int, int> m{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        int cur = 0, i = 0;
        while (i < 9) cur = cur << 2 | m[s[i++]];
        while (i < s.size()) {
            cur = ((cur & 0x3ffff) << 2) | (m[s[i++]]);
            if (st.count(cur)) res.insert(s.substr(i - 10, 10));
            else st.insert(cur);
        }
        return vector<string>(res.begin(), res.end());
    }
};