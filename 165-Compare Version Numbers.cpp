Compare two version numbers version1 and version2.
If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Example 1:

Input: version1 = "0.1", version2 = "1.1"
Output: -1

Example 2:

Input: version1 = "1.0.1", version2 = "1"
Output: 1

Example 3:

Input: version1 = "7.5.2.4", version2 = "7.5.3"
Output: -1

// My solution: Runtime beats 100% cpp submissions.
// 核心：同位置版本数字的比较。
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i1=0, j1=0, i2=0, j2=0;
        int n1 = version1.size(), n2 = version2.size();
        int v1=0, v2=0;
        while(i1<n1 || j1<n2)
        {
            while(i1<n1 && version1[i1]!='.')
                i1++;
            if(i1<=n1)
                v1 = atoi( (version1.substr(i2, i1-i2)).c_str() );
            while(j1<n2 && version2[j1]!='.')
                j1++;
            if(j1<=n2)
                v2 = atoi( (version2.substr(j2, j1-j2)).c_str() );

            if(v1>v2)
                return 1;
            else if(v1<v2)
                return -1;
            
            v1 = v2 = 0;
            i2 = ++i1;
            j2 = ++j1;
        }
        
        return 0;
    }
};

// Corner cases:
// "01"
// "1"
// Expected 0

// "1.0"
// "1"
// Expected: 0


// 其它解法：
// #1 不使用将字符串转为整型的atoi函数，改成一位一位的累加
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size(), n2 = version2.size();
        int i = 0, j = 0, d1 = 0, d2 = 0;
        while (i < n1 || j < n2) {
            while (i < n1 && version1[i] != '.') {
                d1 = d1 * 10 + version1[i++] - '0';
            }
            while (j < n2 && version2[j] != '.') {
                d2 = d2 * 10 + version2[j++] - '0';
            }
            if (d1 > d2) return 1;
            else if (d1 < d2) return -1;
            d1 = d2 = 0;
            ++i; ++j;
        }
        return 0;
    }
};


// #2 我们也可以借用强大的字符串流stringstream的功能来实现分段和转为整数，使用这种方法写的代码很简洁
class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream v1(version1 + "."), v2(version2 + ".");
        int d1 = 0, d2 = 0;
        char dot = '.';
        while (v1.good() || v2.good()) {
            if (v1.good()) v1 >> d1 >> dot;
            if (v2.good()) v2 >> d2 >> dot;
            if (d1 > d2) return 1;
            else if (d1 < d2) return -1;
            d1 = d2 = 0;
        }
        return 0;
    }
};

// #3 用C语言的字符串指针来实现的方法，这个方法的关键是用到将字符串转为长整型的strtol函数
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int res = 0;
        char *v1 = (char*)version1.c_str(), *v2 = (char*)version2.c_str();
        while (res == 0 && (*v1 != '\0' || *v2 != '\0')) {
            long d1 = *v1 == '\0' ? 0 : strtol(v1, &v1, 10);
            long d2 = *v2 == '\0' ? 0 : strtol(v2, &v2, 10);
            if (d1 > d2) return 1;
            else if (d1 < d2) return -1;
            else {
                if (*v1 != '\0') ++v1;
                if (*v2 != '\0') ++v2;
            }
        }
        return res;
    }
};

// strtol是一个C语言函数，作用就是将一个字符串转换为长整型long，其函数原型为：
// long int strtol (const char* str, char** endptr, int base);

// 下面我们来看下每个参数的意义：
// str是要转换的字符
// enptr是指向第一个不可转换的字符位置的指针
// base的基数，表示转换成为几进制的数
// 两点注意：
// 1) 当 base 的值为 0 时，默认采用 10 进制转换，但如果遇到 '0x' / '0X' 前置字符则会使用 16 进制转换，遇到 '0' 前置字符则会使用 8 进制转换。
// 2) 若endptr 不为NULL，则会将遇到的不符合条件而终止的字符指针由 endptr 传回；若 endptr 为 NULL，则表示该参数无效，或不使用该参数。
