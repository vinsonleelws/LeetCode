Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area

Example:

Input: -3, 0, 3, 4, 0, -1, 9, 2
Output: 45

Note:
Assume that the total area is never beyond the maximum possible value of int.

// 把两个矩形的八个顶点分别投影到x轴和y轴上，两个矩形相交的条件就是既在x轴上的投影有交集，又在y轴上的投影有交集。

// Reference solution:
// 首先找出所有的不相交的情况，只有四种，一个矩形在另一个的上下左右四个位置不重叠，这四种情况下返回两个矩形面积之和。
// 其他所有情况下两个矩形是有交集的，这时候我们只要算出相交部分的长和宽，即可求出交集区域的大小，然后从两个矩形面积之
// 和中减去交集面积就是最终答案。关键在求交集区域的长和宽，由于交集都是在中间，所以左端点是两个矩形左顶点横坐标的较大
// 值，右端点是两个矩形右顶点的较小值，同理，下端点是两个矩形下顶点纵坐标的较大值，上端点是两个矩形上顶点纵坐标的较小值。
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int sum = (C - A) * (D - B) + (H - F) * (G - E);
        if (E >= C || F >= D || B >= H || A >= G) 
            return sum;
        return sum - ((min(G, C) - max(A, E)) * (min(D, H) - max(B, F)));
    }
};
