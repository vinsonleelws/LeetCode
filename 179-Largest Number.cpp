Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"

Example 2:

Input: [3,30,34,5,9]
Output: "9534330"

Note: The result may be very large, so you need to return a string instead of an integer.

// 自定义排序：
// 对于两个数字a和b来说，如果将其都转为字符串，如果ab > ba，则a排在前面，比如9和34，由于934>349，所以9排在前面，再比如说30和3，由于303<330，所以3排在30的前面。
// 按照这种规则对原数组进行排序后，将每个数字转化为字符串再连接起来就是最终结果。
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        sort(nums.begin(), nums.end(), [](int a, int b) {
           return to_string(a) + to_string(b) > to_string(b) + to_string(a); 
        });
        for (int i = 0; i < nums.size(); ++i)
            res += to_string(nums[i]);
        
        return res[0] == '0' ? "0" : res;
    }
};

// 另一种写法
class Solution {
public:
    static bool compare(int a, int b)
    {
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    }
    
    string largestNumber(vector<int>& nums) {
        string res;
        sort(nums.begin(), nums.end(), compare);
        for (int i = 0; i < nums.size(); ++i)
            res += to_string(nums[i]);
        
        return res[0] == '0' ? "0" : res;
    }
};