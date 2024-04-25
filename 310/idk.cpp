#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Test{
    int n;
    vector<vector<int>> edges;
    Test(int N, vector<vector<int>> & Edges) : n(N), edges(Edges){};
};

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0}; // Edge case when there's only one node
        
        // Build adjacency list
        unordered_map<int, vector<int>> graph;
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        // Initialize a queue with leaves
        queue<int> leaves;
        for (auto& [node, neighbors] : graph) {
            if (neighbors.size() == 1) {
                leaves.push(node);
            }
        }
        
        // Iterate until there are <= 2 nodes left
        while (n > 2) {
            int numLeaves = leaves.size();
            n -= numLeaves;
            
            for (int i = 0; i < numLeaves; ++i) {
                int leaf = leaves.front();
                leaves.pop();
                
                int neighbor = graph[leaf][0];
                graph[neighbor].erase(remove(graph[neighbor].begin(), graph[neighbor].end(), leaf), graph[neighbor].end());
                
                if (graph[neighbor].size() == 1) {
                    leaves.push(neighbor);
                }
            }
        }
        
        // Add remaining nodes to result
        vector<int> result;
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }
        
        return result;
    }
};

int main(){
    int n = 10;
    vector<vector<int>> edges = {
        //{1,0},{1,2},{1,3}

        //{3,0},{3,1},{3,2},{3,4},{5,4}
        {0,1},{1,2},{2,3},{3,4},{4,5},{5,6},{2,7},{3,9},{4,8}
        };
    Test t = Test(n, edges);
    vector<int> sol = Solution().findMinHeightTrees(t.n,t.edges);
    for (auto edge : sol)
        cout<<edge;
}