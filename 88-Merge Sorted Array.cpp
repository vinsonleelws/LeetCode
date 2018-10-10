/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

    The number of elements initialized in nums1 and nums2 are m and n respectively.
    You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.

Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
*/

// 88-�ϲ�������������  (E)
// Two Pointers

// ��Ŀ��num1���㹻��Ŀռ�(>=m+n)
// �Ӻ���ǰ��ֵ���ȱȽ�num1��num2�����һ��Ԫ�صĴ�С���ѽϴ�ĸ��Ƶ�num1��m+n-1λ���ϣ�������ǰ�ơ�

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int end = m + n - 1;
		int i = m - 1, j = n - 1;

		while (i >= 0 && j >= 0)
			nums1[end--] = nums1[i] >= nums2[j] ? nums1[i--] : nums2[j--];

		while (j >= 0)
			nums1[end--] = nums2[j--];
	}
};

// Testing cases:
// [4,0,0,0,0,0]
// 1
// [1,2,3,5,6]
// 5
// Expected: [1,2,3,4,5,6]