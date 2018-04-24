Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

// 只需要遍历一次即可的解法，这个算法需要start和end两个指针分别指向数组的首尾位置，
// 从两边向中间扫描，在当前两指针确定的范围内，先比较两头找出较小值，如果较小值是start指向的值，
// 则从左向右扫描，如果较小值是end指向的值，则从右向左扫描，若遇到的值比当较小值小，
// 则将差值存入结果，如遇到的值大，则重新确定新的窗口范围，以此类推直至start和end指针重合.

class Solution {
public:
    int trap(vector<int>& height) {
        int sum=0;
        int start=0, end=height.size()-1;
        while(start<end)
        {
            int n = min(height[start], height[end]);
            if(n==height[start])
            {   
                start++;
                while(start<end && height[start]<=n)
                    sum+=n-height[start++];
            }
            else
            {
                end--;
                while(start<end && height[end]<=n)
                    sum+=n-height[end--];
            }
        }
        return sum;
    }
};


// 使用stack的解法：
// 遍历高度，如果此时栈为空，或者当前高度小于等于栈顶高度，则把当前高度的坐标压入栈，
// 注意我们不直接把高度压入栈，而是把坐标压入栈，这样方便我们在后来算水平距离。
// 当我们遇到比栈顶高度大的时候，就说明有可能会有坑存在，可以装雨水。此时我们栈里至少有一个高度，
// 如果只有一个的话，那么不能形成坑，我们直接跳过，如果多余一个的话，那么此时把栈顶元素取出来当作坑，新的栈顶元素就是左边界，
// 当前高度是右边界，只要取二者较小的，减去坑的高度，长度就是右边界坐标减去左边界坐标再减1，二者相乘就是盛水量.

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int i = 0, res = 0, n = height.size();
        while (i < n) {
            if (st.empty() || height[i] <= height[st.top()]) {
                st.push(i++);
            } else {
                int t = st.top(); st.pop();
                if (st.empty()) continue;
                res += (min(height[i], height[st.top()]) - height[t]) * (i - st.top() - 1);
            }
        }
        return res;
    }
};

// 基于动态规划的解法：
// 维护一个一维的dp数组，这个DP算法需要遍历两遍数组，
// 第一遍遍历dp[i]中存入i位置左边的最大值，然后开始第二遍遍历数组，
// 第二次遍历时找右边最大值，然后和左边最大值比较取其中的较小值，然后跟当前值height[i]相比，
// 如果大于当前值，则将差值存入结果。
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, mx = 0, n = height.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            dp[i] = mx;
            mx = max(mx, height[i]);
        }
        mx = 0;
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = min(dp[i], mx);
            mx = max(mx, height[i]);
            if (dp[i] > height[i]) res += dp[i] - height[i];
        }
        return res;
    }
};


// Input: [4,2,3]
// Expected: 1