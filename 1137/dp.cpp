#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Test{
    int n;
    Test(int N): n(N){};
};

class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp (max(n + 1, 3), 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        for(int i = 3; i < n + 1; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }

        return dp[n];
    }
};

int main(){
    Test t = Test(25);
    cout<<Solution().tribonacci(t.n);
}