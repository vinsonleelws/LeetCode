A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

For example, the numbers "69", "88", and "818" are all strobogrammatic.

// Reference solution:
// 这道题定义了一种对称数，就是说一个数字旋转180度和原来一样，也就是倒过来看一样，比如609，倒过来还是609等等，满足这种条件的数字其实没有几个，
// 只有0,1,8,6,9。这道题其实可以看做求回文数的一种特殊情况，我们还是用双指针来检测，那么首尾两个数字如果相等的话，那么只有它们是0,1,8中间的一
// 个才行，如果它们不相等的话，必须一个是6一个是9，或者一个是9一个是6，其他所有情况均返回false
// #1
// 双指针
class Solution {
public:
    bool isStrobogrammatic(string num) {
        int l = 0, r = num.size() - 1;
        while (l <= r) {
            if (num[l] == num[r]) 
            {
                if (num[l] != '1' && num[l] != '0' && num[l] != '8')
                    return false;
            } 
            else 
            {
                if ((num[l] != '6' || num[r] != '9') && (num[l] != '9' || num[r] != '6')) 
                    return false;
            }
            ++l; --r;
        }
        return true;
    }
};

// #2 
// 哈希表
// 由于满足题意的数字不多，所以我们可以用哈希表来做，把所有符合题意的映射都存入哈希表中，然后双指针扫描，看对应位置的两个数字是否在哈希表里存在映射，若不存在，返回false，遍历完成返回true
class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> m {{'0', '0'}, {'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};
        for (int i = 0; i <= num.size() / 2; ++i) {
            if (m[num[i]] != num[num.size() - i - 1]) return false;
        }
        return true;
    }
};