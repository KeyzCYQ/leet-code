#include <iostream>

using namespace std;

class Solution {
public:

    void dfs(vector<vector<char>> & grid, vector<vector<bool>> & visited, int i, int j, int rows, int cols){
        visited[i][j] = true;
        if (i < rows-1 && grid[i+1][j] == '1' && !visited[i+1][j]) dfs(grid, visited, i+1, j, rows, cols);
        if (j < cols-1 && grid[i][j+1] == '1' && !visited[i][j+1]) dfs(grid, visited, i, j+1, rows, cols);
        if (i > 0 && grid[i-1][j] == '1' && !visited[i-1][j]) dfs(grid, visited, i-1, j, rows, cols);
        if (j > 0 && grid[i][j-1] == '1' && !visited[i][j-1]) dfs(grid, visited, i, j-1, rows, cols);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if (grid[i][j] == '1' && !visited[i][j]){
                    count++;
                    dfs(grid, visited, i, j, rows, cols);
                }
            }
        }


        return count;
    }
};

int main(){
    vector<vector<char>> test = {
        /*{'1','0','0','0','1'},
        {'1','1','0','1','1'},
        {'1','0','1','0','1'},
        {'1','1','1','1','1'}*/
        
        /*{'1','1','1','1','1','1','1'},
        {'0','1','0','1','0','1','1'},
        {'0','1','0','0','1','1','1'},
        {'1','1','1','1','1','1','1'}*/

        {'1','1','1','1','1','0','1','1','1','1'},
        {'0','1','1','0','1','1','1','0','1','1'},
        {'1','0','1','0','1','1','0','1','0','1'},
        {'1','0','1','1','0','1','1','1','1','1'},
        {'1','1','0','0','1','1','1','1','1','1'},
        {'1','1','0','1','1','1','1','1','1','1'},
        {'1','1','1','1','1','1','1','1','0','1'},
        {'0','1','1','0','1','1','1','1','1','0'},
        {'1','1','0','1','1','0','1','1','1','1'},
        {'0','1','1','1','1','1','0','1','1','1'}
    };

    cout<<Solution().numIslands(test)<<endl;
}