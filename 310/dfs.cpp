//time limit exceeded

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
    int dfs(vector<vector<int>> & graph, vector<bool> & visited, int i, int h, int * min_h, int n){
        int current_h = h;

        if (h >= *min_h || h > n/2) return INT_MAX;

        for (int neighbor: graph[i]){
            if (!visited[neighbor]){
                visited[neighbor] = true;
                current_h = max(current_h, dfs(graph, visited, neighbor, h, min_h, n));
                if (current_h == INT_MAX) return current_h;
            }
        }

        return current_h + 1;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n, vector<int>());
        vector<int> order_graph;
        vector<int> sol;
        int min_h = INT_MAX - 1;

        for(vector<int> edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; i++){
            vector<bool> visited(n, false);
            visited[i] = true;
            int h = dfs(graph, visited, i, 0, &min_h, n);
            if (h < min_h) {
                sol.clear();
                min_h = h;
            }
            if (h == min_h) sol.push_back(i);
        }

        return sol;
    }
};

int main(){
    int n = 4;
    vector<vector<int>> edges = {{1,0},{1,2},{1,3}};
    Test t = Test(n, edges);
    vector<int> sol = Solution().findMinHeightTrees(t.n,t.edges);
    for (auto edge : sol)
        cout<<edge;
}