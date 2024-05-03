//unfinished

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Test{
    string word;
    Test(string & Word): word(Word){};
};

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n = word.size();
        int sum = 0;
        vector<int> dp (n, 0);
        vector<int> letter_counts(2, 0);

        letter_counts[word[0] - 'a'] = 1;
        dp[0] = 1;

        for(int i = 1; i < n; i++){
            int id = word[i] - 'a';
            int a = 1;
            letter_counts[id]++;
            for(int j = 0; j < 2; j++){
                a += (letter_counts[j]+1)/2;
            }
            dp[i] += dp[i-1] + a;
        }

        return dp[n-1];
    }
};

int main(){
    string word = "aab";
    Test t = Test(word);
    cout<<Solution().wonderfulSubstrings(t.word);
}