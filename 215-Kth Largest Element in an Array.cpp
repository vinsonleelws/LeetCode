Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5

Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.

// #1
// My solution:
// 基于快排的解法：
// 我们只需使用快排使数组中下标为n-k的数的左边都小于等于它，右边都大于等于它，返回数组下标为n-k的数即可
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0, high = n-1;
        while (true) 
        {
            int pos = QuickSort(nums, low, high);
            if (pos == n-k) 
                return nums[pos];
            else if (pos > n-k) 
                high = pos - 1;
            else 
                low = pos + 1;
        }
    }
    
    int QuickSort(vector<int>& nums, int low, int high)
    {
        if(nums.size() == 0 || low >= high)
            return low;
        
        int start = low;
        int end = high;
        int key = nums[start]; 
     
        while(start < end)
        {
            while(start < end && nums[end] >= key)
                --end;
     
            nums[start] = nums[end];
     
            while(start < end && nums[start] <= key)
                ++start;
             
            nums[end] = nums[start];
        }
        nums[start] = key;
        return start;
        //QuickSort(nums, low, start-1);
        //QuickSort(nums, start+1, high);
    }
};


// #2
// 直接使用sort的方法，简单粗暴（本质上也是基于快速排序）
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

// #3
// 基于priority_queue的自动排序的特性，跟上面的解法思路上没有什么区别，我们也可以换成multiset来做~
// Priority queue
// Priority queues are a type of container adaptors, specifically designed such that its first element is always the greatest of the elements it contains, 
// according to some strict weak ordering criterion.
// This context is similar to a heap, where elements can be inserted at any moment, and only the max heap element can be retrieved (the one at the top in the priority queue).

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; ++i) {
            q.pop();
        }
        return q.top();
    }
};