The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

 

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int numRows);

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

class Solution {
public:
    string convert(string s, int numRows) {
        if(s.length()<=2 || numRows<=1)
            return s;
        
        string result;

        string firstRow;
        int j=0;
        while(j<s.length())
        {
            firstRow.push_back(s[j]);
            j+=(2*numRows-2);
        }
        
        string midRow;
        for(int i=1, interval=2*numRows-4; i<=numRows-2 && interval>=1; i++, interval = interval-2)  // interval = interval-2
        {
            int k = i;
            int l = i+interval;
            while(k<s.length() || l<s.length())
            {
                if(k<s.length())
                    midRow.push_back(s[k]);
                if(l<s.length())
                    midRow.push_back(s[l]);
                k+=(2*numRows-2);
                l+=(2*numRows-2);
            }
        }
        
        string lastRow;
        j=numRows-1;
        while(j<s.length())
        {
            lastRow.push_back(s[j]);
            j+=(2*numRows-2);
        }
        
        result = firstRow+midRow+lastRow;
        return result;
    }
};

//
// Input: "ABCDE"
// 4
// Expected: "ABCED"

// "PAYPALISHIRING"
// 3