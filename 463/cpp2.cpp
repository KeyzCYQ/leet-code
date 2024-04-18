#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int p = 0;
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if (grid[i][j]){
                    p += 4;
                    if (i > 0 && grid[i-1][j]) p -= 2;
                    if (j > 0 && grid[i][j-1]) p -= 2;
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
    cout<<Solution().islandPerimeter(test);
}