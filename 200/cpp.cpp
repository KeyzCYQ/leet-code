#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Solution {
public:
    bool isLand(char c){
        if (c != '0') return true;
        else return false;
    }

    bool isUpIsolated(vector<vector<char>> & grid, int i, int j){
        if ((i > 0 && !isLand(grid[i-1][j])) || i == 0) return true;
        else return false;
    }

    bool isLeftIsolated(vector<vector<char>> & grid, int i, int j){
        if ((j > 0 && !isLand(grid[i][j-1])) || j == 0) return true;
        else return false;
    }

    void infectLeft(vector<vector<char>> & grid, int i, int j){
        for (int k = j-1; k >= 0 && isLand(grid[i][k]); k--)
            grid[i][k] = grid[i][j];
    }

    list<char> &getTeam(list<list<char>> & teams, char v){
        for (list<char> &team: teams){
            for(char id: team){
                if (id == v) return team;
            }
        }

        static list<char> empty;

        return empty;
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        int id = 0;
        list<list<char>> teams;

        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if (isLand(grid[i][j])){
                    bool assigned = false;
                    if ((i == 0 && j == 0) || (isUpIsolated(grid, i, j) && isLeftIsolated(grid, i ,j))){
                        count++;
                        id++;
                        list<char> new_team;
                        new_team.push_back('0' + id);
                        teams.push_back(new_team);
                        grid[i][j] = char('0' + id);
                    }
                    if (!assigned && !isLeftIsolated(grid, i, j)) {
                        grid[i][j] = grid[i][j-1];
                        assigned = true;
                    }
                    if (!assigned && !isUpIsolated(grid, i, j)){
                        grid[i][j] = grid[i-1][j];
                        assigned = true;
                    }
                    if (!isUpIsolated(grid, i, j) && grid[i][j] != grid[i-1][j] && grid[i-1][j] != grid[i-1][j-1]) {
                        list<char> & team1 = getTeam(teams, grid[i][j]);
                        list<char> & team2 = getTeam(teams, grid[i-1][j]);

                        if (team1 != team2){
                            count--;
                            for(char v: team2){
                                team1.push_back(v);
                            }
                            teams.erase(find(teams.begin(), teams.end(), team2));
                        }
                    }
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