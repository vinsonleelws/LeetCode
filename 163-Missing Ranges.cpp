Given a sorted integer array where the range of elements are [0, 99] inclusive, return its missing ranges.
For example, given [0, 1, 3, 50, 75], return [“2”, “4->49”, “51->74”, “76->99”] 

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        
    }
};

// ---------------------------------------------------------------------------------
// Reference solution:
// 参考思路：
// 这道题让我们求缺失区间，跟"228-Summary Ranges"很类似，这道题让我们求缺失的空间，给了一个空间的范围[lower upper]，缺失的空间的范围需要在给定的空间范围内。
// 我们首先将lower赋给l，然后开始遍历nums数组，如果i小于nums长度且当前数字小于等于upper，我们让r等于当前数字，否则如果当i等于nums的长度时或者当前数字大于upper时，
// 将r赋为upper+1。然后判断l和r的值，若相同，l自增1，否则当r大于l时，说明缺失空间存在，我们看l和r是否差1，如果是，说明只缺失了一个数字，若不是，则说明缺失了一个区间，
// 我们分别加上数字或者区间即可。

// 自己的理解：
// 使用两个变量l和r，每次l记录的是当前区间最小值，r记录的是nums[i]（当遍历到数组最后一个元素时，记录upper+1）
// 然后比较l和r的大小关系，更新结果。
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        int l = lower;
        for (int i = 0; i <= nums.size(); ++i) 
        {
            int r = (i < nums.size() && nums[i] <= upper) ? nums[i] : upper + 1;
            if (l == r) 
                ++l;
            else if (r > l) 
            {
                res.push_back(r - l == 1 ? to_string(l) : to_string(l) + "->" + to_string(r - 1));
                l = r + 1;
            }
        }
        return res;
    }
};