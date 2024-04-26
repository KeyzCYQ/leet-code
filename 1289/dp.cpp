#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Test{
    vector<vector<int>> grid;
    Test(vector<vector<int>> & Grid): grid(Grid){};
};

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        for(int j = 0; j < n; j++) dp[0][j] = grid[0][j];

        for(int i = 1; i < n; i++){
            for (int j = 0; j < n; j++){
                for (int k = 0; k < n; k++){
                    if (j != k){
                        dp[i][j] = min(dp[i][j], dp[i-1][k] + grid[i][j]);
                    }
                }
                
            }
        }

        return *min_element(dp[n-1].begin(), dp[n-1].end());

    }
};

int main(){
    vector<vector<int>> grid = {
        /*
        {1,2,3},
        {4,5,6},
        {10,8,9}
        */
        //{7}
        {2,2,1,2,2},
        {2,2,1,2,2},
        {2,2,1,2,2},
        {2,2,1,2,2},
        {2,2,1,2,2}
    };
    Test t = Test(grid);
    cout<<Solution().minFallingPathSum(t.grid);
}