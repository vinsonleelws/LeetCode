Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition.


// 数字的格式可以用A[.[B]][e|EC]或者.B[e|EC]表示，其中A和C都是
// 整数（可以有正负号，也可以没有），而B是一个无符号整数

// 思路：
// 首先应去出尽可能多的空格；
// +/-号后面必有数字或小数点；
// 小数点前后可以同时都有数字，也可以一个有，另一个没有；
// e/E前后必有数字，其中后面可以有由+/-构成的整数（不能有小数点）；
// 最后还需注意处理可能存在的空格。

class Solution {
public:
    bool isNumber(string s) {
        if(s.empty())
            return false;
        int len = s.length();
        int i=0;
        while(i<len && s[i]==' ')
            i++;
        if(i==len)
            return false;
        
        bool numeric = scanInt(s, i);
        if(i==len && numeric)
            return true;
        
        if(s[i]=='.')
        {
            i++;
            numeric = scanUnsignedInt(s, i) || numeric;  // Note that scan... before ||...
            // 上一行代码用||的原因：
            // 1. 小数可以没有整数部分，例如.123等于0.123；
            // 2. 小数点后面可以没有数字，例如233.等于233.0；
            // 3. 当然小数点前面和后面可以有数字，例如233.666
        }
        
        if(s[i]=='e' || s[i]=='E')
        {
            i++;
            numeric = numeric && scanInt(s, i);
            // 上一行代码用&&的原因：
            // 1. 当e或E前面没有数字时，整个字符串不能表示数字，例如.e1、e1；
            // 2. 当e或E后面没有整数时，整个字符串不能表示数字，例如12e、12e+5.4
        }
        
        // Remove the last white spaces
        while(i<len && s[i]==' ')
            i++;
            
        return numeric&&(i==len);
    }
    
    bool scanInt(const string& s, int& i)
    {
        if(s[i]=='+'||s[i]=='-')
            i++;
        
        int start = i;  // Note that start after +/-
        if(i==s.length())
            return false;
        
        while(i<s.length() && s[i]>='0' && s[i]<='9')
            i++;
        
        return i-start;
    }
    
    bool scanUnsignedInt(const string& s, int& i)
    {
        int start = i;
        while(i<s.length() && s[i]>='0' && s[i]<='9')
            i++;
        return i-start;
    }
};

// Testing cases:
// Input: "1 "      // 注意后面的空格也要清除
// Expected: true

// Input: " -."
// Expected: false