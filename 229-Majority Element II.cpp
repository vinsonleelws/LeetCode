/* Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Note: The algorithm should run in linear time and in O(1) space.

Example 1:

Input: [3,2,3]
Output: [3]

Example 2:

Input: [1,1,1,3,3,2,2,2]
Output: [1,2]
 */

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
    }
};

// 众数II（找次数超|_n/3_|的数）  [M]
// 找规律（摩尔投票法，O(n)，O(1)）

// 这题要求我们用O(1)的时间和空间复杂度，意味着不能使用排序和哈希表来解。
// 我们还是采用"169-Majority Element"中的摩尔投票法来做：
// 经过举例分析可以得出，任意一个数组出现次数大于n/3的众数最多有两个。我们使用投票法的核心是找出两个候选众数进行投票，需要两遍遍历，
// 第一遍历找出两个候选众数，第二遍遍历重新投票验证这两个候选众数是否为众数即可，选候选众数方法和前面"169-Majority Element"求众数一样，
// 由于之前那题题目中限定了一定会有众数存在，故而省略了验证候选众数的步骤，这道题却没有这种限定，即满足要求的众数可能不存在，所以要有验证。

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int m = 0, n = 0, cm = 0, cn = 0;
        // 查找
        for (auto &a : nums)
        {
            if (a == m)
                ++cm;
            else if (a == n)
                ++cn;
            else if (cm == 0)
                m = a, cm = 1;
            else if (cn == 0)
                n = a, cn = 1;
            else
                --cm, --cn;
        }

        // 验证
        cm = cn = 0;
        for (auto &a : nums)
        {
            if (a == m)
                ++cm;
            else if (a == n)
                ++cn;
        }
        if (cm > nums.size() / 3)
            res.push_back(m);
        if (cn > nums.size() / 3)
            res.push_back(n);

        return res;
    }
};