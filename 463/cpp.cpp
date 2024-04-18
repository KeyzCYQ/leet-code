#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>> & grid, int i, int j, int rows, int cols, int * p, vector<vector<bool>> & visited){
        visited[i][j] = true;
        if (i > 0 && grid[i-1][j]){
            if (!visited[i-1][j]) dfs(grid, i-1, j, rows, cols, &(*p += 3), visited);
            else *p -= 1;
        }
        if (i < rows - 1 && grid[i+1][j]){
            if (!visited[i+1][j]) dfs(grid, i+1, j, rows, cols, &(*p += 3), visited);
            else *p -= 1;
        }
        if (j > 0 && grid[i][j-1]){
            if (!visited[i][j-1]) dfs(grid, i, j-1, rows, cols, &(*p += 3), visited);
            else *p -= 1;
        }
        if (j < cols - 1 && grid[i][j+1]){
            if (!visited[i][j+1]) dfs(grid, i, j+1, rows, cols, &(*p += 3), visited);
            else *p -= 1;
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int p = 0;
        bool done = false;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for(int i = 0; i < rows && !done; i++){
            for(int j = 0; j< cols && !done ; j++){
                if (grid[i][j] == 1){
                    p += 4;
                    dfs(grid, i, j, rows, cols, &p, visited);
                    done = true;
                }
            }
        }
        return p;
    }
};

int main(){
    vector<vector<int>> test = {
        {0,1,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {1,1,0,0}
    };
    Solution().islandPerimeter(test);
}