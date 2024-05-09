class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        int n = happiness.size();

        sort(happiness.begin(), happiness.end());

        for(int i = 0; i < k; i++){
            if (happiness[n-1-i] - i >= 0)
            ans += happiness[n-1-i] - i;
        }

        return ans;
    }
};