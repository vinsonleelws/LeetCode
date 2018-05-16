Write a bash script to calculate the frequency of each word in a text file words.txt.

For simplicity sake, you may assume:

    words.txt contains only lowercase characters and space ' ' characters.
    Each word must consist of lowercase characters only.
    Words are separated by one or more whitespace characters.

Example:

Assume that words.txt has the following content:

the day is sunny the the
the sunny is is

Your script should output the following, sorted by descending frequency:

the 4
is 3
sunny 2
day 1

Note:

    Don't worry about handling ties, it is guaranteed that each word's frequency count is unique.
    Could you write it in one-line using Unix pipes?

    
# Read from the file words.txt and output the word frequency list to stdout.

#1
# grep -oE '[a-z]+'参数表示原文本内容变成一个单词一行的存储方式
# uniq命令是表示去除重复行命令
# sort -nr 表示降序排序
grep -oE '[a-z]+' words.txt | sort | uniq -c | sort -nr | awk '{print $2" "$1}' 


#2

tr -s ' ' '\n' < words.txt | sort | uniq -c | sort -nr | awk '{print $2, $1}'
# tr命令用来进行字符替换或者大小写替换，紧跟的-s参数表示如果发现连续的字符，
# 就把它们缩减为1个，而后面的‘ ’和‘\n'就是空格和回车，意思是把所有的空格都换成回车


#3
awk '{
    for (i = 1; i <= NF; ++i) ++s[$i];
} END {
    for (i in s) print i, s[i];
}' words.txt | sort -nr -k 2



