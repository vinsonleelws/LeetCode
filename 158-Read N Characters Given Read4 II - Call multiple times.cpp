The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

Note:
The read function may be called multiple times. 


// Reference solution:
// #1
// 参考思路：
// 用两个变量readPos和writePos来记录读取和写的位置，i从0到n开始循环，如果此时读和写的位置相同，那么我们调用read4函数，将结果赋给writePos，把readPos置零，
// 如果writePos为零的话，说明buf中没有东西了，返回当前的坐标i。然后我们用内置的buff变量的readPos位置覆盖输入字符串buf的i位置，如果完成遍历，返回n。
class Solution {
public:
    int read(char *buf, int n) {
        for (int i = 0; i < n; ++i) 
        {
            if (readPos == writePos) 
            {
                writePos = read4(buff);
                readPos = 0;
                if (writePos == 0) 
                    return i;
            }
            buf[i] = buff[readPos++];
        }
        return n;
    }
private:
    int readPos = 0, writePos = 0;
    char buff[4];
};

// #2
// 下面这种方法和上面的方法基本相同，稍稍改变了些解法，使得看起来更加简洁一些。
class Solution {
public:
    int read(char *buf, int n) {
        int i = 0;
        while (i < n && (readPos < writePos || (readPos = 0) < (writePos = read4(buff))))
            buf[i++] = buff[readPos++];
        return i;
    }
    char buff[4];
    int readPos = 0, writePos = 0;
};