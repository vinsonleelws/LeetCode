Given a text file file.txt, transpose its content.

You may assume that each row has the same number of columns and each field is separated by the ' ' character.

Example:

If file.txt has the following content:

name age
alice 21
ryan 30

Output the following:

name alice ryan
age 21 30

# Read from the file file.txt and print its transposed content to stdout.

#1 使用awk
awk '{
    for (i = 1; i <= NF; ++i) {
        if (NR == 1) s[i] = $i;
        else s[i] = s[i] " " $i;
    }
} END {
    for (i = 1; s[i] != ""; ++i) {
        print s[i];
    }
}' file.txt

# 遍历的过程如下：
# i = 1, s = [name]
# i = 2, s = [name; age]
# i = 1, s = [name alice; age]
# i = 2, s = [name alice; age 21]
# i = 1, s = [name alice ryan; age 21]
# i = 2, s = [name alice ryan; age 21 30]


#2 使用read
while read -a line; do
    for ((i = 0; i < "${#line[@]}"; ++i)); do
        a[$i]="${a[$i]} ${line[$i]}"
    done
done < file.txt
for ((i = 0; i < ${#a[@]}; ++i)); do
    echo ${a[i]}
done