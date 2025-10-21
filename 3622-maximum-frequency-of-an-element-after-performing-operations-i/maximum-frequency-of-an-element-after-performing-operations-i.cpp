class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int mx = *max_element(nums.begin(), nums.end());
        int n = mx + k + 2;
        vector<int> f(n, 0);
        for (int x : nums) f[x]++;

        vector<int> pre(n, 0);
        pre[0] = f[0];
        for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + f[i];

        int ans = 0;
        for (int t = 0; t < n; t++) {
            if (f[t] == 0 && numOperations == 0) continue;
            int l = max(0, t - k), r = min(n - 1, t + k);
            int tot = pre[r] - (l > 0 ? pre[l - 1] : 0);
            int adj = tot - f[t];
            int val = f[t] + min(numOperations, adj);
            ans = max(ans, val);
        }
        return ans;
    }
};