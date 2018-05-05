Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

click to show corner cases.

Corner Cases:

 

 

    Did you consider the case where path = "/../"?
    In this case, you should return "/".
    Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
    In this case, you should ignore redundant slashes and return "/home/foo".

// 首先总结出简化规则：
// 1) 多重"/"和末尾的"/"可去除，如// --> /，以及/home/ --> /home;
// 2) 遇到"."可去除;
// 3) 遇到".."可去除其前面一个目录;
// 4) 在进行以上操作的最后需确认目录是否为空，如果是则返回"/".

// 在具体操作上，可以使用一个vector<string>来存储目录，
// 每次扫描目前前面尽可能多的'/'，然后判断目录是否为".."或"."进行分情况讨论。
    
class Solution {
public:
    string simplifyPath(string path) {
        int len = path.length();
        if(len==0 || len==1)
            return path;
        
        vector<string> dir;
        int i=0;
        while(i<len)
        {
            while(i<len && path[i]=='/')    // Eat '/' as many as possible
                i++;
            if(i==len)
                break;
            
            int start = i;
            while(i<len && path[i]!='/')
                i++;
            string s = path.substr(start, i-start);
            if(s == "..")
            {
                if(dir.size())
                    dir.pop_back();
            }
            else if(s!=".")
            {
                dir.push_back(s);
            }
        }
        
        if(dir.empty())
            return "/";
        else
        {
            string result;
            for(int i=0; i<dir.size(); i++)
                result+="/"+dir[i];
            
            return result;
        }
    }
};


// 其它不同解法：
// #1
// 利用了C语言中的函数strtok来分隔字符串，思想和以上解法相同
// 但需要注意string和char*的类型相互转换
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        char *cstr = new char[path.length() + 1];
        strcpy(cstr, path.c_str());
        char *pch = strtok(cstr, "/");
        while (pch != NULL) {
            string p = string(pch);
            if (p == "..") {
                if (!v.empty()) v.pop_back();
            } else if (p != ".") {
                v.push_back(p);
            }
            pch = strtok(NULL, "/");
        }
        if (v.empty()) return "/";
        string res;
        for (int i = 0; i < v.size(); ++i) {
            res += '/' + v[i];
        }
        return res;
    }
};

// #2
// 使用stringstream和getline来获取每个目录名，然后对每一段分别处理，思路和上面的方法相似
class Solution {
public:
    string simplifyPath(string path) {
        string res, t;
        stringstream ss(path);
        vector<string> v;
        while (getline(ss, t, '/')) {
            if (t == "" || t == ".") continue;
            if (t == ".." && !v.empty()) v.pop_back();
            else if (t != "..") v.push_back(t);
        }
        for (string s : v) res += "/" + s;
        return res.empty() ? "/" : res;
    }
};