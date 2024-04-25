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
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n, vector<int>());
        vector<int> sol;
        queue<pair<int, int>> q;
        int min_h = INT_MAX - 1;

        for(vector<int> edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; i++){
            if (graph[i].size() > 1){
                pair<int,int> p = make_pair(i,1);
                q.push(p);

                int h_reached = 1;
                vector<bool> visited(n, false);
                visited[i] = true;

                if (edges.size() < 2){
                    for (int i = 0; i < n; i++){
                        sol.push_back(i);
                    }
                }

                while (!q.empty()){
                    int current = q.front().first;
                    int h = q.front().second;
                    h_reached = max(h_reached, h);

                    q.pop();

                    for(int neighbor : graph[current]){
                        if (graph[current].size() > 1 && (h == min_h + 1 || h == n/2)) {
                            while (!q.empty()) q.pop();
                            h_reached = INT_MAX;
                        }
                        if (h < min_h + 1 && !visited[neighbor]){
                            visited[neighbor] = true;
                            p = make_pair(neighbor, h + 1);
                            q.push(p);
                        }
                    }
                }

                if (h_reached < min_h){
                    min_h = h_reached;
                    sol.clear();
                }
                if (h_reached == min_h) sol.push_back(i);
            }
        }

        return sol;
    }
};

int main(){
    int n = 7;
    vector<vector<int>> edges = {{0,1},{1,2},{2,4},{4,6},{1,3},{3,5}};
    Test t = Test(n, edges);
    vector<int> sol = Solution().findMinHeightTrees(t.n,t.edges);
    for (auto edge : sol)
        cout<<edge;
}