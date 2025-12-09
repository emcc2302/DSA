class Solution {
public:
    long long specialTriplets(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        unordered_map<int,long long> r, l;
        for (int x : nums) r[x]++;

        long long ans = 0;
        for (int j = 0; j < nums.size(); j++) {
            int m = nums[j];
            r[m]--;
            long long n = m * 2;
            ans = (ans + (l[n] * r[n]) % MOD) % MOD;
            l[m]++;
        }
        return ans;
    }
};