/*There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:

Input: 2, [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0. So it is possible.

Example 2:

Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.

Note:

    The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
    You may assume that there are no duplicate edges in the input prerequisites.

 Hints:

    This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
    Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
    Topological sort could also be done via BFS.
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {

    }
};

// 课程表  [M]
// BFS + 队列 ; DFS + visit数组

// Reference solution:
// #1 BFS
// 定义二维数组graph来表示这个有向图，一维数组in来表示每个顶点的入度。首先根据输入来建立这个有向图，并将入度数组初始化。然后我们使用一个队列，
// 将所有入度为0的点放入队列中，然后开始遍历队列，从graph里遍历其连接的点，每到达一个新节点，将其入度减一，如果此时该点入度为0，则放入队列末尾。
// 直到遍历完队列中所有的值，若此时还有节点的入度不为0，则说明环存在，返回false，反之则返回true。
//
// 步骤：
// (1) 根据prerequisites建立邻接矩阵graph和度数数组in，入度为0的点入队
// (2) 遍历队列，从graph里遍历其连接的点，每到达一个新节点，将其入度减一，如果此时该点入度为0，则放入队列末尾。
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>(0));
        vector<int> in(numCourses, 0);
        for (auto a : prerequisites)
        {
            graph[a.second].push_back(a.first);
            ++in[a.first];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
            if (in[i] == 0) q.push(i);

        while (!q.empty())
        {
            int t = q.front();
            q.pop();
            for (auto a : graph[t])
            {
                --in[a];
                if (in[a] == 0) q.push(a);
            }
        }

        for (int i = 0; i < numCourses; ++i)
            if (in[i] != 0) return false;

        return true;
    }
};


// #2 DFS
// 步骤：
// (1) 根据prerequisites建立邻接矩阵graph，使用visit数组记录每个课程的访问状态： -1 - conflict, 0 - not visited, 1 - visited and acyclic
// (2) 从第一个门课开始，找其可构成哪门课，暂时将当前课程标记为-1，然后对遍历它接下来的课程，调用DFS递归，如果出现conflict，则返回false，没有冲突的话返回true。
// 遍历完后，如果没有问题，把当前课程的标记记为1（已经访问了且无环）。
 
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int> > graph(numCourses, vector<int>(0));
        vector<int> visit(numCourses, 0);
        for (auto a : prerequisites)
            graph[a.second].push_back(a.first);

        for (int i = 0; i < numCourses; ++i)
            if (!canFinishDFS(graph, visit, i))
                return false;

        return true;
    }

    bool canFinishDFS(cosnt vector<vector<int> > &graph, vector<int> &visit, int i) {
        if (visit[i] == -1)  // -1 : conflict
            return false;
        if (visit[i] == 1)  // 1 : visited and acyclic
            return true;

        visit[i] = -1;  // conflict
        for (auto a : graph[i])
            if (!canFinishDFS(graph, visit, a))
                return false;

        visit[i] = 1;  // visited
        return true;
    }
};
