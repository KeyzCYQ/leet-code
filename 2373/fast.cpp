class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans (n-2, vector<int>(n-2, 0));

        for(int i = 0; i < n-2; i++){
            for(int j = 0; j < n-2; j++){
                for(int i2 = i; i2 < i+3; i2++){
                    for(int j2 = j; j2 < j+3; j2++){
                       ans[i][j] = max(ans[i][j], grid[i2][j2]);
                    }
                }
            }
        }

        return ans;
    }
};