Given a string s, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

Example 1:

Input: "aacecaaa"
Output: "aaacecaaa"

Example 2:

Input: "abcd"
Output: "dcbabcd"

// Reference solution:
// #1
// 题目让我们在给定字符串s的前面加上最少个字符，使之变成回文串，那么我们来看题目中给的两个例子，最坏的情况下是s中没有相同的字符，
// 那么最小需要添加字符的个数为s.size() - 1个，第一个例子的字符串包含一个回文串，只需再在前面添加一个字符即可，还有一点需要注意的
// 是，前面添加的字符串都是从s的末尾开始，一位一位往前添加的，那么我们只需要知道从s末尾开始需要添加到前面的个数。这道题如果用
// brute force无法通过OJ，所以我们需要用一些比较巧妙的方法来解。这里可以使用KMP算法，KMP算法是一种专门用来匹配字符串的高效的算法，
// 我们把s和其转置r连接起来，中间加上一个其他字符，形成一个新的字符串t，我们还需要一个和t长度相同的一维数组next，其中next[i]表示
// 从t[i]到开头的子串的最大前缀后缀公共元素的长度。最后我们把不相同的个数对应的字符串添加到s之前即可。
// 基于KMP的解法：
class Solution {
public:
    string shortestPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        string t = s + "#" + r;
        vector<int> next(t.size(), 0);
        for (int i = 1; i < t.size(); ++i) 
        {
            int j = next[i - 1];
            while (j > 0 && t[i] != t[j]) 
                j = next[j - 1];
            
            next[i] = (j += t[i] == t[j]);
        }
        return r.substr(0, s.size() - next.back()) + s;
    }
};


// #2
// 下面这种方法的写法比较简洁，虽然不是明显的KMP算法，但是也有其的影子在里面，首先我们还是先将其的翻转字符串搞出来，
// 然后比较原字符串s的前缀和翻转字符串t的对应位置的后缀是否相等，起始位置是比较s和t是否相等，如果相等，说明s本身就
// 是回文串，不用添加任何字符，直接返回即可；如果不想等，s去掉最后一位，t去掉第一位，继续比较，以此类推直至有相等，
// 或者循环结束，这样我们就能将两个字符串在正确的位置拼接起来了。
class Solution {
public:
    string shortestPalindrome(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.size(), i = 0;
        for (i = n; i >= 0; --i) 
        {
            if (s.substr(0, i) == t.substr(n - i))
                break;
        }
        return t.substr(0, n - i) + s;
    }
};