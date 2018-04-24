(4) Median of Two Sorted Arrays
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0

Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5


// Reference solution: (100ms)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        double right, left;
        for(int i = 0, j = 0, k = 0; k != total / 2 + 1; k++)
        {
            right = left;
            if(i == nums1.size())
                left = nums2[j++];
            else if(j == nums2.size())
                left = nums1[i++];
            else if(nums1[i] < nums2[j])
                left = nums1[i++];
            else
                left = nums2[j++];
        }
        
        if(total % 2 == 0)
            return (left + right) / 2;
        else
            return left;
    }
};

// 设total为数组的大小.
// 关于中位数：当数组大小为奇数时，mid = data[total/2]; 
// 当数组大小为偶数时，mid = data[total/2] + data[total/2 -1];


// My solution:  (102ms)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        unsigned int size1 = nums1.size();
        unsigned int size2 = nums2.size();
        
        if(nums1.empty() && nums2.empty())
            return 0.0;
        
        if(nums1.empty())
        {
            if((size2&0x1) == 0) //(size2&0x1): Be sure to put parentheses.
                return (double)(nums2[size2/2] + nums2[size2/2-1]) / 2.0;
            else
                return nums2[size2/2];
        }
        else if(nums2.empty())
        {
            if((size1&0x1) == 0)  
                return (double)(nums1[size1/2] + nums1[size1/2-1]) / 2.0;
            else
                return nums1[size1/2];
        }
        
        int i=0, j=0;
        int count=0;
        int mid = (size1+size2)/2;
        bool even_size = false;
        if(((size1+size2)&0x1)==0)
            even_size = true;
        
        while(count<=mid+1)  // +1 means considering two arrays as one array
        {
            if(count == mid+1)
                break;
            
            if(i<=size1-1 && j<=size2-1)
                (nums1[i] <= nums2[j])? ++i : ++j;
            else if(i<=size1-1)
                ++i;
            else if(j<=size2-1)
                ++j;
            
            count++;
        }
        
        cout<<"i: "<<i << " j: "<<j<<" mid: "<<mid<<endl;
        cout<<"count: "<< count<<endl;
        double result = 0.0;
        
        if(i==0)
        {
            result = nums2[j-1];
            if(even_size)
            {
                result+=nums2[j-2];
                result /= 2.0;
            }
            return result;
        }
        
        if(j==0)
        {
            result = nums1[i-1];
            if(even_size)
            {
                result+=nums1[i-2];
                result /= 2.0;
            }
            return result;
        }
        
        if(nums1[i-1]>nums2[j-1])
        {
            result = nums1[i-1];
            if(even_size)
            {
                if(i>=2)
                {
                    if(nums1[i-2]>nums2[j-1])
                        result+=nums1[i-2];
                    else
                        result+=nums2[j-1];
                }
                else
                    result += nums2[j-1];
                    
            }
        }
        else
        {
            result = nums2[j-1];
            if(even_size)
            {
                if(j>=2)
                {
                    if(nums2[j-2]>nums1[i-1])
                        result+=nums2[j-2];
                    else
                        result+=nums1[i-1];
                }
                else
                    result += nums1[i-1];
            }
        }
        
        cout<<"result: "<<result<<endl;
        
        if(even_size)
            result /= 2.0;
        
        return result;
        
    }
};
