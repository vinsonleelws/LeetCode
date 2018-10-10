/*Given an input string, reverse the string word by word.

Example:  

Input: "the sky is blue",
Output: "blue is sky the".

Note:

    A word is defined as a sequence of non-space characters.
    Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
    You need to reduce multiple spaces between two words to a single space in the reversed string.

Follow up: For C programmers, try to solve it in-place in O(1) space.
*/

class Solution {
public:
    void reverseWords(string &s) {
        
    }
};

// 翻转字符串中的单词  [M]
// reverse(s.begin(), s.end()) ; istringstream

// 不仅要实现反转，还需将多余的空格去掉：去掉头尾空格，单词间的空格有多个的话变成一个。

// Reference solution:
// #1
// 先整个字符串整体翻转一次，然后再分别翻转每一个单词（或者先分别翻转每一个单词，然后再整个字符串整体翻转一次），此时就能得到我们需要的结果了。
// 这里我们需要定义一些变量来辅助我们解题，cur表示当前存储到的位置，n为字符串的长度。我们先给整个字符串反转一下，然后我们开始循环，
// 遇到空格直接跳过，如果是非空格字符，我们此时看cur是否为0，为0的话表示第一个单词，不用增加空格；如果不为0，说明不是第一个单词，需要在单词中间加一个空格，
// 然后我们要找到下一个单词的结束位置我们用一个while循环来找下一个为空格的位置，在此过程中继续覆盖原字符串，找到结束位置了，下面就来翻转这个单词，然后更新i为结尾位置，
// 最后遍历结束，我们剪裁原字符串到cur位置。
class Solution {
public:
    void reverseWords(string &s) {
        int cur = 0, n = s.size();  // cur表示当前存储到的位置
        reverse(s.begin(), s.end());  // 先翻转整个字符串
        for (int i = 0; i < n; ++i) 
        {
            if (s[i] != ' ') // 如果是空格，直接跳过； 如果是字母，则开始处理单词
            {
                if (cur != 0) 
                    s[cur++] = ' ';
                int j = i;
                while (j < n && s[j] != ' ')  // 复制单词
                    s[cur++] = s[j++];
                reverse(s.begin() + cur - (j - i), s.begin() + cur); // 翻转单词
                i = j;  // 更新位置
            }
        }
        s.resize(cur);
    }
};

// #2
// 使用字符串流类stringstream的解法，我们先把字符串装载入字符串流中，然后定义一个临时变量tmp，然后把第一个单词赋给s，这里需要注意的是，如果含有非空格字符，
// 那么每次>>操作就会提取连在一起的非空格字符，那么我们每次将其加在s前面即可；如果原字符串为空，那么就不会进入while循环；如果原字符串为许多空格字符连在一起，
// 那么第一个>>操作就会提取出这些空格字符放入s中，然后不进入while循环，这时候我们只要判断一下s的首字符是否为空格字符，是的话就将s清空即可。
class Solution {
public:
    void reverseWords(string &s) {
        istringstream is(s);
        string tmp;
        is >> s;
        while(is >> tmp) 
            s = tmp + " " + s;
        if(!s.empty() && s[0] == ' ') 
            s = ""; 
    }
};

// 下面这种方法也是使用stringstream来做，但是我们使用了getline来做，第三个参数是设定分隔字符，我们用空格字符来分隔，这个跟上面的>>操作是有不同的，每次只能过一个空格字符，
// 如果有多个空格字符连在一起，那么t会赋值为空字符串，所以我们在处理t的时候首先要判断其是否为空，是的话直接跳过
class Solution {
public:
    void reverseWords(string &s) {
        istringstream is(s);
        s = "";
        string t = "";
        while (getline(is, t, ' ')) {
            if (t.empty()) continue;
            s = (s.empty() ? t : (t + " " + s));
        }
    }
};