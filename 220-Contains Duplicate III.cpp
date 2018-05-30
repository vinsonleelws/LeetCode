Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

Example 1:

Input: [1,2,3,1], k = 4, t = 0
Output: true

Example 2:

Input: [1,0,1,1], k = 1, t = 0
Output: true

Example 3:

Input: [4,2], k = 2, t = 1 
Output: false

// 与"219-Contains Duplicate II"一样，此题如果使用Brute force会TLE。还是应当使用哈希表来解，注意两个限制条件即可：两个数字的坐标差不能大于k，值差不能大于t。
// 这里需要两个指针i和j，刚开始i和j都指向0，然后i开始向右走遍历数组，如果i和j之差大于k，且m中有nums[j]，则删除并j加一。这样保证了m中所有的数的下标之差都不大于k，
// 然后我们用map数据结构的lower_bound()函数来找一个特定范围，就是大于或等于nums[i] - t的地方。然后检测后面的所有的数字，如果数的差的绝对值小于等于t，则返回true。最后遍历完整个数组返回false。
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long long, int> m;
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) 
        {
            if (i - j > k) m.erase(nums[j++]);
            auto a = m.lower_bound((long long)nums[i] - t);
            if (a != m.end() && abs(a->first - nums[i]) <= t) 
                return true;
            m[nums[i]] = i;
        }
        return false;
    }
};


// std::map::lower_bound

// iterator lower_bound (const key_type& k);
// const_iterator lower_bound (const key_type& k) const;

// Return iterator to lower bound
// Returns an iterator pointing to the first element in the container whose key is not considered to go before k (i.e., either it is equivalent or goes after).