class Solution {
public:
    int XOR(vector<int>&nums, vector<int> & copy, int i, int n){
        int XORed = 0;
        for(int num: copy){
            if (XORed == 0) XORed = num;
            else XORed = XORed ^ num;
        }

        for(int j = i+1; j < n; j++){
            copy.push_back(nums[j]);
            XORed += XOR(nums, copy, j, n);
            copy.pop_back();
        }

        return XORed;
    }

    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<int> copy;

        for(int i = 0; i < n; i++){
            copy.push_back(nums[i]);
            ans += XOR(nums, copy, i, n);
            copy.pop_back();
        }

        return ans;
    }
};