/*Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true

Example 2:

Input: "race a car"
Output: false*/

class Solution {
public:
    bool isPalindrome(string s) {

    }
};


// 验证回文字符串 (忽略字母大小写)  [E]
// Two Pointers

// 所谓回文，就是一个正读和反读都一样的字符串，比如“level”或者“noon”等等就是回文串。但是这里，加入了空格和非字母数字的字符，增加了些难度，
// 但其实原理还是很简单：只需要建立两个指针，left和right, 分别从字符的开头和结尾处开始遍历整个字符串，如果遇到非字母数字的字符就跳过，继续往下找，
// 直到找到下一个字母数字或者结束遍历，如果遇到大写字母，就将其转为小写。等左右指针都找到字母数字时，比较这两个字符，若相等，则继续比较下面两个分别找到的字母数字，若不相等，直接返回false.


// My solution:
// #1
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1 ;
        while (left < right) {
            if (!isalnum(s[left]))
                ++left;
            else if (!isalnum(s[right]))
                --right;
            else if ((isdigit(s[left]) || isdigit(s[right])) && s[left] != s[right])
                return false;
            else if (s[left] != s[right]  && abs(s[left] - s[right]) != 32)
                return false;
            else
            {
                ++left;
                --right;
            }
        }
        return true;
    }
};

// #2
// 关键：当两个字符是字母或数字时，要判断是它们否合法：如果它们都是数字，那么值必须相等；如果它们是字母，则须是相同的字母（忽略大小写）。
// 在ASCII码表中，9在大写字母前面，大写字母在小写字母前面
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty())
            return true;

        int left = 0;
        int right = s.length() - 1;
        while (left < right)
        {
            if (isAlphaNum(s[left]) && isAlphaNum(s[right]))
            {
                if (s[left] <= '9' || s[right] <= '9')
                {
                    if (s[left] != s[right])
                        return false;
                }
                else if (s[left] != s[right] && abs(s[left] - s[right]) != 32) // 大小写字母的ascii码相差32
                    return false;

                left++;
                right--;

            }
            else
            {
                if (!isAlphaNum(s[left]))
                    left++;

                if (!isAlphaNum(s[right]))
                    right--;
            }
        }

        return true;
    }

    bool isAlphaNum(const char &ch) {
        if (ch >= 'a' && ch <= 'z')
            return true;
        if (ch >= 'A' && ch <= 'Z')
            return true;
        if (ch >= '0' && ch <= '9')
            return true;
        return false;
    }
};

// 另一种写法：
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1 ;
        while (left < right) {
            if (!isAlphaNum(s[left]))
                ++left;
            else if (!isAlphaNum(s[right]))
                --right;
            else if ((s[left] + 32 - 'a') % 32 != (s[right] + 32 - 'a') % 32)
                return false;
            else
            {
                ++left;
                --right;
            }
        }
        return true;
    }
    bool isAlphaNum(char &ch) {
        if (ch >= 'a' && ch <= 'z') return true;
        if (ch >= 'A' && ch <= 'Z') return true;
        if (ch >= '0' && ch <= '9') return true;
        return false;
    }
};


// 我们也可以用库函数isalnum来判断某个字符是否是字母或数字
// isalnum位于头文件<cctype>中
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1 ;
        while (left < right) {
            if (!isalnum(s[left]))
                ++left;
            else if (!isalnum(s[right]))
                --right;
            else if ((s[left] + 32 - 'a') % 32 != (s[right] + 32 - 'a') % 32)
                return false;
            else {
                ++left;
                --right;
            }
        }
        return true;
    }
};

