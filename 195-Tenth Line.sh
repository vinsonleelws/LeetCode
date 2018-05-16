Given a text file file.txt, print just the 10th line of the file.

Example:

Assume that file.txt has the following content:

Line 1
Line 2
Line 3
Line 4
Line 5
Line 6
Line 7
Line 8
Line 9
Line 10

Your script should output the tenth line, which is:

Line 10

Note:
1. If the file contains less than 10 lines, what should you output?
2. There's at least three different solutions. Try to explore all possibilities.

# Read from the file file.txt and output the tenth line to stdout.

#1 使用awk
awk '{if(NR == 10) print $0}' file.txt

#2 
awk 'NR == 10' file.txt

#3
sed -n 10p file.txt

#4 我们也可以使用tail和head关键字来打印
# tail -n 3 file.txt: 打印file文件的最后三行内容　　　　　　
# tail -n +3 file.txt： 从file文件第三行开始打印所有内容
# head -n 3 file.txt： 打印file文件的前三行
# head -n -3 file.txt： 打印file文件除了最后三行的所有内容

tail -n +10 file.txt | head -n 1
# 首先输入file文件从第十行开始的所有内容，然后将输出内容的第一行打印出来即为第十行

#5
head -n 10 file.txt | tail -n +10

