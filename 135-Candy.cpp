There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

    Each child must have at least one candy.
    Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give?

Example 1:

Input: [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

Example 2:

Input: [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
             The third child gets 1 candy because it satisfies the above two conditions.

// 遍历两次的方法：
// 第一遍从左向右遍历，如果右边的小盆友的等级高，等加一个糖果，这样保证了一个方向上高等级的糖果多。然后再从右向左遍历一遍，如果左边的等级比右边的高，
// 而且左边的糖果又小于等于右边的话，则左边糖果数为右边糖果数加一。最后再把所有小盆友的糖果数都加起来返回即可。
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> nums(n,1);
        for(int i=0; i<n-1; i++)
            if(ratings[i]<ratings[i+1])
                nums[i+1] = nums[i]+1;
        
        for(int i=n-1; i>0; i--)
        {
            if(ratings[i-1]>ratings[i])
            {
                if(nums[i-1]<=nums[i])
                    nums[i-1] = nums[i]+1;
            }
        }
        
        int sum=0;
        for(int i = 0; i<n; i++)
            sum += nums[i];
        
        return sum;
    }
};


// 下面是一次遍历的方法：首先我们给第一个同学一个糖果，那么对于接下来的一个同学就有三种情况：
// 1. 接下来的同学的rating等于前一个同学，那么给接下来的同学一个糖果就行。
// 2. 接下来的同学的rating大于前一个同学，那么给接下来的同学的糖果数要比前一个同学糖果数加1。
// 3.接下来的同学的rating小于前一个同学，那么我们此时不知道应该给这个同学多少个糖果，需要看后面的情况。
// 对于第三种情况，我们不确定要给几个，因为要是只给1个的话，那么有可能接下来还有rating更小的同学，总不能一个都不给吧。也不能直接给前一个同学的糖果数减1，有可能给多了，
// 因为如果后面再没人了的话，其实只要给一个就行了。还有就是，如果后面好几个rating越来越小的同学，那么前一个同学的糖果数可能还得追加，以保证最后面的同学至少能有1个糖果。
// eg: 四个同学，他们的rating如下：
// 1 3 2 1
// 先给第一个rating为1的同学一个糖果，然后从第二个同学开始遍历，第二个同学rating为3，比1大，所以多给一个糖果，第二个同学得到两个糖果。下面第三个同学，他的rating为2，
// 比前一个同学的rating小，如果我们此时给1个糖果的话，那么rating更小的第四个同学就得不到糖果了，所以我们要给第四个同学1个糖果，而给第三个同学2个糖果，此时要给第二个
// 同学追加1个糖果，使其能够比第三个同学的糖果数多至少一个。那么我们就需要统计出多有个连着的同学的rating变小，用变量cnt来记录，找出了最后一个减小的同学，那么就可以往
// 前推，每往前一个加一个糖果，这就是个等差数列，我们可以直接利用求和公式算出这些rating减小的同学的糖果之和。然后我们还要看第一个开始减小的同学的前一个同学需不需要追
// 加糖果，只要比较cnt和pre的大小，pre是之前同学得到的最大糖果数，二者做差加1就是需要追加的糖果数，加到结果res中即可。
class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.empty()) return 0;
        int res = 1, pre = 1, cnt = 0;
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] >= ratings[i - 1]) {
                if (cnt > 0) {
                    res += cnt * (cnt + 1) / 2;
                    if (cnt >= pre) res += cnt - pre + 1;
                    cnt = 0;
                    pre = 1;
                }
                pre = (ratings[i] == ratings[i - 1]) ? 1 : pre + 1;
                res += pre;
            } else {
                ++cnt;
            }
        }     
        if (cnt > 0) {
            res += cnt * (cnt + 1) / 2;
            if (cnt >= pre) res += cnt - pre + 1;
        }
        return res;
    }
};
