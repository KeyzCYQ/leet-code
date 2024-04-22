#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

struct Test{
    vector<string> & deadends;
    string target;
    Test(vector<string> & Deadends, string Target) : deadends(Deadends), target(Target){};
};

class Solution {
public:
    string turnWheel (string current, int pos, int dir){
        string new_s = current;

        int wheel = new_s[pos] - '0' + 10;
        wheel = (wheel + dir)%10;
        new_s[pos] = char(wheel + '0');

        return new_s;
    }

    bool isDead(vector<string> & deadends, string & s){
        for (string dead: deadends){
            if (s == dead) return true;
        }

        return false;
    }

    int openLock(vector<string>& deadends, string & target) {
        string current;
        int current_depth;;
        queue<string> q;
        queue<int> q_depth;
        unordered_map<string, bool> visited;
        q.push(target);
        q_depth.push(0);

        while (!q.empty()){
            current = q.front();
            current_depth = q_depth.front();
            if (current == "0000") return current_depth;
            q.pop();
            q_depth.pop();
            for(int pos = 0; pos < 4; pos++){
                visited[current] = true;
                for (int dir = 1; dir > -2; dir -= 2){
                    string new_current = turnWheel(current, pos, dir);
                    if (!visited[new_current]){
                        visited[new_current] = true;
                        if (!isDead(deadends, new_current)){
                            q.push(new_current);
                            q_depth.push(current_depth+1);
                        }
                    }
                }
            }
        }


        return -1;
    }
};

int main(){
    vector<string> deadends = {"0201","0101","0102","1212","2002"};
    string target = "0202";
    Test t = Test(deadends, target);
    cout<<Solution().openLock(t.deadends, t.target);

}