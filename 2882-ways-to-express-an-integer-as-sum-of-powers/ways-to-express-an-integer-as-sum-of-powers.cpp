class Solution {
public:
    const int MOD = 1e9 + 7;
    int solve(const vector<int> &p, int t, int i, vector<vector<int>> &dp) {
        if (t == 0) return 1;
        if (i >= p.size() || t < 0) return 0;
        if (dp[t][i] != -1) return dp[t][i];
        int res = solve(p, t, i + 1, dp);
        if (p[i] <= t) res = (res + solve(p, t - p[i], i + 1, dp)) % MOD;
        return dp[t][i] = res;
    }
    int numberOfWays(int n, int x) {
        vector<int> p;
        for (int i = 1;; i++) {
            long long v = 1;
            for (int j = 0; j < x; j++) v *= i;
            if (v > n) break;
            p.push_back((int)v);
        }
        vector<vector<int>> dp(n + 1, vector<int>(p.size(), -1));
        return solve(p, n, 0, dp);
    }
};