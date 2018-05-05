Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considerred overlapping.

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if(intervals.empty())
            return result;
        sort(intervals.begin(), intervals.end(), compare);
        result.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++)
        {
            if(intervals[i].start<=result.back().end)
                result.back() = Interval(result.back().start, max(intervals[i].end, result.back().end));
            else
                result.push_back(intervals[i]);
        }
    
        return result;
    }
    
    static bool compare(Interval arg1, Interval arg2)
    {
        if(arg1.start==arg2.start)
            return arg1.end<arg2.end;
        else
            return arg1.start<arg2.start;
    }
};

// Testing cases:
// Input: [[1,4],[2,3]]  // 注意完全覆盖的情况
// Expected: [[1,4]]