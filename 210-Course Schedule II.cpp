/*There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished
             course 0. So the correct course order is [0,1] .

Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .

Note:

    The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
    You may assume that there are no duplicate edges in the input prerequisites.

Hints:

    This problem is equivalent to finding the topological order in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
    Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
    Topological sort could also be done via BFS.*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {

    }
};

// 课程表II
// BFS / DFS

// 这道题是"207-Course Schedule"的延伸，要求我们若发现时有环图则返回空数组，若能修完所有可能则返回修课序列。

// #1 BFS
// 可直接从"207-Course Schedule"中扩展：
// 只需将每次从queue中出队的元素加入到结果数组中。最终若有向图中有环，则结果中元素的个数不等于总课程数，那我们将结果清空即可。
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        vector<vector<int> > graph(numCourses, vector<int>(0));
        vector<int> in(numCourses, 0);
        for (auto &a : prerequisites)
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
            res.push_back(t);  // 相比"207-Course Schedule"，增加的一句
            q.pop();
            for (auto &a : graph[t])
            {
                --in[a];
                if (in[a] == 0) q.push(a);
            }
        }
        if (res.size() != numCourses)
            res.clear();
        return res;
    }
};

// #2 DFS
// 首先根据输入构建有向图，同时建立一个一维数组visit，表示某个结点的访问状态：0 - 代表初始态，1 - 代表已访问，若再访问则有冲突，2 - 代表已访问且无冲突。
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector <vector<int>> graph(numCourses, vector <int>());
        vector<int> visit(numCourses, 0);
        vector<int> result;

        //construct graph
        for (auto& x : prerequisites)
            graph[x.first].push_back(x.second);  // 先遍历的后加入result，因此是graph[x.first].push_back(x.second)而不是graph[x.second].push_back(x.first)

        for (int i = 0; i < numCourses; ++i)
            if (visit[i] != 2 && !dfs(i, graph, visit, result))
                return {};

        return result;
    }

    bool dfs(int i, vector<vector<int>>& graph, vector<int>& visit, vector<int>& result ) {
        visit[i] = 1;
        for (auto child : graph[i])
        {
            if (visit[child] == 0)
            {
                if (!dfs(child, graph, visit, result))
                    return false;
            }
            if (visit[child] == 1)
                return false;
        }
        result.push_back(i);
        visit[i] = 2;
        return true;
    }
};


// Corner cases:
// Input: 1
//        []
// Expected: [0]

// Input: 2
//        []
// Expected: [1,0]

// Input: 3
// [[1,0]]
// Expected: [2,0,1]