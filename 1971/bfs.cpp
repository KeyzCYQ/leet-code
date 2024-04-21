#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Test
{
    int n;
    vector<vector<int>> edges;
    int source;
    int destination;
    Test(int N, vector<vector<int>> & Edges, int Source, int Destination) : n{N}, edges(Edges), source(Source), destination(Destination) {};
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n, vector<int>());
        queue<int> q;
        vector<bool> visited(n, false);

        for (vector<int> & edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        q.push(source);

        while(!q.empty()){
            int current = q.front();
            if (current == destination) return true;
            q.pop();
            for (int neighbor : graph[current]){
                if (!visited[neighbor]){
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return false;
    }
};

int main(){
    vector<vector<int>> edges = {
            {0,1},
    };
    Test t(
        3,
        edges,
        0,
        2
    );
    cout<<Solution().validPath(t.n, t.edges, t.source, t.destination);
}