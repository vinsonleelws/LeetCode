/*Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

OJ's undirected graph serialization:

Nodes are labeled uniquely.
We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.

As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

    First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
    Second node is labeled as 1. Connect node 1 to node 2.
    Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.

Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/

*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        
    }
};

// 无向图复制  [M]
// DFS


// DFS
// 使用一个哈希表来记录已知结点 <label, UndirectedGraphNode*>
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<int, UndirectedGraphNode *> umap;
        return cloneGraphDFS(node, umap);
    }
    
    UndirectedGraphNode *cloneGraphDFS(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode *>& umap)
    {
        if(!node)
            return NULL;
        
        if(umap.count(node->label))
            return umap[node->label];
        
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        umap[node->label] = newNode;
        for (int i = 0; i < node->neighbors.size(); ++i) 
            (newNode->neighbors).push_back(cloneGraphDFS(node->neighbors[i], umap));
        
        return newNode;
    }
};