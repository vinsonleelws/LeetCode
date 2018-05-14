Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Example 1:

Input: [[1,1],[2,2],[3,3]]
Output: 3
Explanation:
^
|
|        o
|     o
|  o  
+------------->
0  1  2  3  4

Example 2:

Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
Explanation:
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

// Reference solution:
// #1
// 基于斜率的解法：
// 由于通过斜率来判断共线需要用到除法，而用double表示的双精度小数在有的系统里不一定准确，为了更加精确无误的计算共线，我们应当避免除法，从而避免无限不循环小数的出现，
// 那么怎么办呢，我们把除数和被除数都保存下来，不做除法，但是我们要让这两数分别除以它们的最大公约数，这样例如8和4，4和2，2和1，这三组商相同的数就都会存到一个映射里面，
// 同样也能实现我们的目标，而求GCD的函数如果用递归来写那么一行就搞定了，这个方法能很好的避免除法的出现，牺牲空间来保证精度~
// 需要考虑的特殊情况：
// (1) 斜率为无穷大（分母为0）的情况：
// (2) 两点重合的情况：对于每个点，用一个变量duplicate来记录重合点的个数。
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int res = 0;
        for (int i = 0; i < points.size(); ++i) 
        {
            map<pair<int, int>, int> m;
            int duplicate = 1;
            for (int j = i + 1; j < points.size(); ++j) 
            {
                if (points[i].x == points[j].x && points[i].y == points[j].y) 
                {
                    ++duplicate; 
                    continue;
                } 
                int dx = points[j].x - points[i].x;
                int dy = points[j].y - points[i].y;
                int d = gcd(dx, dy);
                ++m[{dx / d, dy / d}];
            }
            res = max(res, duplicate);
            
            for (auto it = m.begin(); it != m.end(); ++it) 
                res = max(res, it->second + duplicate);
            
        }
        return res;
    }
    
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }
};

// #2
// O(n3)的解法之所以能通过OJ，可能还有一个原因就是用了比较高效的判断三点共线的方法。一般来说判断三点共线有三种方法，斜率法，周长法，面积法(参见帖子: http://yiminghe.iteye.com/blog/568666)。
// 而其中通过判断叉积为零的面积法是坠好的。比如说有三个点A(x1, y1)、B(x2, y2)、C(x3, y3)，那么判断三点共线就是判断下面这个等式是否成立：
// |x1 y1 1|
// |x2 y2 1| = 0
// |x3 y3 1|
// 即上面的行列式为0
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int res = 0;
        for (int i = 0; i < points.size(); ++i) {
            int duplicate = 1;
            for (int j = i + 1; j < points.size(); ++j) {
                int cnt = 0;
                long long x1 = points[i].x, y1 = points[i].y;
                long long x2 = points[j].x, y2 = points[j].y;
                if (x1 == x2 && y1 == y2) {++duplicate; continue;}
                for (int k = 0; k < points.size(); ++k) {
                    int x3 = points[k].x, y3 = points[k].y;
                    if (x1 * y2 + x2 * y3 + x3 * y1 - x3 * y2 - x2 * y1 - x1 * y3 == 0) {
                        ++cnt;
                    }
                }
                res = max(res, cnt);
            }
            res = max(res, duplicate);
        }
        return res;
    }
};
