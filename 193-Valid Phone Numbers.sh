Given a text file file.txt that contains list of phone numbers (one per line), write a one liner bash script to print all valid phone numbers.

You may assume that a valid phone number must appear in one of the following two formats: (xxx) xxx-xxxx or xxx-xxx-xxxx. (x means a digit)

You may also assume each line in the text file must not contain leading or trailing white spaces.

Example:

Assume that file.txt has the following content:

987-123-4567
123 456 7890
(123) 456-7890

Your script should output the following valid phone numbers:

987-123-4567
(123) 456-7890


# Read from the file file.txt and output all valid phone numbers to stdout.

#1 使用awk
awk '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/' file.txt


#2 使用sed
# -n表示关闭默认输出，默认将自动打印所有行，这样就不会打印出不符合要求的数字串了。-r表示支持扩展正则+ ? () {} |。
#后面的正则表达式和上面都相同，就是后面多了一个p，在用sed时，p和-n合用，表示打印某一行，这样才能把符合要求的行打印出来
sed -n -r '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/p' file.txt

#3 使用grep
grep -P '^(\d{3}-|\(\d{3}\) )\d{3}-\d{4}$' file.txt