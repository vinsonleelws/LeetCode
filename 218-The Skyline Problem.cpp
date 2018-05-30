A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A), write a program to output the skyline formed by these buildings collectively (Figure B).
Buildings Skyline Contour

The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.

For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].

Notes:

    The number of buildings in any input list is guaranteed to be in the range [0, 10000].
    The input list is already sorted in ascending order by the left x position Li.
    The output list must be sorted by the x position.
    There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]

// 参考思路：
// 这里用到了multiset数据结构。这里为了区分左右边界，将左边界的高度存为负数，建立左边界和负高度的pair，再建立右边界和高度的pair，存入vector数组中，
// 都存进去了以后，给数组按照左边界排序，这样我们就可以按顺序来处理那些关键的节点了。我们要在multiset中放入一个0，这样在某个没有和其他建筑重叠的右
// 边界上，我们就可以将封闭点存入结果res中。下面我们按顺序遍历这些关键节点，如果遇到高度为负值的pair，说明是左边界，那么将正高度加入multiset中，然
// 后取出此时集合中最高的高度，即最后一个数字，然后看是否跟pre相同，这里的pre是上一个状态的高度，初始化为0，所以第一个左边界的高度绝对不为0，所以肯
// 定会存入结果res中。接下来如果碰到了一个更高的楼的左边界的话，新高度存入multiset的话会排在最后面，那么此时cur取来也跟pre不同，可以将新的左边界点
// 加入结果res。第三个点遇到绿色建筑的左边界点时，由于其高度低于红色的楼，所以cur取出来还是红色楼的高度，跟pre相同，直接跳过。下面遇到红色楼的右边界，
// 此时我们首先将红色楼的高度从multiset中删除，那么此时cur取出的绿色楼的高度就是最高啦，跟pre不同，则可以将红楼的右边界横坐标和绿楼的高度组成pair加到
// 结果res中，这样就成功的找到我们需要的拐点啦，后面都是这样类似的情况。当某个右边界点没有跟任何楼重叠的话，删掉当前的高度，那么multiset中就只剩0了，
// 所以跟当前的右边界横坐标组成pair就是封闭点。

// Reference solution:
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> h, res;
        multiset<int> m;
        int pre = 0, cur = 0;
        for (auto &a : buildings) 
        {
            h.push_back({a[0], -a[2]});
            h.push_back({a[1], a[2]});
        }
        sort(h.begin(), h.end());
        m.insert(0);
        for (auto &a : h) 
        {
            if (a.second < 0) 
                m.insert(-a.second);
            else 
                m.erase(m.find(a.second));
            
            cur = *m.rbegin();
            if (cur != pre) 
            {
                res.push_back({a.first, cur});
                pre = cur;
            }
        }
        return res;
    }
};