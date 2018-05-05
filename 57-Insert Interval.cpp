Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
// My solution: 
// 直接修改原Interval数组，空间复杂度O(1)
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if(intervals.empty())
            return {newInterval};
        
        if(newInterval.start > intervals[intervals.size()-1].end)  // head
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        else if(newInterval.end < intervals[0].start)  // tail
        {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
            
        for(int i=0; i<intervals.size(); i++)
        {
            if(i>0 && newInterval.start>intervals[i-1].end && newInterval.end<intervals[i].start) //mid
            {
                intervals.insert(intervals.begin()+i, newInterval);
                return intervals;
            }
            else  // overlap
            {
                if(newInterval.start<=intervals[i].end)
                {
                    intervals[i].start = min(intervals[i].start, newInterval.start);
                    intervals[i].end = max(intervals[i].end, newInterval.end);
                    for(int j=i+1; j<intervals.size(); j++)
                    {
                        if(intervals[j].start<=intervals[i].end)
                        {
                            intervals[i].end = max(intervals[j].end, intervals[i].end);
                            intervals.erase(intervals.begin()+j);
                            j--;
                        }
                    }
                    return intervals;
                }
            }
        }
        
        return intervals;
    }
};


// Reference solution:
// #1
// 思路：
// 我们用一个变量cur来遍历区间，如果当前cur区间的结束位置小于要插入的区间的起始位置的话，
// 说明没有重叠，则将cur区间加入结果res中，然后cur自增1。直到有cur越界或有重叠while循环退出，
// 然后再用一个while循环处理所有重叠的区间，每次用取两个区间起始位置的较小值，和结束位置的较大值来更新要插入的区间，
// 然后cur自增1。直到cur越界或者没有重叠时while循环退出。之后将更新好的新区间加入结果res，然后将cur之后的区间再加入结果res中即可.
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int n = intervals.size(), cur = 0;
        while (cur < n && intervals[cur].end < newInterval.start) {
            res.push_back(intervals[cur++]);
        }
        while (cur < n && intervals[cur].start <= newInterval.end) {
            newInterval.start = min(newInterval.start, intervals[cur].start);
            newInterval.end = max(newInterval.end, intervals[cur].end);
            ++cur;
        }
        res.push_back(newInterval);
        while (cur < n) {
            res.push_back(intervals[cur++]);
        }
        return res;
    }
};

// #2
// 下面这种方法的思路跟上面的解法很像，只不过没有用while循环，而是使用的是for循环，
// 但是思路上没有太大的区别，变量cur还是用来记录新区间该插入的位置，
// 稍有不同的地方在于在for循环中已经将新区间后面不重叠的区间也加进去了，for循环结束后就只需要插入新区间即可.
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int n = intervals.size(), cur = 0;
        for (int i = 0; i < n; ++i) {
            if (intervals[i].end < newInterval.start) {
                res.push_back(intervals[i]);
                ++cur;
            } else if (intervals[i].start > newInterval.end) {
                res.push_back(intervals[i]);
            } else {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
        }
        res.insert(res.begin() + cur, newInterval);
        return res;
    }
};

// #3:
// 下面这种解法就是把上面解法的for循环改为了while循环，其他的都没有变
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int n = intervals.size(), cur = 0, i = 0;
        while (i < n) {
            if (intervals[i].end < newInterval.start) {
                res.push_back(intervals[i]);
                ++cur;
            } else if (intervals[i].start > newInterval.end) {
                res.push_back(intervals[i]);
            } else {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
            ++i;
        }
        res.insert(res.begin() + cur, newInterval);
        return res;
    }
};

// Testing cases:
// Input: []        // 注意intervals为空而newInterval不为空的情况
//        [5,7]
// Expected: [[5,7]]

// Input: [[1,5]]   // 注意newInterval插入到头和尾的情况
//        [6,8]
// Expected: [[1,5],[6,8]]

// Input: [[1,5]]   // 注意newInterval的start比较小的情况
//        [0,3]
// Expected: [[0,5]]

// Input: [[3,5],[12,15]]   // 插入到中间的情况
//        [6,6]
// Expected: [[3,5],[6,6],[12,15]]