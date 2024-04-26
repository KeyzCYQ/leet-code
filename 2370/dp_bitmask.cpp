#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct Test{
    string & s;
    int k;
    Test(string S, int K): s(S), k(K){};
};

class Solution {
public:

    int longestIdealString(string s, int k) {
        int n = s.length();
        vector<int> dp(26, 0);

        for (int i = 0; i < n; i++){
            int current = s[i] - 'a';
            dp[current] = max(1, *max_element(dp.begin() + max(0, current - k), dp.begin() + min(26, current + k + 1)) + 1);
        }

        return *max_element(dp.begin(), dp.end());
    }
};

int main(){
    Test t = Test("eduktdb", 15);
    cout<<Solution().longestIdealString(t.s, t.k);
}