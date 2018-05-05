93. Restore IP Addresses


             // pre指O��|a
、O��|a
、O��|a

Note:

    The number of elements initialized in nums1 and nums2 are m and n respectively.
    You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.

Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]

// 避免使用辅助数组或插入扰动的方法：
// 思路：由于合并后A数组的大小必定是m+n，所以从最后面开始往前赋值，先比较A和B中最后一个元素的大小，
// 把较大的那个插入到m+n-1的位置上，再依次向前推。如果A中所有的元素都比B小，那么前m个还是A原来的内容，没有改变。
// 如果A中的数组比B大的，当A循环完了，B中还有元素没加入A，直接用个循环把B中所有的元素覆盖到A剩下的位置。

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int end = m+n-1;
        int i = m-1, j= n-1;
        
        while(i>=0 && j>=0)
            nums1[end--] = nums1[i] >= nums2[j] ? nums1[i--] : nums2[j--];
        
        while(j>=0)
            nums1[end--] = nums2[j--];
    }
};

// Testing cases:
// [4,0,0,0,0,0]
// 1
// [1,2,3,5,6]
// 5
// Expected: [1,2,3,4,5,6]