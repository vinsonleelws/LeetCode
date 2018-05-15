Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:

Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

Note:

    Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
    Could you do it in-place with O(1) extra space?

    
// Reference solution:

// #1 
// Cyclic Replacements 循环置换法
// 首先找到位置变换的映射表达式，对于位置i的数字，旋转后它的位置变为(i+k)%n
// 然后我们对数字进行循环置换。
// 以Example 1为例：
// 每一步操作的过程如下：
// 1 2 3 4 5 6 7
// 1 2 3 1 5 6 7
         -
// 1 2 3 1 5 6 4
               -
// 1 2 7 1 5 6 4
       -
// 1 2 7 1 5 3 4
             -       
// 1 6 7 1 5 3 4
     -
// 1 6 7 1 2 3 4
           -
// 5 6 7 1 2 3 4
   -
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty() || (k %= nums.size()) == 0) 
            return;
        int n = nums.size(), start = 0, i = 0, cur = nums[i], cnt = 0;
        while (cnt++ < n) 
        {
            i = (i + k) % n;
            int t = nums[i];
            nums[i] = cur;
            if (i == start) 
            {
                ++start; ++i;
                cur = nums[i];
            } 
            else 
            {
                cur = t;
            }
        }
    }
};

// #2
// 空间复杂度为O(n)的方法，仍然是利用位置映射表达式，只需3行
// 复制一个和nums一样的数组，然后利用映射关系i -> (i+k)%n来交换数字
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> t = nums;
        for (int i = 0; i < nums.size(); ++i) 
            nums[(i + k) % nums.size()] = t[i];
    }
};


// #3
// Using Reverse
// 类似翻转字符的方法，思路是先把前n-k个数字翻转一下，再把后k个数字翻转一下，最后再把整个数组翻转一下
// eg:
// 1 2 3 4 5 6 7
// 4 3 2 1 5 6 7
// 4 3 2 1 7 6 5
// 5 6 7 1 2 3 4
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty() || (k %= nums.size()) == 0) return;
        int n = nums.size();
        reverse(nums.begin(), nums.begin() + n - k);
        reverse(nums.begin() + n - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

// #4
// 由于旋转数组的操作也可以看做从数组的末尾取k个数组放入数组的开头，所以我们用STL的push_back和erase可以很容易的实现这些操作。
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty() || (k %= nums.size()) == 0) return;
        int n = nums.size();
        for (int i = 0; i < n - k; ++i) {
            nums.push_back(nums[0]);
            nums.erase(nums.begin());
        }
    }
};

// #5
// 基于交换的方法。
// eg:
// 1 2 3 4 5 6 7
// 5 2 3 4 1 6 7
   -       -
// 5 6 3 4 1 2 7
     -       -
// 5 6 7 4 1 2 3
       -       -
// 5 6 7 1 4 2 3
         - -
// 5 6 7 1 2 4 3
           - -
// 5 6 7 1 2 3 4
             - -
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) 
            return;
        int n = nums.size(), start = 0;   
        while (n && (k %= n)) 
        {
            for (int i = 0; i < k; ++i) {
                swap(nums[i + start], nums[n - k + i + start]);
            }
            n -= k;
            start += k;
        }
    }
};