/*
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true

Example 2:

Input: [1,2,3,4]
Output: false

Example 3:

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
    }
};

// 包含重复值  [E]
// Hash Table ; Sort + 遍历

// 有两种方法：1是排序后遍历，2是使用哈希表

// #1 排序+遍历
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) return true;
        }
        return false;
    }
};

// #2 哈希表
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) 
        {
            if (m.find(nums[i]) != m.end()) 
                return true;
            ++m[nums[i]];
        }
        return false;
    }
};


