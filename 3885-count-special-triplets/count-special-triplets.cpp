class Solution {
public:
    long long specialTriplets(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        unordered_map<int,long long> right, left;
        for (int x : nums) right[x]++;

        long long ans = 0;
        for (int j = 0; j < nums.size(); j++) {
            int mid = nums[j];
            right[mid]--;
            long long need = mid * 2;
            ans = (ans + (left[need] * right[need]) % MOD) % MOD;
            left[mid]++;
        }
        return ans;
    }
};