Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Return 0 if the array contains less than 2 elements.

Example 1:

Input: [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either
             (3,6) or (6,9) has the maximum difference 3.

Example 2:

Input: [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.

Note:

    You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
    Try to solve it in linear time/space.


// Reference solution:
// #1 Sort the entire array. Then iterate over it to find the maximum gap between two successive elements.
class Solution {
public:
    int maximumGap(vector<int>& nums)
    {
        if (nums.size() < 2)            // check if array is empty or small sized
            return 0;

        sort(nums.begin(), nums.end());                 // sort the array

        int maxGap = 0;

        for (int i = 0; i < nums.size() - 1; i++)
            maxGap = max(nums[i + 1] - nums[i], maxGap);

        return maxGap;
    }
};
// Time complexity: O(nlog(n))
// Space complexity: No extra space needed, other than the input array (since sorting can usually be done in-place).


// #2 基于基排序的方法：
// This approach is similar to Approach #1, except we use Radix Sort instead of a traditional comparison sort.
class Solution {
public:
    int maximumGap(vector<int>& nums)
    {
        if (nums.size() < 2)
            return 0;

        int maxVal = *max_element(nums.begin(), nums.end());

        int exp = 1;                                 // 1, 10, 100, 1000 ...
        int radix = 10;                              // base 10 system

        vector<int> aux(nums.size());

        /* LSD Radix Sort */
        while (maxVal / exp > 0) {                   // Go through all digits from LSD to MSD
            vector<int> count(radix, 0);

            for (int i = 0; i < nums.size(); i++)    // Counting sort
                count[(nums[i] / exp) % 10]++;

            for (int i = 1; i < count.size(); i++)   // you could also use partial_sum()
                count[i] += count[i - 1];

            for (int i = nums.size() - 1; i >= 0; i--)
                aux[--count[(nums[i] / exp) % 10]] = nums[i];

            for (int i = 0; i < nums.size(); i++)
                nums[i] = aux[i];

            exp *= 10;
        }

        int maxGap = 0;

        for (int i = 0; i < nums.size() - 1; i++)
            maxGap = max(nums[i + 1] - nums[i], maxGap);

        return maxGap;
    }
};

// Time complexity: O(d(n+k))≈O(n)
// Space complexity: O(n+k)≈O(n)


// #3 基于桶排序的方法：
// 参考思路：
// 这里用桶排序Bucket Sort来做:
// 首先找出数组的最大值和最小值，然后要确定每个桶的容量，即为(最大值 - 最小值)/个数 + 1，再确定桶的个数，即为
// (最大值 - 最小值)/桶的容量 + 1，然后需要在每个桶中找出局部最大值和最小值，而最大间距的两个数不会在同一个桶中，
// 而是一个桶的最小值和另一个桶的最大值之间的间距。
class Solution {
public:
    int maximumGap(vector<int> &numss) {
        if (numss.empty()) return 0;
        int mx = INT_MIN, mn = INT_MAX, n = numss.size();
        for (int d : numss) {
            mx = max(mx, d);
            mn = min(mn, d);
        }
        int size = (mx - mn) / n + 1;
        int bucket_nums = (mx - mn) / size + 1;
        vector<int> bucket_min(bucket_nums, INT_MAX);
        vector<int> bucket_max(bucket_nums, INT_MIN);
        set<int> s;
        for (int d : numss) {
            int idx = (d - mn) / size;
            bucket_min[idx] = min(bucket_min[idx], d);
            bucket_max[idx] = max(bucket_max[idx], d);
            s.insert(idx);
        }
        int pre = 0, res = 0;
        for (int i = 1; i < n; ++i) {
            if (!s.count(i)) continue;
            res = max(res, bucket_min[i] - bucket_max[pre]);
            pre = i;
        }
        return res;
    }
};